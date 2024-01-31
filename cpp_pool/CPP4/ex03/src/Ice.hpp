/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:44:01 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/26 10:44:22 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

class Ice: public AMateria
{
public:
	Ice();
	Ice( Cure &cure );
	~Ice();

	void		use( ICharacter &target );
	AMateria	*clone() const;
};
