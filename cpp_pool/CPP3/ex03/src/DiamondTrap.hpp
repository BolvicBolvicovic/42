/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:26:29 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/25 16:09:47 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string	name;
public:
	DiamondTrap( std::string Name );
	DiamondTrap( const DiamondTrap  &copy );
	~DiamondTrap();

	using	ScavTrap::attack;

	using	FragTrap::beRepaired;
	using	FragTrap::takeDamage;

	using	FragTrap::health;
	using	ScavTrap::energy;
	using	FragTrap::attackDamage;
	
	using	FragTrap::getHealth;
	using	ScavTrap::getEnergy;
	using	FragTrap::getAttackDamage;

	using	FragTrap::setHealth;
	using	ScavTrap::setEnergy;
	using	FragTrap::setAttackDamage;
	
	void		setName( std::string str );
	std::string	getName( void );
};
