/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:40:17 by acasamit          #+#    #+#             */
/*   Updated: 2024/04/05 21:40:16 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.hpp"

std::vector<std::string> split(const std::string &s, char delim)
{
	std::vector<std::string> elems;
	std::istringstream iss(s);
	std::string item;
	while (std::getline(iss, item, delim))
		elems.push_back(item);
	return elems;
}

std::string unsplit(std::vector<std::string>& command, char delim)
{
	std::string message = command[0];
	for (size_t i = 1; i != command.size(); i++)
		message += delim + command[i];
	return message;
}

Client& Server::getClient(int fd, std::vector<Client>& clients)
{
	for (size_t i = 0; i != clients.size(); i++)
	{
		if (clients[i].getFd() == fd)
			return clients[i];
	}
	return error;
}

Channel& Server::getChannel(std::string name, std::vector<Channel>& channels)
{
	if (name[0] != '#')
		name += "#" + name;
	for (size_t i = 0; i != channels.size(); i++)
	{
		if (channels[i].name == name)
			return channels[i];
	}
	return error_chan;
}

int isComma(std::string str)
{
	for (size_t i = 0; i != str.size(); i++)
	{
		if (str[i] != ',' && str[i] != ' ')
			return 0;
	}
	return 1;
}

void	Server::Cap(int fd)
{
	std::string capResponse = ":Feur CAP * LS :\r\n";
	send(fd, capResponse.c_str(), capResponse.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
}

void send_to_all_client(std::string message, std::vector<Client> clients)
{
	for (size_t i = 0; i != clients.size(); i++)
		send(clients[i].getFd(), message.c_str(), message.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
}

std::string to_lower(std::string str) {
	std::string data = str;
	for (size_t i = 0; i < str.length(); i++) {
		data[i] = std::tolower(data[i]);
	}
	return data;
}

void	Server::Nick(std::string message, int fd)
{
	std::vector<std::string> command = split(message, ' ');
	if (command[0] != "NICK")
		return;

	if (command.size() == 1)
	{
		std::string errorMessage = ":Feur 431 * :No nickname given\r\n";
		send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
		return ;
	}

	if (command.size() > 2 || (command[1].find(',') != std::string::npos) || command[1][0] == ':' || command[1][0] == '#')
	{
		std::string errorMessage = ":Feur 432 " + message.substr(5) + " :Erroneous nickname\r\n";
		send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
		return ;
	}

	for (size_t i = 0; i != clients.size(); i++)
	{
		if (to_lower(command[1]) == to_lower(clients[i].getNick()) && fd != clients[i].getFd())
		{
			std::string errorMessage = ":Feur 433 * " + command[1] + " :Nickname is already in use\r\n";
			send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
			return ;
		}
	}

	//std::string Message = ":" + getClient(fd, clients).getNick() + "!~" + getClient(fd, clients).getNick() + "@" + getClient(fd, clients).ip + " NICK " + command[1];
	for (size_t i = 0; i < this->clients.size(); i++)
	{
		if (command[1] != clients[i].getNick() && clients[i].getFd() == fd)
		{
			clients[i].setNick(command[1]);
			if (clients[i].full_registred){
				std::string NickMessage = ":" + clients[i].getNick() + " NICK "+ command[1] + "\r\n";
				send_to_all_client(NickMessage, clients);
			} else if (clients[i].registred) {
				std::string serverName = "Feur";
				std::string welcomeMsg = "";
				welcomeMsg += ":" + serverName + " 001 " + clients[i].username + " :Welcome to the Internet Relay Chat Network, " + clients[i].username + "\r\n";
				welcomeMsg += ":" + serverName + " 002 " + clients[i].username + " :Your host is " + serverName + ", running version 6.9\r\n";
				welcomeMsg += ":" + serverName + " 003 " + clients[i].username + " :This server was created on 11/09/2001\r\n";
				welcomeMsg += ":" + serverName + " 004 " + clients[i].username + " :" + serverName + " 6.9\r\n";
				welcomeMsg += ":Feur 005 * CASEMAPPING=ascii\r\n";
				welcomeMsg += ":Feur 422 * :MOTD File is missing\r\n";
				send(fd, welcomeMsg.c_str(), welcomeMsg.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
				clients[i].full_registred = true;
			}
			if (!clients[i].registred && clients[i].unfinished_registration != "null")
			{
				std::vector<std::string> user_command = split(clients[i].unfinished_registration, ' ');
				user_command[1] = command[1];
				user_command[2] = command[1];
				User(unsplit(user_command, ' '), fd);
			}
			return ;
		}
	}
}

void	Server::User(std::string message, int fd)
{
	std::vector<std::string> command = split(message, ' ');
	if (command[0] != "USER")
		return;

	if (command.size() <= 4 || command[4][0] != ':')
	{
		std::string errorMessage = ":Feur 461 * " + command[1] + " :Not enough parameters\r\n";
		send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
		return ;
	}
	for (size_t i = 0; i < this->clients.size(); i++)
	{
		if (clients[i].getFd() == fd)
		{
			if (clients[i].registred == true)
			{
				std::string errorMessage = ":Feur 462 " + command[1] + " :Unauthorized command (already registered)\r\n";
				send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
				return ;
			}
		}
	}
	for (size_t i = 0; i < this->clients.size(); i++)
	{
		if (clients[i].getFd() == fd)
		{
			clients[i].username = command[1];
			clients[i].ip = command[3];
			std::string serverName = "Feur";
			std::string welcomeMsg = "";
			if (clients[i].getNick() == "")
			{
				clients[i].unfinished_registration = message;
				return ;
			}
			clients[i].registred = true;
			if (!clients[i].getNick().empty()) {
				clients[i].full_registred = true;
				welcomeMsg += ":" + serverName + " 001 " + clients[i].username + " :Welcome to the Internet Relay Chat Network, " + clients[i].username + "\r\n";
				welcomeMsg += ":" + serverName + " 002 " + clients[i].username + " :Your host is " + serverName + ", running version 6.9\r\n";
				welcomeMsg += ":" + serverName + " 003 " + clients[i].username + " :This server was created on 11/09/2001\r\n";
				welcomeMsg += ":" + serverName + " 004 " + clients[i].username + " :" + serverName + " 6.9\r\n";
				welcomeMsg += ":Feur 005 * CASEMAPPING=ascii\r\n";
				welcomeMsg += ":Feur 422 * :MOTD File is missing\r\n";
				send(fd, welcomeMsg.c_str(), welcomeMsg.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
			}
		}
	}
}

void	Server::Pong(std::string message, int fd)
{
	std::vector<std::string> command = split(message, ' ');
	if (command[0] != "PING")
		return;

	if (command.size() == 1)
	{
		std::string errorMessage = ":Feur 461 * " + command[1] + " :Not enough parameters\r\n";
		send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
		return ;
	}
	std::string errorMessage = "PONG" + message.substr(4) + "\r\n";
	send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
}

void	Server::Pass(std::string message, int fd) {
	std::vector<std::string> command = split(message, ' ');
	Client &client = getClient(fd, clients);
	if (command.size() < 2) {
		std::string errorMessage = ":Feur 464 " + message + " :Password Incorrect\r\n";
		send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
		return;
	}

	if (client.registred) {
		std::string errorMessage = ":Feur 462 " + message + " :User already registred\r\n";
		send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
		return;
	}

	if (command[1] != password) {
		std::string errorMessage = ":Feur 464 " + message + " :Password mismatch\r\n";
		send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
		return;
	}
	client.allowed = true;
}

void	Server::Invite(std::string message, int fd) {
	std::vector<std::string> command = split(message, ' ');
	Client client = getClient(fd, clients);

	if (command.size() < 3) {
		std::string errorMessage = ":Feur 461 " + message + " :Not enough parameters\r\n";
		send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
		return;
	}
	
	if (getChannel(command[2], channels).error) {
		std::string errorMessage = ":Feur 403 " + message + " :No such channel\r\n";
		send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
		return;
	}

	if (getClient(fd, getChannel(command[2], channels).user_list).getFd() == -1) {
		std::string errorMessage = ":Feur 442 " + client.getNick() + " " + command[2] + " :Not on channel\r\n";
		send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
		return;
	}
	bool found = false;
	for (int i = 0; i < (int)getChannel(command[2], channels).user_list.size() ;i++) {
		if (command[1] == getChannel(command[2], channels).user_list[i].getNick()) {
			found = true;
		}
	}
	if (found) {
		std::string errorMessage = ":Feur 443 " + message + " :Nickname is already used\r\n";
		send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
		return;
	}
	if (getClient(fd, getChannel(command[2], channels).operator_list).getFd() == -1) {
		std::string errorMessage = ":Feur 482 " + client.getNick() + " " + command[2] + " :You're not channel operator\r\n";
		send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
		return;
	}
	Client add_client;
	for (int i = 0; i < (int)clients.size(); i++) {
		if (clients[i].getNick() == command[1]) {
			add_client = clients[i];
			break;
		}
	}
	getChannel(command[2], channels).invited_list.push_back(add_client);
	std::string errorMessage = ":Feur 341 " + message + "\r\n";
	send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
}

void	Server::Mode(std::string message, int fd)
{
	std::vector<std::string> command = split(message, ' ');
	Channel	&channel = getChannel(command[1], channels);

	if (command.size() == 1) {
		std::string errorMessage = ":Feur 461 " + message + " :Not enough parameters\r\n";
		send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
		return ;
	}

	if (command[1][0] != '#')
		return ;

	if (channel.error) {
		std::string errorMessage = ":Feur 403 " + command[1] + " :No such channel\r\n";
		send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
		return ;
	}
	if (getClient(fd, getChannel(command[1], channels).operator_list).getFd() == -1)
	{
		std::string errorMessage = ":Feur 482 " + command[1] + " :You're not channel operator\r\n";
		send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
		return ;
	}
	if (command.size() == 2) {
		std::string msg = ":Feur 324 " + command[1];
		bool first = true;
		if (channel.invitation_mode) {
			if (first) {
				first = false;
				msg += " +";
			}
			msg += "i";
		}
		if (channel.t_mode) {
			if (first) {
				first = false;
				msg += " +";
			}
			msg += "t";
		}
		if (channel.password != "") {
			if (first) {
				first = false;
				msg += " +";
			}
			msg += "k";	
		}
		if (channel.limit > 0) {
			if (first) {
				first = false;
				msg += " +";
			}
			msg += "l";
		}
		msg += "\r\n";
		send(fd, msg.c_str(), msg.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
		return;
	}

	bool add = false;
	int	index_arg = 3;
	for (size_t i = 0; i < command[2].size(); i++) {
		if (command[2][i] != '+' && command[2][i] != '-' && command[2][i] != 'i' 
			&& command[2][i] != 't' && command[2][i] != 'k' && command[2][i] != 'o' && command[2][i] != 'l') {	
			std::string errorMessage = ":Feur 501 ";
			errorMessage += command[2][i];
			errorMessage += " :Unknown MODE flag\r\n";
			send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
			continue ;
		}
		if (command[2][i] == '+') {
			add = true;
			continue ;
		}
		if (command[2][i] == '-') {
			add = false;
			continue ;
		}
		if (command[2][i] == 'i') {
			if (add) {
				channel.invitation_mode = true;
			} else {
				channel.invitation_mode = false;
			}
		} else if (command[2][i] == 't') {
			if (add) {
				channel.t_mode = true;
			} else {
				channel.t_mode = false;
			}
		} else if (command[2][i] == 'k') {
			if (add) {
				if (command.size() > 3) {
					channel.password = command[index_arg++];
				} else {
					std::string errorMessage = ":Feur 461 " + message + " :Not enough parameters\r\n";
					send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
					continue ;
				}
			} else {
				channel.password = "";
			}
		} else if (command[2][i] == 'l') {
			if (add) {
				if (command.size() > 3) {
					channel.limit = atoi(command[index_arg++].c_str());
				} else {
					std::string errorMessage = ":Feur 461 " + message + " :Not enough parameters\r\n";
					send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
					continue;					
				}
				
			} else {
				channel.limit = -1;
			}
		} else if (command[2][i] == 'o') {
			bool fnd = false;
			int k = 0;
			const int	channel_user_size = channel.user_list.size();
			if (command.size() < 4) {
					std::string errorMessage = ":Feur 461 " + message + " :Not enough parameters\r\n";
					send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
					continue;
			}
			for (int i = 0; i < channel_user_size; i++) {
				if (channel.user_list[i].getNick() == command[index_arg++]) {
					fnd = true;
					k = i;
					break;
				}
			}
			if (!fnd) {
				std::string errorMessage = ":Feur 401 " + command[1] + " :No such nickname\r\n";
				send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
				continue;
			}
			if (add) {
				const int channel_oper_size = channel.operator_list.size();
				for (int i = 0; i < channel_oper_size; i++) {
					if (channel.user_list[k].getFd() == channel.operator_list[i].getFd())
						continue;
				}
				channel.operator_list.push_back(channel.user_list[k]);
			} else {
				const int channel_oper_size = channel.operator_list.size();
				bool found = false;
				int j = -1;
				for (int i = 0; i < channel_oper_size; i++) {
					if (channel.user_list[k].getFd() == channel.operator_list[i].getFd()) {
						found = true;
						j = i;
						break;
					}
				}
				if (!found) {
					return;
				} else {
					channel.operator_list.erase(channel.operator_list.begin() + j);
				}
			}
		}

	}
}

void Server::Privmsg(std::string message, int fd)
{
	std::vector<std::string> command = split(message, ' ');
	if ((command.size() == 1 || command[1][0] == ':') || isComma(command[1]))
	{
		std::string errorMessage = ":Feur 411 :No recipient given (PRIVMSG)\r\n";
		send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
		return ;
	}
	std::vector<std::string> list = split(command[1], ',');
	Client client;
	if (command.size() == 2 || command[2][0] != ':')
	{
		std::string errorMessage = ":Feur 412 :No text to send\r\n";
		send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
		return ;
	}
	for (size_t i = 0; i != list.size(); i++)
	{
		bool found = false;
		if (list[i][0] == '#')
		{
			if (getClient(fd, getChannel(list[i], channels).user_list).getFd() == -1)
			{
				std::string errorMessage = ":Feur 404 " + list[i] + " :Cannot send to channel\r\n";
				send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
				continue ;
			}
			std::string Message = ":" + getClient(fd, clients).getNick() + " PRIVMSG " + list[i];
					for (size_t k = 2; k != command.size(); k++)
						Message += " " + command[k];
					Message += "\r\n";
			for (size_t k = 0; k != getChannel(list[i], channels).user_list.size(); k++)
			{
				if (getChannel(list[i], channels).user_list[k].getFd() != fd)
					send(getChannel(list[i], channels).user_list[k].getFd(), Message.c_str(), Message.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
			}
			found = true;
		}
		else
		{
			for (size_t j = 0; j != clients.size(); j++)
			{
				if (list[i] == clients[j].getNick())
				{
					found = true;
					std::string Message = ":" + getClient(fd, clients).getNick() + " PRIVMSG " + clients[j].getNick();
					for (size_t k = 2; k != command.size(); k++)
						Message += " " + command[k];
					Message += "\r\n";
					send(clients[j].getFd(), Message.c_str(), Message.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
				}
			}
		}
		if (!found)
		{
			std::string errorMessage = ":Feur 401 " + list[i] + " :No such nick/channel\r\n";
			std::cout << list[i] << std::endl;
			send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
		}
	}
}

void Server::Join(std::string message, int fd)
{
	std::vector<std::string> command = split(message, ' ');
	if (command.size() == 1 || isComma(command[1]) || (command[1].size() == 1 && command[1][0] == '#'))
	{
		std::string errorMessage = ":Feur 461 * JOIN :Not enough parameters\r\n";
		send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
		return ;
	}
	bool pass = false;
	std::vector<std::string> list = split(command[1], ',');
	std::vector<std::string> key_list;
	if (command.size() >= 3)
	{
		if (!isComma(command[2]))
			key_list = split(command[2], ',');
				pass = true;
	}

	//check if there is enough parameters
	for (size_t i = 0; i != list.size(); i++)
	{
		if (list[i][0] != '#')
			list[i] += "#" + list[i];
		//if channel does not exist create one
		if (!channels.size() || getChannel(list[i], channels).error)
		{
			Channel first_channel;
			first_channel.name = list[i];
			channels.push_back(first_channel);
		}
		//check if the user is already in channel
		if (getChannel(list[i], channels).user_list.size())
		{
			std::vector<Client> user_list = getChannel(list[i], channels).user_list;
			if (getClient(fd, user_list).getFd() != -1)
				continue ;
		}
		//check if user is banned from channel
		if (getChannel(list[i], channels).banned_list.size())
		{
			std::vector<Client> banned_list = getChannel(list[i], channels).banned_list;
			if (getClient(fd, banned_list).getFd() != -1)
			{
				std::string errorMessage = ":Feur 474 " + getClient(fd, clients).getNick() + " " + list[i] + " :Cannot join channel (+b)\r\n";
				send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
				continue ;
			}
		}
		//check if the channel is full
		if (getChannel(list[i], channels).user_list.size() == (size_t)getChannel(list[i], channels).limit)
		{
			std::string errorMessage = ":Feur 471 " + getClient(fd, clients).getNick() + " " + list[i] + " :Cannot join channel (+l)\r\n";
			send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
			continue ;
		}
		//check if the user is invited
		std::vector<Client> invited_list = getChannel(list[i], channels).invited_list;
		if (getChannel(list[i], channels).invitation_mode && getClient(fd, invited_list).getFd() == -1)
		{
			std::string errorMessage = ":Feur 473 " + getClient(fd, clients).getNick() + " " + list[i] + " :Cannot join channel (+i)\r\n";
			send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
			continue ;
		}
		//check if the password is wrong
		if (getChannel(list[i], channels).password != "")
		{
			std::cout << "MDP NEEDED " << key_list.size() << std::endl;
			std::cout << getChannel(list[i], channels).password << std::endl;
			if (!pass)
			{
				std::cout << "allah" << std::endl;
				std::string errorMessage = ":Feur 475 " + getClient(fd, clients).getNick() + " " + list[i] + " :Cannot join channel (+k)\r\n";
				send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
				continue ;
			}
			else
			{
				if (key_list.size() < i || getChannel(list[i], channels).password != key_list[i])
				{
					std::string errorMessage = ":Feur 475 " + getClient(fd, clients).getNick() + " " + list[i] + " :Cannot join channel (+k)\r\n";
					send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
					continue ;
				}
			}
		}
		//client joined the channel
		if (!getChannel(list[i], channels).user_list.size())
			getChannel(list[i], channels).operator_list.push_back(getClient(fd, clients));
		getChannel(list[i], channels).user_list.push_back(getClient(fd, clients));
		std::string join_message = ":" + getClient(fd, clients).getNick() + "!~" + getClient(fd, clients).getNick() + "@" + getClient(fd, clients).ip + " JOIN " + list[i] + "\r\n";
		send_to_all_client(join_message, getChannel(list[i], channels).user_list);
		//say topic to the client
		if (getChannel(list[i], channels).topic == "")
		{
			std::string no_topic = ":Feur 331 " + getClient(fd, clients).getNick() + " " + list[i] + " :No topic is set\r\n";
			send(fd, no_topic.c_str(), no_topic.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
		}
		else
		{
			std::string topic = ":Feur 332 " + getClient(fd, clients).getNick() + " " + list[i] + " :" + getChannel(list[i], channels).topic + "\r\n";
			send(fd, topic.c_str(), topic.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
		}
		//say user list to the client
		std::string user_in_channel = ":Feur 353 * = " + list[i] + " :";
		bool first = false;
		std::vector<Client> operator_list = getChannel(list[0], channels).operator_list;
		for (size_t j = 0; j != getChannel(list[0], channels).user_list.size(); j++)
		{
			if (!first)
				first = true;
			else
				user_in_channel += " ";
			if (getClient(getChannel(list[0], channels).user_list[j].getFd(), operator_list).getFd() != -1)
				user_in_channel += "@";
			user_in_channel += getChannel(list[0], channels).user_list[j].getNick();
		}
		user_in_channel += "\r\n";
		send(fd, user_in_channel.c_str(), user_in_channel.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
		std::string end_of_name = ":Feur 366 " + getClient(fd, clients).getNick() + " " + list[i] + " :End of /NAMES list\r\n";
		send(fd, end_of_name.c_str(), end_of_name.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
	}
}

void Server::Topic(std::string message, int fd)
{
	std::vector<std::string> command = split(message, ' ');

	if (command.size() == 1)
	{
		std::string errorMessage = ":Feur 461 * " + message + " :Not enough parameters\r\n";
		send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
		return ;
	}
	std::cout << "1" << std::endl;
	if (getChannel(command[1], channels).error)
	{
		std::string errorMessage = ":Feur 403 " + command[1] + " :No such channel\r\n";
		send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
		return ;
	}
	std::cout << "2" << std::endl;
	if (getClient(fd, getChannel(command[1], channels).user_list).getFd() == -1)
	{
		std::string errorMessage = ":Feur 422 " + command[1] + " :You're not on that channel\r\n";
		send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
		return ;
	}
	std::cout << "3" << std::endl;
	if (getClient(fd, getChannel(command[1], channels).operator_list).getFd() == -1)
	{
		if (getChannel(command[1], channels).t_mode)
		{
			std::string errorMessage = ":Feur 482 " + command[1] + " :You're not channel operator\r\n";
			send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
			return ;
		}
	}
	std::cout << "4" << std::endl;
	if (command.size() == 2)
	{
		if (getChannel(command[1], channels).topic == "")
		{
			std::string no_topic = ":Feur 331 " + getClient(fd, clients).getNick() + " " + command[1] + " :No topic is set\r\n";
			send(fd, no_topic.c_str(), no_topic.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
			return ;
		}
		else
		{
			std::string topic = ":Feur 332 " + getClient(fd, clients).getNick() + " " + command[1] + " :" + getChannel(command[1], channels).topic + "\r\n";
			send(fd, topic.c_str(), topic.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
			return ;
		}
	}
	std::cout << "5" << std::endl;
	message += "\r\n";
	std::string str = ":" + getClient(fd, clients).getNick() + "!~" + getClient(fd, clients).getNick() + "@" + getClient(fd, clients).ip + " ";
	str += message;
	if (command[2].size() == 1)
		getChannel(command[1], channels).topic = "";
	std::cout << message << std::endl;
	for (size_t i = 0; i != getChannel(command[1], channels).user_list.size(); i++)
		send(getChannel(command[1], channels).user_list[i].getFd(), str.c_str(), str.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
	if (command[2][0] == ':' && command[2].size() > 1)
	{
		command[2] = command[2].substr(1);
		std::string topic = command[2];
		for (size_t i = 3; i != command.size(); i++)
			topic += " " + command[i];
		getChannel(command[1], channels).topic = topic;
	}
	std::cout << "6" << std::endl;
}

void Server::Part(std::string message, int fd)
{
	std::vector<std::string> command = split(message, ' ');
	if (command.size() == 1 || isComma(command[1]))
	{
		std::string errorMessage = ":Feur 461 * " + message + " :Not enough parameters\r\n";
		send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
		return ;
	}
	std::vector<std::string> list = split(command[1], ',');
	for (size_t i = 0; i != list.size(); i++)
	{
		if (getChannel(list[i], channels).error)
		{
			std::string errorMessage = ":Feur 403 " + command[1] + " :No such channel\r\n";
			send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
			continue ;
		}
		if (getClient(fd, getChannel(list[i], channels).user_list).getFd() == -1)
		{
			std::string errorMessage = ":Feur 422 " + list[i] + " :You're not on that channel\r\n";
			send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
			continue ;
		}
		std::string Message = ":" + getClient(fd, clients).getNick() + "!~" + getClient(fd, clients).getNick() + "@" + getClient(fd, clients).ip + " PART " + list[i];
		for (size_t j = 2; j != command.size(); j++)
			Message += " " + command[j];
		Message += "\r\n";
		std::cout << Message;
		send_to_all_client(Message, getChannel(list[i], channels).user_list);
		for (size_t ChannelID = 0; ChannelID != channels.size(); ChannelID++)
		{
			if (channels[ChannelID].name == list[i])
			{
				for (size_t k = 0; k != channels[ChannelID].user_list.size(); k++)
				{
					if (channels[ChannelID].user_list[k].getFd() == fd)
					{
						channels[ChannelID].user_list.erase(channels[ChannelID].user_list.begin() + k);
						break ;
					}
				}
				for (size_t k = 0; k != channels[ChannelID].operator_list.size(); k++)
				{
					if (channels[ChannelID].operator_list[k].getFd() == fd)
					{
						channels[ChannelID].operator_list.erase(channels[ChannelID].operator_list.begin() + k);
						break ;
					}
				}
				continue ;
			}
		}
	}
}

void Server::Kick(std::string message, int fd)
{
	std::vector<std::string> command = split(message, ' ');

	if (command.size() < 3 || isComma(command[2]))
	{
		std::string errorMessage = ":Feur 461 * " + message + " :Not enough parameters\r\n";
		send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
		return ;
	}
	std::vector<std::string> list = split(command[2], ',');
	if (getChannel(command[1], channels).error)
	{
		std::string errorMessage = ":Feur 403 * " + command[1] + " :No such channel\r\n";
		send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
		return ;
	}
	if (getClient(fd, getChannel(command[1], channels).user_list).getFd() == -1)
	{
		std::string errorMessage = ":Feur 442 * " + command[1] + " :You're not on that channel\r\n";
		send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
		return ;
	}
	if (getClient(fd, getChannel(command[1], channels).operator_list).getFd() == -1)
	{
		std::string errorMessage = ":Feur 482 * " + command[1] + " :You're not channel operator\r\n";
		send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
		return ;
	}
	for (size_t i = 0; i != list.size(); i++)
	{
		bool found = false;
		for (size_t j = 0; j != getChannel(command[1], channels).user_list.size(); j++)
		{
			std::cout << list[i] << " != " << getChannel(command[1], channels).user_list[j].getNick() << std::endl;
			if (list[i] == getChannel(command[1], channels).user_list[j].getNick())
				found = true;
		}
		std::cout << "user: " << found << std::endl;
		if (!found)
		{
			std::string errorMessage = ":Feur 441 " + list[i] + " " + command[1] + " :They aren't on that channel\r\n";
			send(fd, errorMessage.c_str(), errorMessage.length(), MSG_DONTWAIT | MSG_NOSIGNAL);
			continue ;
		}
		std::string Message = ":" + getClient(fd, clients).getNick() + " KICK " + command[1] + " " + list[i];
		if (command[3].size() != 1)
			Message += " " + command[3];
		if (command.size() >= 4)
		{
			for (size_t k = 4; k != command.size(); k++)
				Message += " " + command[k];
		}
		Message += "\r\n";
		std::cout << Message;
		send_to_all_client(Message, getChannel(command[1], channels).user_list);
		int ChannelID = 0;
		for (size_t k = 0; k != channels.size(); k++)
		{
			if (channels[k].name == command[1])
			{
				ChannelID = k;
				break ;
			}
		}
		for (size_t k = 0; k != channels[ChannelID].user_list.size(); k++)
		{
			if (channels[ChannelID].user_list[k].getNick() == list[i])
			{
				channels[ChannelID].user_list.erase(channels[ChannelID].user_list.begin() + k);
				break ;
			}
		}
		for (size_t k = 0; k != channels[ChannelID].operator_list.size(); k++)
		{
			if (channels[ChannelID].operator_list[k].getNick() == list[i])
			{
				channels[ChannelID].operator_list.erase(channels[ChannelID].operator_list.begin() + k);
				break ;
			}
		}
	}
}

void Server::Quit(std::string message, int fd)
{
	std::vector<std::string> command = split(message, ' ');
	std::string Message = ":" + getClient(fd, clients).getNick() + " QUIT";
	if (command.size() != 1)
	{
		Message += " :";
		for (size_t i = 1; i != command.size(); i++)
			Message += " " + command[i];
	}
	Message += "\r\n";
	for (size_t i = 0; i != channels.size(); i++)
	{
		if (getClient(fd, channels[i].user_list).getFd() != -1)
		{
			send_to_all_client(Message, channels[i].user_list);
			for (size_t k = 0; k != channels[i].user_list.size(); k++)
			{
				if (channels[i].user_list[k].getFd() == fd)
				{
					channels[i].user_list.erase(channels[i].user_list.begin() + k);
					break ;
				}
			}
			for (size_t k = 0; k != channels[i].operator_list.size(); k++)
			{
				if (channels[i].operator_list[k].getFd() == fd)
				{
					channels[i].operator_list.erase(channels[i].operator_list.begin() + k);
					break ;
				}
			}
		}
	}
	std::cout << RED << "Client <" << fd << "> Disconnected" << WHI << std::endl;
	this->clearClients(fd);
	close(fd);
}
