/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:28:04 by vcornill          #+#    #+#             */
/*   Updated: 2024/02/08 14:15:41 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
Dog::Dog()		: Animal(), brain( new Brain() )
{ this->type = "Dog"; std::cout << "Dog created" << std::endl; }
Dog::Dog( Dog &cpy)	: Animal(), brain( cpy.brain )
{ this->type = cpy.type; std::cout << "Dog copy created" << std::endl; }
Dog::~Dog()
{ delete this->brain; std::cout << "Dog destroyed" << std::endl; }

Dog		&Dog::operator=( const Dog &ref )
{
	this->brain = ref.brain;
	return *this;
}

void	Dog::makeSound( void ) const	{ std::cout << "CuiCui..." << std::endl; }
