/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:33:52 by vcornill          #+#    #+#             */
/*   Updated: 2024/02/08 13:05:57 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap( std::string Name ) : ClapTrap( Name + "_clap_trap" ), ScavTrap( Name + "_clap_trap" ), FragTrap( Name + "_clap_trap" ), name(Name)
{
	std::cout << "DiamondTrap " << this->name << " built." << std::endl;
	health = FragTrap::getHealth();
	attackDamage = FragTrap::getAttackDamage();
	energy = ScavTrap::getEnergy();
}
DiamondTrap::DiamondTrap( const DiamondTrap  &copy ) : ClapTrap( copy.name + "_clap_trap" ), ScavTrap( copy.name + "_clap_trap" ), FragTrap( copy.name + "_clap_trap" ), name(copy.name)
{ 
	setHealth(FragTrap::getHealth());
	setAttackDamage(FragTrap::getAttackDamage());
	setEnergy(ScavTrap::getEnergy());
}
DiamondTrap::~DiamondTrap()
{ std::cout << "DiamondTrap " << this->name << " destroyed." << std::endl; }
std::string	DiamondTrap::getName( void )	{ return this->name; }
void		DiamondTrap::setName( std::string str )	{ this->name = str; }
void		DiamondTrap::whoAmI( void ) { std::cout << this->name << " " << ClapTrap::name << std::endl; }
