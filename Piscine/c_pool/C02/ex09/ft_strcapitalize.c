/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 10:00:35 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/12 10:12:56 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strcapitalize(char *str)
{
	int	i;
	int	cn;
	int	isnum;
	int	ismaj;
	int	ismin;

	i = 0;
	cn = 1;
	while (str[i])
	{
		if (cn && str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		else if (!cn && str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		isnum = (str[i] >= '0' && str[i] <= '9');
		ismaj = (str[i] >= 'A' && str[i] <= 'Z');
		ismin = (str[i] >= 'a' && str[i] <= 'z');
		if (ismin || ismaj || isnum)
			cn = 0;
		else
			cn = 1;
		i++;
	}
	return (str);
}
