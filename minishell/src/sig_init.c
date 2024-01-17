/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:49:01 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/17 17:09:47 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

extern int g_status;

void	ft_raise_error(char *error)
{
	g_status = 1;
	printf("Error: %s\n", error);
}

int	is_exec(int value)
{
	static int	is_exec = 0;

	if (value >= 0)
		is_exec = value;
	return (is_exec);
}

void	sig_int(int signum)
{
	if (signum == SIGINT)
	{
		g_status = 130;
		rl_replace_line("", 0);
		printf("\n");
		rl_on_new_line();
		if (!is_exec(-1))
			rl_redisplay();
	}
}

void	sig_init(void)
{
	signal(SIGINT, &sig_int);
	signal(SIGQUIT, SIG_IGN);
}
