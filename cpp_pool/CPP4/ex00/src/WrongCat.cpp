/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:28:07 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/25 18:03:08 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
WrongCat::WrongCat()		: WrongAnimal( "WrongCat" ) { std::cout << "WrongCat created" << std::endl; }
WrongCat::WrongCat( WrongCat &cpy)	: WrongAnimal( cpy.type ) { std::cout << "WrongCat copy created" << std::endl; }
WrongCat::~WrongCat()		{ std::cout << "WrongCat destroyed" << std::endl; }

void	WrongCat::makeSound( void ) const	{ std::cout << "Je soutiens WrongE.Z..." << std::endl; }
