/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:28:04 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/25 17:42:09 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
Dog::Dog()		: Animal( "Dog" ) { std::cout << "Dog created" << std::endl; }
Dog::Dog( Dog &cpy)	: Animal( cpy.type ) { std::cout << "Dog copy created" << std::endl; }
Dog::~Dog()		{ std::cout << "Dog destroyed" << std::endl; }

void	Dog::makeSound( void ) const	{ std::cout << "CuiCui..." << std::endl; }
