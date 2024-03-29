FROM		alpine:3.18

RUN			apk update && apk upgrade && apk add		\
				wget									\
				php7.4 php-fpm php-mysql				\
				mariadb	mariadb-client					\
				vim									

RUN			wget https://fr.wordpress.org/wordpress-6.0-fr_FR.tar.gz -P /var/www
RUN			cd /var/www && tar -xvf wordpress-6.0-fr_FR.tar.gz && rm wordpress-6.0-fr_FR.tar.gz
RUN			chown -R root:root /var/www/wordpress

COPY		./conf/www.config /etc/php/7.4/fpm/pool.d
COPY		./conf/auto_config.sh ./conf auto_config.sh
RUN			chmod +x ./conf/auto_config.sh

RUN			wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar

RUN			chmod +x wp-cli.phar
RUN			mv wp-cli.phar /usr/local/bin/wp

EXPOSE		9000

ENTRYPOINT	["./conf/auto_config.sh"]

CMD         ["/usr/sbin/php-fpm7.4", "--nodaemonize"]
