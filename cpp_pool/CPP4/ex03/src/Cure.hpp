/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:44:06 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/26 10:44:22 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

class Cure: public AMateria
{
public:
	Cure();
	Cure( Cure &cure );
	~Cure();

	void		use( ICharacter &target );
	AMateria	*clone() const;
};
