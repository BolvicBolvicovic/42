/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:28:07 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/26 10:32:10 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
Cat::Cat()		: brain( new Brain() )
{
	this->setType( "Cat" );
	std::cout << "Cat created" << std::endl;
}
Cat::Cat( Cat &cpy)	: brain( cpy.brain )
{
	this->setType( cpy.type );
	std::cout << "Cat copy created" << std::endl;
}
Cat::~Cat()
{ delete this->brain; std::cout << "Cat destroyed" << std::endl; }

void	Cat::makeSound( void ) const	{ std::cout << "Je soutiens E.Z..." << std::endl; }
