/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 01:34:32 by acasamit          #+#    #+#             */
/*   Updated: 2024/04/02 16:43:19 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "lib.hpp"

class Channel
{
	public:
		std::vector<Client> operator_list;
		std::vector<Client> user_list;
		std::vector<Client> banned_list;
		std::vector<Client> invited_list;
		std::string password;
		std::string topic;
		std::string name;
		bool invitation_mode;
		int limit;
		bool error;
		bool t_mode;

		Channel() : password(""), topic(""), invitation_mode(false), limit(-1), error(false), t_mode(false) {}
};

