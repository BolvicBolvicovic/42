/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:28:07 by vcornill          #+#    #+#             */
/*   Updated: 2024/03/06 16:21:17 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
Cat::Cat()		: Animal( "Cat" ) { std::cout << "Cat created" << std::endl; }
Cat::Cat( Cat &cpy)	: Animal( cpy.type ) { std::cout << "Cat copy created" << std::endl; }
Cat::~Cat()		{ std::cout << "Cat destroyed" << std::endl; }

void	Cat::makeSound( void ) const	{ std::cout << "On peut pu dire r...miaou..miaou..." << std::endl; }
