/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newdict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:07:49 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/26 13:27:52 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mixlib.h"

char	*getdict(int argc, char **argv, int *err)
{
	int		fd;
	char	*dict;
	ssize_t	bytes_read;
	
	dict = malloc(4096);
	if (dict == NULL)
	{
		*err = 1;
		return (NULL);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1 || !argv[1])
	{
		write(2, "Dict Error\n", 11);
		*err = 1;
		return (dict);
	}
	bytes_read = read(fd, dict, sizeof(dict))
	dict[bytes_read] = '\0';
	*err = 0;
	return (dict);
}

int	newdict(int argc, char **argv)
{
	int	err;
	char	*dict;	
	int	numlen;

	if (error(argc, argv))
		return (1);
	dict = getdict(argc, argv, &err);
	if (err || !argv[1])
	{
		write(2, "Dict error", 11);
		return (1);
	}
	numlen = ft_strlen(argv[2]);
	printnumber(argv[2], dict, numlen);
	return (0);
}	
