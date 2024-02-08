/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:28:07 by vcornill          #+#    #+#             */
/*   Updated: 2024/02/08 14:03:51 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
Cat::Cat()		: Animal( "Cat" ), brain( new Brain() )
{ std::cout << "Cat created" << std::endl; }
Cat::Cat( Cat &cpy)	: Animal( cpy.type ), brain( cpy.brain )
{ std::cout << "Cat copy created" << std::endl; }
Cat::~Cat()
{ delete this->brain; std::cout << "Cat destroyed" << std::endl; }

Cat		&Cat::operator=( const Cat &ref )
{
	this->brain = ref.brain;
	return *this;
}
void	Cat::makeSound( void ) const	{ std::cout << "Je soutiens E.Z..." << std::endl; }
