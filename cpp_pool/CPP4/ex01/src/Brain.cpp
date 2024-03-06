/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:12:15 by vcornill          #+#    #+#             */
/*   Updated: 2024/03/04 15:34:13 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>
Brain::Brain()	{ std::cout << "Brain built" << std::endl; }
Brain::Brain( Brain &cpy )
{
	*this = cpy;
    std::cout << "Brain cpy built" << std::endl;
}
Brain::~Brain()	{ std::cout << "Brain destroyed" << std::endl; }

Brain	&Brain::operator=( const Brain &ref )
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = ref.ideas[i];
	return *this;
}
