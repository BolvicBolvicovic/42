/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:09:10 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/09 15:09:18 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_comb2(void);
void	buffer0(int n0, int n1);
void	buffer1(void);
void	ft_putchar(char c);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	n0;
	int	n1;

	n0 = 0;
	while (n0 <= 98)
	{
		n1 = n0 + 1;
		while (n1 <= 99)
		{
			if (!(n0 == 98 && n1 == 99))
			{
				buffer0(n0, n1);
			}
			else
			{
				buffer1();
				return ;
			}
			n1++;
		}
		n0++;
	}
}

void	buffer0(int n0, int n1)
{
	ft_putchar(n0 / 10 + '0');
	ft_putchar(n0 % 10 + '0');
	ft_putchar(' ');
	ft_putchar(n1 / 10 + '0');
	ft_putchar(n1 % 10 + '0');
	ft_putchar(',');
	ft_putchar(' ');
}

void	buffer1(void)
{
	char	buffer[5];

	buffer[0] = '9';
	buffer[1] = '8';
	buffer[2] = ' ';
	buffer[3] = '9';
	buffer[4] = '9';
	write(1, buffer, 5);
}
