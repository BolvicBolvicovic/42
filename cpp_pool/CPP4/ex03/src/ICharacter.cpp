/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:44:15 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/26 10:44:22 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter( std::string Name )		: name( Name )
{
	for (int i = 0; i < 4; i++)
		this->materia[i] = NULL;
	std::cout << this->name << " created" << std::endl;
}
ICharacter::ICharacter( ICharacter &character )	: name( character.name )
{
	for (int i = 0; i < 4; i++)
		this->materia[i] = character.materia[i].clone();
	std::cout << this->name << " copy created" << std::endl;
}
ICharacter::~ICharacter()
{
	for (int i = 0; i < 4; i++)
		delete this->materia[i];
	std::cout << this->name << " deleted." << std::endl;
}
	
std::string const	&ICharacter::getName() const				{ return this->name; }
AMateria			*ICharacter::getMateria( int idx ) const	{ return this->materia[idx]; }
	
void				ICharacter::equip( AMateria *m )
{
	for (int i = 0; i < 4; i++)
		if ( !this->materia[i] )
			this->materia[i] = m;
}
void				ICharacter::unequip( int idx )	{ this->materia[idx] = NULL; }

void				ICharacter::use( int idx, ICharacter &target )
{ if ( this->materia[idx] )
	{ this->materia[idx].use( target ); delete this->materia[idx]; this->materia[idx] = NULL; }
}
