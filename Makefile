all: restart

IMAGE = market
TAG_BD=mysql

DEV_DATABASE_IMAGE = mysql/mysql-server:5.7
DEV_DATABASE_PASS=pass
DEV_DATABASE_NAME=market
DEV_DATABASE_USER=user

create: main.cpp
	g++ -c main.cpp -o bin/main.o
	g++ -o main bin/main.o -I.. -lpthread 

clean:
	rm -rf bin/*.o create
	rm -rf main
	rm -rf mtest

run: create
	./main

restart: clean  run

client_t:
	g++ -c client.cpp -o bin/client.o
	g++ -o client bin/client.o

client_run: client_t
	./client

#docker rmi $(docker images -a -q)
mysql_client_build:
	docker build -t $(DEV_DATABASE_IMAGE) .

mysql_client: mysql_client_build
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
			$(DEV_DATABASE_IMAGE)
			@echo 'Waiting 15s for database to be initialized...'
			@sleep 15
		docker logs $@

mysql_client_stop:
	docker stop mysql_client || echo

#mysql -uroot -p
#show databases;
#show tables;
mysql_exec:
	docker exec -it mysql_client bash