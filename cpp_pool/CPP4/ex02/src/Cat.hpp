/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:28:14 by vcornill          #+#    #+#             */
/*   Updated: 2024/02/08 14:05:07 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal
{
private:
	Brain	*brain;
public:
	Cat();
	Cat( Cat &cpy);
	~Cat();

	Cat		&operator=( const Cat &ref );
	
	void	makeSound( void ) const;
};
