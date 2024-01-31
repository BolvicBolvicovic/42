/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:44:11 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/26 10:44:22 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class ICharacter
{
private:
	std::string	name;
	AMateria	*materia[4];
public:
	ICharacter( std::string Name );
	ICharacter( ICharacter &character );
	~ICharacter();
	
	std::string const	&getName() const;
	AMateria			*getMateria( int idx ) const;
	
	void				equip( AMateria *m );
	void				unequip( int idx );
	void				use( int idx, ICharacter &target );
};
