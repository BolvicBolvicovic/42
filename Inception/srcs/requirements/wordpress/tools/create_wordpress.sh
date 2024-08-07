while ! nc -z mariadb 3306; do
	sleep 0.1
done

if [ -f ./wp-config.php ]
then
	echo "wordpress already downloaded"
else
	wget http://wordpress.org/latest.tar.gz
	tar xfz latest.tar.gz
	mv wordpress/* .
	rm -rf latest.tar.gz
	rm -rf wordpress

	sed -i "s/username_here/$MYSQL_USER/g" wp-config-sample.php
	sed -i "s/password_here/$MYSQL_PASSWORD/g" wp-config-sample.php
	sed -i "s/localhost/$MYSQL_HOSTNAME/g" wp-config-sample.php
	sed -i "s/database_name_here/$MYSQL_DATABASE/g" wp-config-sample.php
	cp wp-config-sample.php wp-config.php
	
	wp core download --allow-root

	wp core install \
		--allow-root \
		--url=$DOMAIN_NAME \
		--title=$WP_TITLE \
		--admin_user=$WP_ADMIN_LOGIN \
		--admin_password=$WP_ADMIN_PASSWORD \
		--admin_email=$WP_ADMIN_EMAIL
	wp user create \
		--allow-root \
		$WP_USER_LOGIN \
		$WP_USER_EMAIL \
		--user_pass=$WP_USER_PASSWORD

fi

exec "$@"
