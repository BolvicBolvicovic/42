/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:43:58 by vcornill          #+#    #+#             */
/*   Updated: 2024/02/02 13:20:12 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::~AMateria( void ) { std::cout << "AMateria " << this->type << " destroyed\n"; }
AMateria::AMateria( std::string Type );

std::string const	&AMateria::getType( void ) const	{ return this->type; }

void		AMateria::use( ICharacter &target )
{ std::cout << "'* Amateria has some effect on " << target.getName() << " *'\n"; }
