/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:27:55 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/26 10:34:24 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::~Animal() { std::cout << "An animal has been eliminated." << std::endl; }
std::string	Animal::getType( void ) const		{ return this->type; }
void		Animal::setType( std::string str )	{ this->type = str; }
