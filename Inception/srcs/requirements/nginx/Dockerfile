FROM	debian:bullseye

RUN		apt-get update
RUN		apt-get install -y nginx \
                openssl

RUN mkdir /etc/nginx/ssl
RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
       -out /etc/nginx/ssl/vcornill.crt \
       -keyout /etc/nginx/ssl/vcornill.key \
       -subj "/C=FR/ST=Havre/L=Havre/O=42 School/OU=vcornill/CN=vcornill/"

COPY ./conf/nginx.conf /etc/nginx/conf.d

RUN mkdir -p /run/nginx

RUN			chmod 755 /var/www/html
RUN			chown -R www-data:www-data /var/www/html

EXPOSE	443

CMD ["nginx", "-g", "daemon off;"]
