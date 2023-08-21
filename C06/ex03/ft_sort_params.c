/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:41:34 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/17 11:43:52 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == 0)
			return (0);
		i++;
	}
	if (s1[i] < s2[i])
		return (-1);
	else
		return (1);
}

int	main(int argc, char **argv)
{
	char	*temp;
	int		comp;

	argc = 0;
	while (argv[++argc])
	{
		if (!argv[argc + 1])
			break ;
		comp = ft_strcmp(argv[argc], argv[argc + 1]);
		if (comp > 0)
		{
			temp = argv[argc];
			argv[argc] = argv[argc + 1];
			argv[argc + 1] = temp;
			argc = 0;
		}
	}
	argc = 0;
	while (argv[++argc])
		ft_putstr(argv[argc]);
	return (0);
}
