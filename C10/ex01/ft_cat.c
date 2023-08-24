/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <vcornill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:50:53 by marvin            #+#    #+#             */
/*   Updated: 2023/08/24 21:50:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	char	tab[240000];
	int	*fd;
	ssize_t	bytes_read;
	int	i;

	if (argc == 1)
	{
		write(2, "File name missing\n", 20);
		return (1);
	}
	fd = malloc(sizeof(int) * (argc - 1));
	i = 0;
	while (++i < argc)
	{
		fd[i - 1] = open(argv[i], O_RDONLY);
		if (fd[i - 1] == -1)
		{
			write(2, "Cannot read file.\n", 18);
			return (1);
		}
	}
	i = 0;
	while (++i < argc)
	{
		while ((bytes_read = read(fd[i - 1], tab, sizeof(tab))) > 0)
			write(1, tab, bytes_read);
		close(fd[i - 1]);
	}
	free(fd);
	return (0);
}