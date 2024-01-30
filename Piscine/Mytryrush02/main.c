/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:37:33 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/26 12:34:31 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mixlib.h" 

int	main(int argc, char **argv)
{
	if (argc == 2)
		if()
			return (1);
	else if (argc == 3)
		if (newdict(argc, argv))
			return (1);
	else
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
