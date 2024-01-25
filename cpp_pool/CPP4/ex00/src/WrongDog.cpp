/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:28:04 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/25 18:00:57 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"
WrongDog::WrongDog()		: WrongAnimal( "WrongDog" ) { std::cout << "WrongDog created" << std::endl; }
WrongDog::WrongDog( WrongDog &cpy)	: WrongAnimal( cpy.type ) { std::cout << "WrongDog copy created" << std::endl; }
WrongDog::~WrongDog()		{ std::cout << "WrongDog destroyed" << std::endl; }

void	WrongDog::makeSound( void ) const	{ std::cout << "WrongCuiCui..." << std::endl; }
