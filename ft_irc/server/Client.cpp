#include "lib.hpp"

			Client::Client() : _nickname(""), allowed(false), registred(false), full_registred(false), username(""), ip(""), unfinished_registration("null"), message(""), pos(0) { mode.push_back('\0'); }
			Client::~Client() {}

int			Client::getFd() {
	return this->fd;
}

void		Client::setFd(const int fd) {
	this->fd = fd;
}

void		Client::setIPaddress(const char *ipaddr) {
	std::string str(ipaddr);
	this->IPaddress = str;
}

void Client::setNick(std::string nick) { _nickname = nick; }

std::string Client::getNick() const { return _nickname; }
