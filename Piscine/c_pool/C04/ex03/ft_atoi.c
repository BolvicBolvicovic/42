/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:12:12 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/16 10:15:16 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*isminus(char *str, int *ismin)
{
	int	count;

	count = 0;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			count++;
		str++;
	}
	*ismin = count % 2; 
	return (str);
}

int	ft_atoi(char *str)
{
	int	ismin;
	int	num;
	int	ws0;
	int	ws1;

	ws0 = (*str == ' ' || *str == '\n' || *str == '\t');
	ws1 = (*str == '\v' || *str == '\f' || *str == '\r');
	num = 0;
	while (ws0 || ws1)
	{
		str++;
		ws0 = (*str == ' ' || *str == '\n' || *str == '\t');
		ws1 = (*str == '\v' || *str == '\f' || *str == '\r');
	}
	str = isminus(str, &ismin);
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (ismin)
		num = -num;
	return (num);
}
