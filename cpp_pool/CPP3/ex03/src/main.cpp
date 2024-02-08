/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:26:24 by vcornill          #+#    #+#             */
/*   Updated: 2024/02/08 13:06:30 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main( void )
{
	DiamondTrap e( "clebard" ); DiamondTrap f( e );
	std::cout << "f name: " << f.getName() << std::endl;
	f.setName( "vraiment" );
	std::cout << "f name changed: " << f.getName() << std::endl;
	e.attack( f.getName() );
	f.takeDamage( f.getAttackDamage() );
	f.beRepaired( 10 );
	e.highFivesGuys();
	e.whoAmI();
	return 0;
}
