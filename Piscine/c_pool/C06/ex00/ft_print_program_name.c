/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:20:16 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/17 11:20:29 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		write(1, &src[i], 1);
}

int	main(int argc, char **argv)
{
	argc = 0;
	ft_putstr(argv[argc]);
	write(1, "\n", 1);
	return (0);
}
