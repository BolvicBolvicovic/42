/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:12:23 by vcornill          #+#    #+#             */
/*   Updated: 2024/02/08 13:56:16 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class	Brain
{
private:
	std::string	ideas[100];
public:
	Brain();
	Brain( Brain &ref );
	~Brain();

	Brain	&operator=( const Brain &ref );
};
