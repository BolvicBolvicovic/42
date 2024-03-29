/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:26:24 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/25 11:58:22 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap a( "SeX" ); ClapTrap b( a );
	std::cout << "b name: " << b.getName() << std::endl;
	b.setName( "BonK" );
	std::cout << "b name changed: " << b.getName() << std::endl;
	a.attack( b.getName() );
	b.takeDamage( a.getAttackDamage() );
	b.beRepaired( 5 );
	return 0;
}
