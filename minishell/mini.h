/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:13:56 by vcornill          #+#    #+#             */
/*   Updated: 2023/12/13 18:33:08 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef enum
{
	T_WORD,
	T_PIPE,
	T_REDIRECT_IN,
	T_REDIRECT_OUT,
}	token_type;

typedef struct
{
	token_type	type;
	char		*value;
}

int		ft_strlen(char *str);
char	*ft_strjoin(int size, char **strs, char *sep);
int		ft_count_words(char const *s, char sep);

#endif
