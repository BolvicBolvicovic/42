/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:32:48 by acasamit          #+#    #+#             */
/*   Updated: 2024/04/05 21:46:37 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "lib.hpp"

class Client
{
	private:
		int			fd;
		std::string	IPaddress;
		std::string _nickname;
	public:
					Client();
					~Client();
	
	int			getFd();
	bool		allowed;
	bool		registred;
	bool		full_registred;
	std::vector<char> mode;
	std::string username;
	std::string ip;
	std::string unfinished_registration;

	std::string message;
	size_t pos;

	void		setFd(const int fd);
	void		setIPaddress(const char *ipaddr);
	std::string getNick() const;
	void		setNick(std::string nick);
};
