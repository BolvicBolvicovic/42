/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:12:15 by vcornill          #+#    #+#             */
/*   Updated: 2024/02/08 14:06:12 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>
Brain::Brain()	{ std::cout << "Brain built" << std::endl; }
Brain::Brain( Brain &cpy )
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = cpy.ideas[i];
	std::cout << "Brain cpy built" << std::endl;
}
Brain::~Brain()	{ std::cout << "Brain destroyed" << std::endl; }

Brain	&Brain::operator=( const Brain &ref )
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = ref.ideas[i];
	return *this;
}
