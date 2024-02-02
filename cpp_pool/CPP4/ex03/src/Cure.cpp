/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:44:08 by vcornill          #+#    #+#             */
/*   Updated: 2024/02/02 12:14:37 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : type("Cure")						{ std::cout << "Cure created"\n; }
Cure::Cure( Cure &cure ) : type ( cure.type )	{ std::cout << "Cure copied"\n; }
Cure::~Cure()									{ std::cout << "Cure destroyed\n"; }

Cure		&operator=( Cure &ref )				{ return ref; }

void		Cure::use( ICharacter &target )
{ std::cout << "'* heals " << target.getName() << "'s wounds *'" << std::endl; }
AMateria	*Cure::clone() const
{ AMateria *clone; *clone = new Cure(); return clone;}
