/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:26:29 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/25 13:49:38 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Scavtrap.hpp"
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

	using	FragTrap::getHealth();
	using	ScavTrap::getEnergy();
	using	FragTrap::getAttackDamage();
};
