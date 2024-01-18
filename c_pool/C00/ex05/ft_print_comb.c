/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C00.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:22:35 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/09 12:22:50 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);
void	newwrite(int i, int j, int k);
void	elsewrite(int i, int j, int k);
void	ifstatement(int i, int j, int k);

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i <= 7)
	{
		j = i + 1;
		while (j <= 8)
		{
			k = j + 1;
			while (k <= 9)
			{
				ifstatement(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}

void	ifstatement(int i, int j, int k)
{
	if (!(i == 7 && j == 8 && k == 9))
	{
		newwrite(i, j, k);
	}
	else
	{
		elsewrite(i, j, k);
		return ;
	}
}

void	newwrite(int i, int j, int k)
{
	char	buffer[5];

	buffer[0] = '0' + i;
	buffer[1] = '0' + j;
	buffer[2] = '0' + k;
	buffer[3] = ',';
	buffer[4] = ' ';
	write(STDOUT_FILENO, buffer, 5);
}

void	elsewrite(int i, int j, int k)
{
	char	buffer[3];

	buffer[0] = '0' + i;
	buffer[1] = '0' + j;
	buffer[2] = '0' + k;
	write(STDOUT_FILENO, buffer, 3);
}
