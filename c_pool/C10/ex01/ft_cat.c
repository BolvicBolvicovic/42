/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <vcornill@student.42.fr>              +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:50:53 by vcornill            #+#    #+#           */
/*   Updated: 2023/08/25 11:19:14 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	ft_cat(int argc, char **argv)
{
	int		i;
	char	tab[240000];
	int		fd;
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
			bytes_read = read(fd, tab, sizeof(tab));
			if (bytes_read <= 0)
				break ;
			write(1, tab, bytes_read);
		}
		close(fd);
		write(1, "\n", 1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		write(2, "File name missing\n", 20);
		return (1);
	}
	if (ft_cat(argc, argv))
		return (1);
	return (0);
}
