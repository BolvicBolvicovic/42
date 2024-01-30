/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:28:45 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/26 14:03:47 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mixlib.h"

char	*cutnum(char n, int nindex, int numlen, char *numcut)
{
	
}

char	*getline(char *num, char *dict)
{

}

void	printnumber(char *num, char *dict, int numlen)
{
	char	*numcut;
	char	*line;
	int	i;
	
	i = -1;
	while (num[++i])
	{
		numcut = cutnum(num[i], i, numlen, numcut);
		line = getline(numcut, dict);
		ft_putstr(line);
		free(numcut);
		free(line);
	}
}
