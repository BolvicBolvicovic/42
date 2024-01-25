/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:06:18 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/25 12:19:17 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class	ClapTrap
{
protected :
	std::string	name;
	int		health;
	int		energy;
	int		attackDamage;
public:
	ClapTrap( std::string Name );
	ClapTrap( ClapTrap &copy );
	~ClapTrap();

	ClapTrap	&operator=( ClapTrap &ct );
	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);

	std::string	getName( void );
	int		getHealth( void );
	int		getEnergy( void );
	int		getAttackDamage( void );

	void		setName( std::string str );
	void		setHealth( int nb );
	void		setEnergy( int nb );
	void		setAttackDamage( int nb );
};

#endif
