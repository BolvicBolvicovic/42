/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:06:30 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/25 12:40:40 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string Name ) : ClapTrap( Name )
{
	this->setHealth( 100 );
	this->setEnergy( 50 );
	this->setAttackDamage( 20 );
	std::cout << "ScavTrap " << this->name << " created." << std::endl;
}

ScavTrap::ScavTrap( ScavTrap  &copy ) : ClapTrap( copy )
{ std::cout << "ScavTrap " << this->name << " created." << std::endl; }
ScavTrap::~ScavTrap()
{ std::cout << "ScavTrap " << this->name << " destroyed." << std::endl; }


void	ScavTrap::attack( std::string target )
{ if (this->energy > 0) 
	{std::cout << "ScavTrap " << this->name << " attacks savagely " << target 
	<< ", causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energy -= 1;} }
void	ScavTrap::guardGate( void )
{ std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl; }
