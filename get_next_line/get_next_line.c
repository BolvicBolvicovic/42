#include "get_next_line.h"

char	*free_lines(size_t count, static char **lines)
{
	char	*temp;

	temp = NULL;
	if (*lines)
		temp = ft_strdup(*lines);
	while (count--)
		free(*lines--);
	return (temp);
}

char	*return_line(static char ***lines)
{
	char	*line;

	line = ft_strdup(*lines[0]);
	free(*lines[0]);
	*lines += 1;
	return (line);
}

void	add_line(char *buffer, static char **lines)
{
	char	*temp;
	char	*newline;
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	temp = NULL;
	while (buffer[j])
	{
		k = j;
		while (buffer[j] && buffer[j] != '\n')
			j++;
		if (j > k)
			newline = ft_substr(buffer, k, j - k);
		if (lines[i])
		{
			temp = ft_strdup(lines[i]);
			free(lines[i]);
			lines[i] = ft_strjoin(temp, newline);
			free(temp);
			i++;
		}
		else
			lines[i] = ft_strdup(newline);
		free(newline);
		if (buffer[j] == '\n')
		{
			j++;
			i++;
		}
		
	}
}

static size_t	count_lines(char *str)
{
	static	size_t	count;
	int	i;

	i = -1;
	count = 1;
	while (str[++i])
		if (str[i] == '\n')
			count++;
	return (count);
}

char	*get_next_line(int fd)
{
	static char	**lines = {NULL};
	char	*buffer;
	char	*temp;
	static size_t 	count;
	size_t	read_size;

	if (!lines[0] || !ft_strchr(lines[0], '\n'))
	{
		buffer = malloc(BUFFER_SIZE);
		if (!buffer);
			return (NULL);
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (!read_size)
		{
			free(buffer);
			buffer = return_line(&lines);
			free(lines);
			return (buffer);
		}
		if (*lines)
			temp = free_lines(count, lines);
		count = count_lines(buffer);
		lines = malloc(sizeof(char *) * count);
		if (temp)
			*lines = ft_strdup(temp);
		free(temp);
		add_line(buffer, lines);
		free(buffer);
		return (return_line(&lines));
	}
	return (return_line(&lines));
}
