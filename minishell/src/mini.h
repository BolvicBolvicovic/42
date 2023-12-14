/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:13:56 by vcornill          #+#    #+#             */
/*   Updated: 2023/12/14 14:34:08 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"
# include "ft_printf.h"

typedef enum
{
	T_WORD,
	T_CMD,
	T_PIPE,
	T_REDIRECT_IN,
	T_REDIRECT_OUT,
}	token_type;

typedef struct
{
	token_type	type;
	char		*value;
}	token;

int	find_type(char *str);

#endif
