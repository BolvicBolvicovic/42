#!/bin/bash

# set -x Bash print each command that it executes to the terminal, preceded by a + sign.
# set -e Bash exit with an error if any command in the script fails.


# start of the script

echo "Welcome to your Encrypton, sir."

generator()
{
	lenght=$1
	upper='ABCDEFGHIJKLMNOPQRSTUVWXYZ'
	lower='abcdefghijklmnopqrstuvwxyz'
	numbers='0123456789'
	symbols='!@#$%^&*()-=_+[]{}|;:,.<>?'
	all_chars="$upper$lower$numbers$symbols"
	password=$(head -c $lenght /dev/urandom | base64 | tr -dc "$all_chars | head -c $lenght")
	echo "Generated Password: $password"
}

read -p "Enter password size: " password_lenght

if [[ $password_length =~ ^[1-9][0-9]*$ ]]; then
	generate_password $password_length
else
	echo "Please enter a valid positive integer for the password length."
fi
# end of the script

if [ $? -ne 0 ]; then
	echo "ERROR"
fi
