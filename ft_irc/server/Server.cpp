#include "lib.hpp"

std::vector<std::string> splitCommands(const std::string &s) {
	std::vector<std::string> commands;
	std::istringstream iss(s);
	std::string command;
	
	while (std::getline(iss, command, '\n')) {
		if (!command.empty() && command[command.size() - 1] == '\r') {
			command.erase(command.size() - 1);
		}
		if (!command.empty()) {
			commands.push_back(command);
		}
	}
	return commands;
}

bool		Server::signal = false;
Server::Server(const int port, const std::string password): port(port), password(password)	{
}

Server::~Server() {}

void		Server::serverInit() {
	struct	sockaddr_in addr;
	struct	pollfd		newPoll;

	error_chan.error = true;
	error.setFd(-1);
	addr.sin_family 		= AF_INET;							// set ipv4
	addr.sin_port			= htons(this->port);
	addr.sin_addr.s_addr	= INADDR_ANY;						// set to any local machine

	this->serverSocketFd	= socket(AF_INET, SOCK_STREAM, 0);
	if (this->serverSocketFd == -1) {
		throw std::runtime_error("Panic: failed to create socket");
	}

	int	en 			= 1;
	int	set_socket	= setsockopt(this->serverSocketFd, SOL_SOCKET, SO_REUSEADDR, &en, sizeof(en));
	if (set_socket == -1) {
		throw std::runtime_error("Panic: failed to set option (SO_REUSEADDR) on socket");
	}
	set_socket		= fcntl(this->serverSocketFd, F_SETFL, O_NONBLOCK);
	if (set_socket == -1) {
		throw std::runtime_error("Panic: failed to set option (O_NONBLOCK) on socket");
	}
	set_socket		= bind(this->serverSocketFd, (struct sockaddr *)&addr, sizeof(addr));
	if (set_socket == -1) {
		throw std::runtime_error("Panic: failed to bind socket");
	}
	set_socket		= listen(serverSocketFd, SOMAXCONN);
	if (set_socket == -1) {
		throw std::runtime_error("Panic: listen() function failed");
	}

	newPoll.fd		= this->serverSocketFd;
	newPoll.events	= POLLIN;
	newPoll.revents	= 0;
	this->fds.push_back(newPoll);
	std::cout << GRE << "Server <" << this->serverSocketFd << "> Connected" << WHI << std::endl;
	std::cout << "Waiting to accept a connection...\n";
	while (signal == false) {

		int pollResult = poll(&this->fds[0], this->fds.size(), -1);
		if (pollResult == -1 || signal == true) 
			break;
		for (size_t i = 0; i < this->fds.size(); i++) {
			if (this->fds[i].revents & POLLIN) {
				if (i == 0) {
					this->accepteNewClient();
				} else {
					if (!this->receiveNewData(this->fds[i].fd)) {
						break;
					}
				}
			}
		}
	}
	this->closeFds();
}

void		Server::accepteNewClient() {
	Client	client;
	struct	sockaddr_in	clientAddr;
	struct	pollfd		newPoll;
	socklen_t	len = sizeof(clientAddr);

	int	incommingFd	= accept(this->serverSocketFd, (sockaddr *)&(clientAddr), &len);
	if (incommingFd == -1) {
		std::cout << "Panic: accept() function failed" << std::endl;
		return;
	}
	int set_socket	= fcntl(incommingFd, F_SETFL, O_NONBLOCK);
	if (set_socket == -1) {
		throw std::runtime_error("Panic: failed to set option (O_NONBLOCK) on socket");
	}
	newPoll.fd		= incommingFd;
	newPoll.events	= POLLIN;
	newPoll.revents	= 0;

	client.setFd(incommingFd);
	client.setIPaddress(inet_ntoa(clientAddr.sin_addr));

	this->clients.push_back(client);
	this->fds.push_back(newPoll);

	std::cout << GRE << "Client <" << incommingFd << "> Connected" << WHI << std::endl;
}

int		Server::receiveNewData(const int fd)
{
	char	buff[512];
	memset(buff, 0, sizeof(buff));
	ssize_t	bytes	= recv(fd, buff, 512, 0);

	std::cout << "New data received" << std::endl;
	if (bytes <= 0) {
		std::cout << RED << "Client <" << fd << "> Disconnected" << WHI << std::endl;
		this->clearClients(fd);
		close(fd);
	} else {
		getClient(fd, clients).message += buff;
		while ((getClient(fd, clients).pos = getClient(fd, clients).message.find("\r\n")) != std::string::npos)
		{
			std::string tmp = getClient(fd, clients).message;
			getClient(fd, clients).message = getClient(fd, clients).message.substr(0, getClient(fd, clients).pos + 2);
			buff[bytes] = '\0';
			//std::string message(buff);
			std::vector<std::string> message_s = splitCommands(getClient(fd, clients).message);
			std::cout << YEL << "Client <" << fd << "> Data: " << WHI << getClient(fd, clients).message;
			for (size_t i = 0; i != message_s.size(); i++)
			{
				if (message_s[i] == "CAP LS")
					Cap(fd);
				if (message_s[i].substr(0, 4) == "PASS")
					Pass(message_s[i], fd);
				if (!getClient(fd, clients).allowed) {
					if (message_s[i] != "CAP LS") {
						Quit("QUIT :bad password", fd);
						return 0;
					}
				}
				if (message_s[i].substr(0, 4) == "NICK")
					Nick(message_s[i], fd);
				if (message_s[i].substr(0, 4) == "USER")
					User(message_s[i], fd);
				if (message_s[i].substr(0, 4) == "PING")
					Pong(message_s[i], fd);
				if (!getClient(fd, clients).full_registred)
					continue;
				if (message_s[i].substr(0, 4) == "MODE")
					Mode(message_s[i], fd);
				if (message_s[i].substr(0, 4) == "JOIN")
					Join(message_s[i], fd);
				if (message_s[i].substr(0, 7) == "PRIVMSG")
					Privmsg(message_s[i], fd);
				if (message_s[i].substr(0, 5) == "TOPIC")
					Topic(message_s[i], fd);
				if (message_s[i].substr(0, 4) == "KICK")
					Kick(message_s[i], fd);
				if (message_s[i].substr(0, 4) == "QUIT") {
					Quit(message_s[i], fd);
					return 0;
				}
				if (message_s[i].substr(0, 4) == "PART")
					Part(message_s[i], fd);
				if (message_s[i].substr(0, 6) == "INVITE")
					Invite(message_s[i], fd);
			}
			getClient(fd, clients).message = tmp.substr(getClient(fd, clients).pos + 2);
		}
	}
	return 1;
}

void		Server::signalHandler(	const int signum) {
	(const void)signum;
	std::cout << std::endl << "Signal Received!" << std::endl;
	signal = true;
}

void		Server::closeFds() {
	for(size_t i = 0; i < this->clients.size(); i++) {
		std::cout << RED << "Client <" << this->clients[i].getFd() << "> Disconnected" << WHI << std::endl;
		close(this->clients[i].getFd());
	}
	if (this->serverSocketFd != -1) {
		std::cout << RED << "Server <" << this->serverSocketFd << "> Disconnected" << WHI << std::endl;
		close(this->serverSocketFd);
	}
}

void		Server::clearClients(	const int fd	) {
	for (size_t i = 0; i < this->fds.size(); i++) {
		if (this->fds[i].fd == fd) {
			this->fds.erase(fds.begin() + i);
			break;
		}
	}
	for (size_t i = 0; i < this->clients.size(); i++) {
		if (this->clients[i].getFd() == fd) {
			this->clients.erase(this->clients.begin() + i);
			break;
		}
	}
}
