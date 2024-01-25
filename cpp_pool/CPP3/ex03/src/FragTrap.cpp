/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:48:23 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/25 12:52:10 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( std::string Name ) : ClapTrap( Name )
{
	this->setHealth( 100 );
	this->setEnergy( 100 );
	this->setAttackDamage( 30 );
	std::cout << "FragTrap " << this->name << " created." << std::endl;
}

FragTrap::FragTrap( FragTrap  &copy ) : ClapTrap( copy )
{ std::cout << "FragTrap " << this->name << " created." << std::endl; }
FragTrap::~FragTrap()
{ std::cout << "FragTrap " << this->name << " destroyed." << std::endl; }


void	FragTrap::attack( std::string target )
{ if (this->energy > 0) 
	{std::cout << "FragTrap " << this->name << " attacks savagely " << target 
	<< ", causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energy -= 1;} }
void	FragTrap::highFivesGuys( void )
{ std::cout << "FragTrap " << this->name << " :Let's make a high fives guys!" << std::endl; }
