/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:28:07 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/26 10:32:10 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
Dog::Dog()		: brain( new Brain() )
{
	this->setType( "Dog" );
	std::cout << "Dog created" << std::endl;
}
Dog::Dog( Dog &cpy)	: brain( cpy.brain )
{
	this->setType( cpy.type );
	std::cout << "Dog copy created" << std::endl;
}
Dog::~Dog()
{ delete this->brain; std::cout << "Dog destroyed" << std::endl; }

void	Dog::makeSound( void ) const	{ std::cout << "CuiCui..." << std::endl; }
