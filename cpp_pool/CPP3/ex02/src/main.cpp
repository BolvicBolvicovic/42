/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:26:24 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/25 12:54:48 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
	
	FragTrap e( "clebard" ); FragTrap f( e );
	std::cout << "f name: " << f.getName() << std::endl;
	f.setName( "vraiment" );
	std::cout << "f name changed: " << f.getName() << std::endl;
	e.attack( f.getName() );
	f.takeDamage( f.getAttackDamage() );
	f.beRepaired( 10 );
	e.highFivesGuys();
	return 0;
}
