/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:43:55 by vcornill          #+#    #+#             */
/*   Updated: 2024/02/02 13:20:16 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string	type;
public:
	virtual			AMateria( std::string Type );
	virtual			~AMateria( void );
	
	std::string const	&getType( void ) const;		//Returns the materia type
	
	virtual AMateria	*clone( void ) const = 0;
	virtual void		use( ICharacter &target );
};
