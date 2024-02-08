/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:28:11 by vcornill          #+#    #+#             */
/*   Updated: 2024/02/08 14:04:45 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal
{
private:
	Brain	*brain;	
public:
	Dog();
	Dog( Dog &cpy);
	~Dog();

	Dog		&operator=( const Dog &ref );

	void	makeSound( void ) const;
};
