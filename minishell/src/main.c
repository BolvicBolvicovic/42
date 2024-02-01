/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:01:55 by acasamit          #+#    #+#             */
/*   Updated: 2024/02/01 11:16:15 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	g_status;

void	check_redirect(t_oken **token_list)
{
	t_oken	*tmp;

	tmp = *token_list;
	while (tmp)
	{
		if (tmp->value[0] == '<'
			&& !(!tmp->value[1] || (tmp->value[1] == '<' && !tmp->value[2])))
			tmp->type = T_ERROR;
		if (tmp->value[0] == '>'
			&& !(!tmp->value[1] || (tmp->value[1] == '>' && !tmp->value[2])))
			tmp->type = T_ERROR;
		tmp = tmp->next;
	}
}

void	free_tokens(t_oken *list)
{
	t_oken	*tmp;

	while (list)
	{
		tmp = list->next;
		if (list->value)
			free(list->value);
		if (list->path)
			free(list->path);
		free(list);
		list = tmp;
	}
}

void	free_token(t_oken **list)
{
	t_oken	*tmp;

	tmp = (*list)->next;
	free((*list)->value);
	free((*list)->path);
	free((*list));
	*list = tmp;
}

t_oken	*parsing(char **envp)
{
	t_oken	*t_argv;
	char	*input;

	t_argv = NULL;
	input = readline("➜ MiniFeur$ ");
	if (input && ft_strlen(input) > 0)
	{
		add_history(input);
		t_argv = tokenize(input, envp);
		add_flags(&t_argv);
		check_redirect(&t_argv);
		join_string(&t_argv, envp);
		if (t_argv->type == T_S_QUOTE
			|| t_argv->type == T_D_QUOTE || t_argv->type == T_SPACE)
			free_token(&t_argv);
		if (!t_argv)
			add_token(&t_argv, 1, 0, "");
		free(input);
	}
	else if (input)
		add_token(&t_argv, 1, 0, "");
	return (t_argv);
}

int	main(int argc, char **argv, char **envp)
{
	t_oken	*t_argv;
	char	*cpy;
	t_env	env;
	int		i;

	i = -1;
	t_argv = NULL;
	cpy = NULL;
	env.env_cpy = copy_string_array(envp);
	sig_init();
	(void)argc;
	(void)argv;
	printf("\033c\033]0;MiniFeur\a");
	while (envp[++i])
	{
		if (ft_strncmp(env.env_cpy[i], "PATH=", 5) == 0)
		{
			cpy = envp[i] + 5;
			break ;
		}
	}
	do_main_loop(&env, t_argv, cpy);
	free_tab(env.env_cpy);
	return (0);
}
