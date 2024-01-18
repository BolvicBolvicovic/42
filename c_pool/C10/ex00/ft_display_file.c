/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:29:06 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/24 17:46:42 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	buffer[4096];
	ssize_t bytes_read;

	if (argc != 2)
	{
		if (argc < 2)
			write(2, "File name missing.\n", 20);
		else
			write(2, "Too many arguments.\n", 2);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(2, "Cannot read file.\n", 18);
		return (1);
	}
	while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
		write(1, buffer, bytes_read);
	close(fd);
	return (0);
}
