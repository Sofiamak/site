all: restart

create: main.cpp
	g++ -c main.cpp  -o bin/main.o
	g++ -o main  bin/main.o  -I.. -lpthread  `mysql_config --libs`

clean:
	rm -rf bin/*.o create
	rm -rf main
	rm -rf mtest

run: create
	./main

restart: clean  run

##################PARAM########################
################################################
IMAGE_WEB=site
IMAGE_DATABASE= mysql/mysql-server:5.7

TAG_BD=mysql
TAG_WEB=web

DEV_DATABASE_PASS=pass
DEV_DATABASE_NAME=web
DEV_DATABASE_USER=user


#####################IMAGES#########################
image_web:
	docker build -f docker/Dockerfile.web -t $(IMAGE_WEB) .

image_db:
	docker build -f docker/Dockerfile.mysql -t $(IMAGE_DATABASE) .




###################################################
####################MYSQL##########################
$(TAG_BD)_container : image_db
	docker stop $@ || echo
	@echo
	@echo '========================================================'
	@echo '||          STARTING DATABASE SERVER                  ||'
	@echo '||                                                    ||'
	@echo '|| Run "make mysql-client" to start MySQL CLI         ||'
	@echo '========================================================'
	@echo
	docker run \
		-d \
		--rm \
		--name $@ \
			-e MYSQL_ROOT_PASSWORD=$(DEV_DATABASE_PASS) \
			-e MYSQL_DATABASE=$(DEV_DATABASE_NAME) \
			-e MYSQL_USER=$(DEV_DATABASE_USER)	\
			-e MYSQL_PASSWORD=$(DEV_DATABASE_PASS) \
			-p 3326:3306 \
			$(IMAGE_DATABASE)
			@echo 'Waiting 15s for database to be initialized...'
			@sleep 15
		docker logs $@

mysql_exec:
	docker exec -it mysql_client bash

####################WEB#################################
########################################################
$(TAG_WEB)_container: image_web
	docker stop $@ || echo
	docker run --rm  --name $@  -p 9000:80  -d  $(IMAGE_WEB)
	@sleep 15
	docker exec -it $@ bash ./start.sh