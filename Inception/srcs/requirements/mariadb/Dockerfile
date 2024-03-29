FROM		alpine:3.18

RUN			apk update && apk upgrade && apk add		\
				openssl									\
				mariadb	mariadb-client					\
				curl									\
				vim										

COPY		conf/50-server.cnf			/etc/mysql/mariadb.conf.d/50-server.cnf
COPY		./tools/script_mdb.sh		./script_mdb.sh

CMD			["sh", "./script_mdb.sh"]
