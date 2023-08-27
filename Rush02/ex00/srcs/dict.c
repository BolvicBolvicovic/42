/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <vcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:27:04 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/27 12:53:27 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ourlib.h"

char	*read_dict(char *dictionary)
{
	int		fd;
	char	*buf;

	buf = (char *)malloc(4096);
	fd = open(dictionary, O_RDONLY);
	if (fd == -1)
	{
		puterror("Read error\n");
		return (0);
	}
	read(fd, buf, 1000);
	close(fd);
	return (buf);
}

int	count_rows(char *buf)
{
	int		j;
	int		rows;

	j = -1;
	rows = 0;
	while (buf[++j])
		if (buf[j] == '\n')
			rows++;
	return (rows);
}

char	**alloc_array(char *buf)
{
	char	**array;
	int		i;
	int		j;
	int		counter;

	i = -1;
	j = -1;
	array = (char **)malloc(count_rows(buf) * sizeof(char *));
	while (++i < count_rows(buf))
	{
		counter = 0;
		while (buf[++j] != '\n')
			counter++;
		j++;
		array[i] = (char *)malloc((counter + 1));
	}
	return (array);
}

char	**copy_dict(char *dictionary)
{
	int		i;
	int		j;
	int		k;
	char	*buf;
	char	**array;

	buf = ft_strdup(read_dict(dictionary));
	i = -1;
	j = 0;
	array = alloc_array(buf);
	while (++i < count_rows(buf))
	{
		k = 0;
		while (buf[j] != '\n')
			array[i][k++] = buf[j++];
		array[i][k] = '\0';
		j++;
	}
	free(buf);
	return (array);
}
