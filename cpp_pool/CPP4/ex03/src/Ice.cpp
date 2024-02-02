/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:44:04 by vcornill          #+#    #+#             */
/*   Updated: 2024/02/02 12:13:40 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : type("Ice")					{ std::cout << "Ice created"\n; }
Ice::Ice( Ice &ice ) : type ( ice.type )	{ std::cout << "Ice copied"\n; }
Ice::~Ice()									{ std::cout << "Ice destroyed\n"; }

Ice		&operator=( Ice &ref )				{ return ref; }

void		Ice::use( ICharacter &target )
{ std::cout << "'* shoots an ice bolt at " << target.getName() << " *'" << std::endl; }
AMateria	*Ice::clone() const
{ AMateria *clone; *clone = new Ice(); return clone;}
