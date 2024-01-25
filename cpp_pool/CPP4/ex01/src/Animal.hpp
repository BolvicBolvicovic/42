/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:28:01 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/25 17:45:55 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class	Animal
{
protected:
	std::string	type;
public:
	Animal( void );
	Animal( std::string type );
	Animal( Animal &copy );
	~Animal( void );

	std::string	getType( void ) const;
	void		setType( std::string str );

	virtual void	makeSound( void ) const;

};
