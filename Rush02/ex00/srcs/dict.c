
#include "ourlib.h"

int		ft_read_words(char *str)
{
	unsigned int	i;

	i = 0;
	if (!str[0])
		return (0);
	while (!(str[i] >= 'a' && str[i] <= 'z') ||
	(str[i] >= 'A' && str[i] <= 'Z'))
		i++;
	while ((str[i] >= 'a' && str[i] <= 'z') ||
	(str[i] >= 'A' && str[i] <= 'Z'))
	{
		write(1, &str[i], 1);
		i++;
	}
	return (0);
}

char	*ft_read_dict(char *dictionary)
{
	int		fd;
	char	*buf;

	buf = (char *)malloc(2000 * sizeof(char));
	fd = open(dictionary, O_RDONLY);
	if (fd == -1)
	{
		ft_puterror("Read error\n");
		return (0);
	}
	read(fd, buf, 1000);
	close(fd);
	return (buf);
}

int		ft_counter_rows(char *buf)
{
	int		j;
	int		rows;

	j = -1;
	rows = 0;
	while (buf[++j])
	{
		if (buf[j] == '\n')
			rows++;
	}
	return (rows);
}

char	**ft_alloc_array(char *buf)
{
	char	**array;
	int		i;
	int		j;
	int		counter;

	i = 0;
	j = -1;
	array = (char **)malloc(ft_counter_rows(buf) * sizeof(char *));
	while (i < ft_counter_rows(buf))
	{
		counter = 0;
		while (buf[++j] != '\n')
			counter++;
		j++;
		array[i++] = (char *)malloc((counter + 1) * sizeof(char));
	}
	return (array);
}

char	**ft_copy_dict_array(char *dictionary)
{
	int		i;
	int		j;
	int		k;
	char	*buf;
	char	**array;

	buf = ft_strdup(ft_read_dict(dictionary));
	i = -1;
	j = -1;
	array = ft_alloc_array(buf);
	while (++i < ft_counter_rows(buf))
	{
		k = -1;
		while (buf[++j] != '\n')
			array[i][++k] = buf[j];
		array[i][k] = '\0';
		j++;
	}
	free(buf);
	return (array);
}
