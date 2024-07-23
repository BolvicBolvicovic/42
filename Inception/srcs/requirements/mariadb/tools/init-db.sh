#!/bin/sh

echo "Installing database..."


echo "Starting temp server"
/usr/bin/mysqld --user=mysql &
MARIADB_PID=$?


echo "Mariadb is starting..."
mariadb-check -A
STATUS=$?
while [[ $STATUS -ne 0 ]]
do
	mariadb-check -A
	STATUS=$?
	sleep 1
done

echo "Creating user and database"
mariadb << EOF
CREATE USER $MYSQL_USER@'%' IDENTIFIED BY "$MYSQL_PASSWORD";
CREATE DATABASE $MYSQL_DATABASE;
GRANT ALL PRIVILEGES on $MYSQL_DATABASE.* to $MYSQL_USER@'%';
FLUSH PRIVILEGES;
SELECT User,Host FROM mysql.user;
EOF


echo "Stoping temp server"
kill $MARIADB_PID
wait $MARIADB_PID

echo "Installation complete"

exit 0
