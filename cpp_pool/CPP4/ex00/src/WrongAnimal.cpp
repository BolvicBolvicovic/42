/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:27:55 by vcornill          #+#    #+#             */
/*   Updated: 2024/02/16 12:29:22 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : type( "" )
{ std::cout << "WrongAnimal created" << std::endl; }
WrongAnimal::WrongAnimal( std::string type ) : type( type )
{std::cout << "WrongAnimal " << this->type  << " created" << std::endl; }
WrongAnimal::WrongAnimal( WrongAnimal &copy ) : type( copy.type )
{std::cout << "WrongAnimal copied " << this->type  << " created" << std::endl; }
WrongAnimal::~WrongAnimal( void )
{std::cout << "WrongAnimal " << this->type << " detroyed" << std::endl; }

WrongAnimal		&WrongAnimal::operator=( const WrongAnimal &ref ) { this->type = ref.type; return *this; }

std::string	WrongAnimal::getType( void ) const	{ return this->type; }
void		WrongAnimal::setType( std::string str )	{ this->type = str; }
void		WrongAnimal::makeSound( void ) const	{ std::cout << "WrongSounds..." << std::endl; }
