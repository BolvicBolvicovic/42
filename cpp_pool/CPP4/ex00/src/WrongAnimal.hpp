/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:28:01 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/25 18:06:25 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class	WrongAnimal
{
protected:
	std::string	type;
public:
	WrongAnimal( void );
	WrongAnimal( std::string type );
	WrongAnimal( WrongAnimal &copy );
	~WrongAnimal( void );

	std::string	getType( void ) const;
	void		setType( std::string str );

	void		makeSound( void ) const;

};
