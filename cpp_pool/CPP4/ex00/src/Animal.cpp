/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:27:55 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/25 17:38:53 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : type( "" )
{ std::cout << "Animal created" << std::endl; }
Animal::Animal( std::string type ) : type( type )
{std::cout << "Animal " << this->type  << " created" << std::endl; }
Animal::Animal( Animal &copy ) : type( copy.type )
{std::cout << "Animal copied " << this->type  << " created" << std::endl; }
Animal::~Animal( void )
{std::cout << "Animal " << this->type << " detroyed" << std::endl; }

std::string	Animal::getType( void ) const		{ return this->type; }
void		Animal::setType( std::string str )	{ this->type = str; }
void		Animal::makeSound( void ) const		{ std::cout << "Sounds..." << std::endl; }
