/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:36:52 by vcornill          #+#    #+#             */
/*   Updated: 2023/12/14 13:48:11 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	find_type(char *str)
{
	if (ft_memcmp(str, "<", 1) == 0)
		return (T_REDIRECT_IN);
	else if (ft_memcmp(str, ">", 1) == 0)
		return (T_REDIRECT_OUT);
	else if (ft_memcmp(str, "|", 1) == 0)
		return (T_PIPE);
	else
		return (T_WORD);
}
