/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:16:25 by vcornill          #+#    #+#             */
/*   Updated: 2023/10/17 15:39:22 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		start;
	int		end;

	if (!s1 || !set)
		return (0);
	start = 0;
	while (s1[start] && strchr(set, s1[start]))
		start++;
	end = strlen(s1) - 1;
	while (end >= 0 && strchr(set, s1[end]))
        	end--;
	if (end - start + 1 <= 0)
	{
		*trimmed = (char *)malloc(1);
		if (trimmed)
			trimmed[0] = '\0';
		return (trimmed);
	}
	trimmed = (char *)malloc(end - start + 2);
	if (!trimmed)
		return (0);
	ft_strncpy(trimmed, s1 + start, end - start +1);
	trimmed[trimmed_length] = '\0';
	return (trimmed);
}
