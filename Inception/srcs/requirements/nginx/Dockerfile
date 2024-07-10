FROM		alpine:3.18

RUN			apk update && apk upgrade && apk add		\
				openssl									\
				nginx									\
				curl									\
				vim										\
				sudo


RUN			mkdir -p /etc/nginx/ssl
RUN			openssl req -x509 -nodes 					\
				-out /etc/nginx/ssl/inception.crt 		\
				-keyout /etc/nginx/ssl/inception.key	\
				-subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=login.42.fr/UID=login"

RUN			rm -f /etc/nginx/nginx.conf
RUN			mkdir -p /var/run/nginx


COPY		./conf/nginx.conf /etc/nginx/nginx.conf

RUN			chmod 755 /var/www/html
RUN			chown -R www-data:www-data /var/www/html

EXPOSE		443

CMD			["nginx", "-g", "daemon off;"]