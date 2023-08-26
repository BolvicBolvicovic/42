/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printlastlines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 11:28:22 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/25 11:44:07 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	printlastlines(int argc, char **argv)
{
	int		i;
	int		fd;
	char	*tab;
	ssize_t	bytes_read;

	i = 0;
	while (++i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			write(2, "Cannot read file.\n", 18);
			return (1);
		}
		while (1)
		{
			bytes_read = read(fd, tab, sizeof(tab);
			if (bytes_read <= 0)
				break ;
			write(1, tab, bytes_read);
		}
		close(fd);
	}
	return (0);	
}
