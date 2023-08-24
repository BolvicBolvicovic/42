/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <vcornill@student.42.fr>              +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:50:53 by vcornill            #+#    #+#           */
/*   Updated: 2023/08/24 21:50:53 by vcornill           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	ft_cat(int argc, char **argv)
{
	int	i;
	char	tab[240000];
	int	fd[240000];
	ssize_t	bytes_read;

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
		write(1, "\n", 1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		write(2, "File name missing\n", 20);
		return (1);
	}
	if (ft_cat(argc, argv))
		return(1);
	return (0);
}