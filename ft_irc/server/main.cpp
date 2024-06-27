#include "lib.hpp"

int	main(int argc, char **argv) {
	if (argc != 3) {
		std::cerr << "USAGE: ./ircserv <PORT> <PASSWORD>" << std::endl;
		return 1;
	}
	if (atoi(argv[1]) < 1 || atoi(argv[1]) > 65535) {
		std::cerr << "Panic: Port out of bound" << std::endl;
		return 1;
	}
	Server server = Server(atoi(argv[1]), argv[2]);
	std::cout << "-----SERVER-----" << std::endl;
	try {
		signal(SIGINT, Server::signalHandler);
		signal(SIGQUIT, Server::signalHandler);
		server.serverInit();
	} catch (const std::exception &e) {
		server.closeFds();
		std::cerr << e.what() << std::endl;
		return 1;
	}
	std::cout << "Server closed" << std::endl;
	return 0;
}
