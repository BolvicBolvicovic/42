/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:43:58 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/26 10:44:22 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::~AMateria( void ) { std::cout << "AMateria " << this->type << " destroyed\n"; }

std::string const	&AMateria::getType( void ) const	{ return this->type; }

void		AMateria::use( ICharacter &target )
{ std::cout << "'* Amateria has some effect on " << target.getName() << " *'\n"; }
