/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 10:07:26 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/25 11:28:16 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	printnumbytes(int argc, char **argv);
int	printlastlines(int argc, char **argv);

int	errorargmissing(int argc, char **argv)
{
	if (argv[1] == "-c" && argv == 2)
	{	
		write(2, "File name missing\n", 20);
		return (1);	
	}
	else if (argc == 1)
	{
		write(2, "File name missing\n", 20);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	*tab;
	ssize_t	bytes_read;


	if (errorargmissing(argc, argv))
		return (1);

	if (argv[1] == "-c")
		if (printnumbytes(argc, argv))
			return (1);
	else
		if (printlastlines(argc, argv))
			return (1);
	return (0);
}
