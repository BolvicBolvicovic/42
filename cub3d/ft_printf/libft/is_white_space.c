/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_white_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:18:32 by vcornill          #+#    #+#             */
/*   Updated: 2023/12/15 11:38:33 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_white_space(char c)
{
	return (c == ' ' || (c >= '\r' && c <= '\t'));
}