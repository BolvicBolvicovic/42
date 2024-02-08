/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:28:07 by vcornill          #+#    #+#             */
/*   Updated: 2024/02/08 14:16:07 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
Cat::Cat()		: Animal(), brain( new Brain() )
{ this->type = "Cat"; std::cout << "Cat created" << std::endl; }
Cat::Cat( Cat &cpy)	: Animal(), brain( cpy.brain )
{ this->type = cpy.type; std::cout << "Cat copy created" << std::endl; }
Cat::~Cat()
{ delete this->brain; std::cout << "Cat destroyed" << std::endl; }

Cat		&Cat::operator=( const Cat &ref )
{
	this->brain = ref.brain;
	return *this;
}
void	Cat::makeSound( void ) const	{ std::cout << "Je soutiens E.Z..." << std::endl; }
