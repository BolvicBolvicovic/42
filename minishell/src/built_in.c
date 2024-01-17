/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:40:48 by acasamit          #+#    #+#             */
/*   Updated: 2023/12/18 02:59:00 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	is_equal(const char *entry)
{
    int i = 0;

    while (entry[i])
    {
        if (entry[i] == '=')
            return 1;
        i++;
    }
    return 0;
}

void	echo_utils(char **arg_tab)
{
	int	j;

	j = 0;
	while (arg_tab[++j] && arg_tab[j + 1] != NULL)
	{
		printf("%s", arg_tab[j]);
		printf(" ");
	}
	if (arg_tab[j] && arg_tab[j + 1] == NULL)
		printf("%s\n", arg_tab[j]);
	return ;
}

void	ft_echo(char **arg_tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!arg_tab[1])
	{
		printf("\n");
		return ;
	}
	if (arg_tab[1][0] == '-')
	{
		while (arg_tab[1][++i])
		{
			if (arg_tab[1][i] != 'n')
				return (echo_utils(arg_tab));
		}
	}
	else
		return (echo_utils(arg_tab));
	j = 1;
	while (arg_tab[++j] && arg_tab[j + 1] != NULL)
	{
		printf("%s", arg_tab[j]);
		printf(" ");
	}
	if (arg_tab[j] && arg_tab[j + 1] == NULL)
		printf("%s", arg_tab[j]);
	return ;
}

void	ft_cd(char **arg_tab)
{
	if (chdir(arg_tab[1]) == -1)
		perror("");
}

void	ft_pwd(void)
{
	char	*path;

	path = malloc(PATH_MAX + 1);
	path = getcwd(path, PATH_MAX);
	printf("%s\n", path);
	free(path);
}

void	ft_env(t_env *envp, int is_export)
{
	int	i;

	i = -1;
	while (envp->env_cpy[++i])
	{
		if (!is_equal(envp->env_cpy[i]) && !is_export)
			continue ;
		if (is_export)
			printf("declare -x ");
		if (is_export && is_equal(envp->env_cpy[i]) && envp->env_cpy[i][strcspn(envp->env_cpy[i], "=") + 2] == '\0')
			printf("%s\"\"\n", envp->env_cpy[i]);
		else
			printf("%s\n", envp->env_cpy[i]);
	}
}

void	ft_unset(char **arg_tab, t_env *envp)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	if (arg_tab[1] == NULL)
	{
		printf("unset: not enough arguments\n");
		return ;
	}
	while (arg_tab[++i])
	{
		while (arg_tab[i][++j])
		{
			if (arg_tab[i][j] == '=' || arg_tab[i][j] == ':')
			{
				printf("unset: `%s': not a valid identifier\n", arg_tab[i]);
				return ;
			}
		}
		j = -1;
		while (envp->env_cpy[++j])
		{
			if (!ft_strncmp(arg_tab[i], envp->env_cpy[j], ft_strlen(arg_tab[i])))
			{
				while (envp->env_cpy[j])
				{
					envp->env_cpy[j] = envp->env_cpy[j + 1];
					j++;
				}
				free(envp->env_cpy[j]);
				break ;
			}
		}
	}
	j = -1;
}

size_t	var_exist(char	*full_name, char **envp)
{
	size_t		j;
	char	*var_name;
	size_t		i;

	i = -1;
	var_name = malloc(strcspn(full_name, "=") + 1);
	while (++i != strcspn(full_name, "="))
		var_name[i] = full_name[i];
	var_name[i] = '\0';

	j = -1;
	while (envp[++j])
	{
		if ((!ft_strncmp(var_name, envp[j], ft_strlen(var_name))) && envp[j][ft_strlen(var_name)] == '=')
		{
			return (j);
		}
	}
	return (-1);
}

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	**ft_realloc_tab(char **tab, int size)
{
	char	**new_tab;
	int		i;

	i = -1;
	new_tab = malloc((size + 1) * sizeof(char *));
	while (tab[++i])
		new_tab[i] = ft_strdup(tab[i]);
	new_tab[size - 1] = NULL;
	new_tab[size] = NULL;
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (new_tab);
}

char	*ft_realloc_string(char *str, int size)
{
	int		i;
	char	*new_str;

	i = -1;
	new_str = malloc(size);
	while (str[++i])
		new_str[i] = str[i];
	new_str[i] = '\0';
	free(str);
	return (new_str);
}

char	**ft_export(char **arg_tab, t_env *env)
{
	int	i;
	int	j;
	int	k;
	int	empty;
	int	equal;
	int	completed;

	i = 0;
	j = -1;
	empty = 1;
	equal = 0;
	completed = 0;
	if (!arg_tab[1])
	{
		while (env->env_cpy[++i])
			printf("declare -x %s\n", env->env_cpy[i]);
		return (env->env_cpy);
	}
	while (arg_tab[++i])
	{
		k = 0;
		while (arg_tab[i][++j])
		{
			if (arg_tab[i][j] == '=')
			{
				equal = 1;
				if (arg_tab[i][j + 1] != '\0')
					empty = 0;
			}
		}
		if (!equal)
		{
			arg_tab[i] = realloc(arg_tab[i], ft_strlen(arg_tab[i]) + 2);
			ft_strcat(arg_tab[i], "=");
		}
		j = 0;
		while (env->env_cpy[++j])
		{
			while (arg_tab[i][k] != '=')
				k++;
			if (!ft_strncmp(arg_tab[i], env->env_cpy[j], k + 1))
			{
				if (empty && equal)
				{
					free(env->env_cpy[j]);
					env->env_cpy[j] = malloc(ft_strlen(arg_tab[i]) + 2);
					env->env_cpy[j][0] = '\0';
					ft_strcat(env->env_cpy[j], arg_tab[i]);
					ft_strcat(env->env_cpy[j], "\"\"");
					completed = 1;
				}
				else
				{
					free(env->env_cpy[j]);
					env->env_cpy[j] = malloc(ft_strlen(arg_tab[i]) + 2);
					env->env_cpy[j][0] = '\0';
					ft_strcat(env->env_cpy[j], arg_tab[i]);
					completed = 1;
				}
			}
		}
		k = 0;
		if (!empty && !completed)
		{
			while (env->env_cpy[k])
				k++;
			env->env_cpy = ft_realloc_tab(env->env_cpy, k + 1);
			env->env_cpy[k] = ft_strdup(arg_tab[i]);
		}
		else if (empty && !completed)
		{
			while (env->env_cpy[k])
				k++;
			env->env_cpy = ft_realloc_tab(env->env_cpy, k + 1);
			env->env_cpy[k] = malloc(ft_strlen(arg_tab[i]) + 2);
			env->env_cpy[k][0] = '\0';
			ft_strcat(env->env_cpy[k], arg_tab[i]);
			ft_strcat(env->env_cpy[k], "\"\"");
			env->env_cpy[k + 1] = NULL;
		}
		completed = 0;
		empty = 1;
		equal = 0;
		j = -1;
	}
	return (env->env_cpy);
}

