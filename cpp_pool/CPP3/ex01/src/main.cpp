/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:26:24 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/25 12:43:29 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main( void )
{
	ClapTrap a( "SeX" ); ClapTrap b( a );
	std::cout << "b name: " << b.getName() << std::endl;
	b.setName( "BonK" );
	std::cout << "b name changed: " << b.getName() << std::endl;
	a.attack( b.getName() );
	b.takeDamage( a.getAttackDamage() );
	b.beRepaired( 5 );
	
	ScavTrap c( "CHAD" ); ScavTrap d( c );
	std::cout << "d name: " << d.getName() << std::endl;
	d.setName( "beta" );
	std::cout << "d name changed: " << d.getName() << std::endl;
	c.attack( d.getName() );
	d.takeDamage( d.getAttackDamage() );
	d.beRepaired( 10 );
	c.guardGate();
	return 0;
}
