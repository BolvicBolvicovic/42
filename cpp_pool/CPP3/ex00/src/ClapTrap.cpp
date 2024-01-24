/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:34:12 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/24 16:17:01 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

	std::string	name;
	int		health;
	int		energy;
	int		attackDamage;
ClapTrap::ClapTrap( std::string Name ) : health(10), energy(10), attackDamage(0) { std::cout << "ClapTrap " << this->name << " created." << std::endl; }
ClapTrap::ClapTrap( ClapTrap &copy ) : name(copy.name), health(copy.health), energy(copy.energy), attackDamage(copy.attackDamage){ std::cout << "ClapTrap " << this->name << " created." << std::endl; }
ClapTrap::~ClapTrap(){ std::cout << "ClapTrap " << this->name << " destroyed." << std::endl; }

ClapTrap	&ClapTrap::operator=( ClapTrap &ct )
{ if (this != &ct) 
	{this->health = ct.health; this->name = ct.name; this->energy = ct->energy; this->attackDamage = ct.attackDamage;} 
	return *this;}

void		ClapTrap::attack( const std::string& target )
{ if (this->energy > 0) 
	{std::cout << "ClapTrap " << this->name << " attacks " << target 
	<< ", causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energy -= 1;} }

void		ClapTrap::takeDamage( unsigned int amount )
{ this->health -= amount; 
std::cout << "ClapTrap " << this->name << " takes in " << amount << " damages!" << std::endl;}

void		ClapTrap::beRepaired( unsigned int amount )
{ if (this->energy > 0) 
	{this->health += amount; this->energy -= 1;
	std::cout << "ClapTrap " << this->name << " healed of " << amount << " HP!" << std::endl;} }

std::string	ClapTrap::getName( void )		{ return this->name; }
int		ClapTrap::getHealth( void )		{ return this->health; }
int		ClapTrap::getEnergy( void )		{ return this->energy; }
int		ClapTrap::getAttackDamage( void )	{ return this->attackDamage; }

void		ClapTrap::setName( std::string str )	{ this->name = str; }
void		ClapTrap::setHealth( int nb )		{ this->health = nb; }
void		ClapTrap::setEnergy( int nb )		{ this->energy = nb; }
void		ClapTrap::setAttackDamage( int nb )	{ this->attackDamage = nb; }
