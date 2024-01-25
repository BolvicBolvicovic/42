/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:06:25 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/25 12:33:58 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap( std::string Name );
	ScavTrap( ScavTrap  &copy );
	~ScavTrap();

	void	attack( std::string target );
	void	guardGate( void );
};
