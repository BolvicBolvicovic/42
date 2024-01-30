/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <vcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:16:36 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/15 16:16:33 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	lowpoint;
	int	midpoint;
	int	result;
	int	highpoint;

	highpoint = nb;
	lowpoint = 1;
	if (nb < 0)
		return (0);
	if (nb <= 1)
		return (nb);
	while (lowpoint <= highpoint)
	{
		midpoint = lowpoint + (highpoint - lowpoint) / 2;
		if (midpoint <= nb / midpoint)
		{
			result = midpoint;
			lowpoint = midpoint + 1;
		}
		else
			highpoint = midpoint - 1;
	}
	if (result * result != nb)
		result = 0;
	return (result);
}
