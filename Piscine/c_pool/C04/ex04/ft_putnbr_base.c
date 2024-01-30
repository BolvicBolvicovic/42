/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:16:06 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/16 10:21:27 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_valid_base(char *base)
{
	int	i;

	if (!base || base[0] == '\0' || base[1] == '\0')
		return (0);
	i = -1;
	while (base[++i])
		if (base[i] == '+' || base[i] == '-' || base[i] == base[i + 1])
			return (0);
	return (1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base_recursive(long int nbr, char *base, int base_len)
{
	if (nbr == 0)
		ft_putchar('0')
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= base_len)
		ft_putnbr_base_recursive(nbr / base_len, base, base_len);
	ft_putchar(base[nbr % base_len]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	base_len;
	long int	mynum;

	mynum = nbr;
	if (!is_valid_base(base))
		return ;
	base_len = ft_strlen(base);
	ft_putnbr_base_recursive(mynum, base, base_len);
}
