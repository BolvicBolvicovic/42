/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:44:01 by vcornill          #+#    #+#             */
/*   Updated: 2024/02/02 12:12:17 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

class Ice: public AMateria
{
public:
	Ice();
	Ice( Ice &ice );
	~Ice();

	Ice		&operator=( Ice &ref );

	void		use( ICharacter &target );
	AMateria	*clone() const;
};
