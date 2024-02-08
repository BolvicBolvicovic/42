/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:27:55 by vcornill          #+#    #+#             */
/*   Updated: 2024/02/08 14:12:57 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : type( "" )
{ std::cout << "Animal created" << std::endl; }
Animal::Animal( Animal &copy ) : type( copy.type )
{ std::cout << "Animal copied " << this->type  << " created" << std::endl; }
Animal::~Animal( void )
{ std::cout << "Animal " << this->type << " detroyed" << std::endl; }

Animal	&Animal::operator=( const Animal &ref ) { this->type = ref.type; return *this; }

std::string	Animal::getType( void ) const		{ return this->type; }
void		Animal::setType( std::string str )	{ this->type = str; }
void		Animal::makeSound( void ) const		{ std::cout << "Sounds..." << std::endl; }
