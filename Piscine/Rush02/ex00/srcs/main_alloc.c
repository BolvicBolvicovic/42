/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <vcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:27:25 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/27 13:14:44 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ourlib.h"

char	**populate(char *avnum, char **newnum, int avlen, int slot_one)
{
	int	i;
	int	j;
	int	avnum_i;

	avnum_i = 0;
	i = 0;
	while (i < (avlen / 3) + slot_one)
	{
		j = 0;
		while (1)
		{
			if (j == 3)
			{
				newnum[i++][j] = '\0';
				break ;
			}
			if (i == 0 && j == 0 && (avlen % 3 == 2))
				newnum[i][j++] = '0';
			while (i == 0 && (avlen % 3 == 1) && j <= 1)
				newnum[i][j++] = '0';
			newnum[i][j++] = avnum[avnum_i++];
		}
	}
	return (newnum);
}

char	**allocnum(char *avnum)
{
	int		len;
	int		i;
	int		slot_one;
	char	**newnum;

	i = -1;
	len = ft_strlen(avnum);
	slot_one = modthree(avnum);
	newnum = (char **)malloc((len / 3 + slot_one) * sizeof(char *));
	if (!newnum)
		puterror("Allocation Memory Error");
	while (++i < (len / 3) + slot_one)
	{
		newnum[i] = (char *)malloc(4);
		if (!newnum[i])
		{
			puterror("Allocation Memory Error");
			return (0);
		}
	}
	newnum = populate(avnum, newnum, len, slot_one);
	return (newnum);
}
