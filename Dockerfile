FROM ubuntu:18.04
RUN apt-get update -q && apt-get -y install apache2
COPY index.html /var/www/html
