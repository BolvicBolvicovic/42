/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:40:23 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/13 16:40:28 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strstr(char *str, char *to_find)
{
	char	*h;
	char	*current_h;
	char	*n;

	h = str;
	n = to_find;
	if (*to_find == '\0')
		return (str);
	while (*h)
	{
		current_h = h;
		while (*n && *current_h == *n)
		{
			current_h++;
			n++;
		}
		if (*n == '\0')
			return (h);
		h++;
		n = to_find;
	}
	return (0);
}
