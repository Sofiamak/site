FROM ubuntu:18.04 as builder

# Install.
RUN apt-get update

RUN  apt-get install -y \
    bash \
    make \
    gcc \
    g++ \
    mariadb-server \
    mariadb-client \
    libmysqlclient-dev \
    unzip \ 
    curl \ 
    ca-certificates \ 
    libleveldb-dev \ 
    sqlite3 \ 
    libsqlite3-dev

RUN apt-get install -y nginx    

RUN apt-get update    

WORKDIR /build

COPY . .

RUN find /usr/ -name 'mysql.h'

RUN make create

WORKDIR /

# # install nginx
RUN apt-get update -y

RUN  rm -f etc/nginx/nginx.conf
# # add nginx conf
ADD  nginx/nginx.conf  /etc/nginx/nginx.conf

RUN echo "\ndaemon off;" >> /etc/nginx/nginx.conf
RUN chown -R www-data:www-data /var/lib/nginx

# volume
VOLUME ["/etc/nginx/sites-enabled", "/etc/nginx/certs", "/var/log/nginx"]

# expose ports
EXPOSE 80 443

WORKDIR /etc/nginx

CMD ["nginx"]

WORKDIR /

RUN mkdir prod
COPY --from=builder   /build/main   /prod/main
COPY --from=builder   /build/web    /prod/web

RUN  rm -rf build

WORKDIR /prod











