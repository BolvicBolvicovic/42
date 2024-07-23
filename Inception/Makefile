all		:
	docker compose -f ./srcs/docker-compose.yml up -d --build

stop	:
	docker-compose -f ./srcs/docker-compose.yml stop

clean	:
	docker-compose -f ./srcs/docker-compose.yml down -v

fclean	: clean
	docker system prune -af

re		: fclean all

.PHONY	: all stop clean fclean re
