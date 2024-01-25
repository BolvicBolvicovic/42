/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:28:11 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/25 17:57:11 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class	WrongDog : public WrongAnimal
{
public:
	WrongDog();
	WrongDog( WrongDog &cpy);
	~WrongDog();

	void	makeSound( void ) const;
};
