/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:26:24 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/24 16:20:05 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap a; ClapTrap( a ) b;
	a.attack( b.getName() );
	b.takeDamage( a.getAttackDamage() );
	b.beRepaired( 5 );
	return 0;
}
