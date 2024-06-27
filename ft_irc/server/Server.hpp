/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:01:45 by acasamit          #+#    #+#             */
/*   Updated: 2024/04/05 22:38:31 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "lib.hpp"
#include <vector>
#include <cstring>
#include <cerrno>
#include <string>
#include <sstream>

class Server {
private:
	int					port;
	int							serverSocketFd;
	static bool					signal;
	std::string			password;
	std::vector<Client>			clients;
	std::vector<Channel>		channels;
	std::vector<struct pollfd>	fds;
public:
								Server(const int port, const std::string password);
								~Server();
	void						serverInit();
	void						accepteNewClient();
	int						receiveNewData(	const int fd	);
	Client& 					getClient(int fd, std::vector<Client>& clients);
	Channel&					getChannel(std::string name, std::vector<Channel>& channels);

	static void					signalHandler(	const int signum);

	void						closeFds();
	void						clearClients(	const int fd	);

	void						Cap(int fd);
	void						Nick(std::string message, int fd);
	void						User(std::string message, int fd);
	void						Pong(std::string message, int fd);
	void						Mode(std::string message, int fd);
	void						Join(std::string message, int fd);
	void						Privmsg(std::string message, int fd);
	void						Topic(std::string message, int fd);
	void						Pass(std::string message, int fd);
	void						Invite(std::string message, int fd);
	void						Quit(std::string message, int fd);
	void						Kick(std::string message, int fd);
	void						Part(std::string message, int fd);

	Channel						error_chan;
	Client						error;
};
