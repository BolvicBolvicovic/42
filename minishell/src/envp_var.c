#include "mini.h"

char	*transform_value(char *str, int *i, char **envp, char *var)
{
	int		l;
	int		k;
	int		j;
	char	*value;
	char	*new_str;

	j = -1;
	while (envp[++j])
	{
		if (ft_strnstr(envp[j], var, ft_strlen(var)))
		{
			value = ft_calloc(1, ft_strlen(envp[j]) - ft_strlen(var));
			k = 0;
			while (envp[j][k] && envp[j][k] != '=')
				k++;
			l = 0;
			while (envp[j][++k])
				value[l++] = envp[j][k];
			value[l] = '\0';
			break ;
		}
	}
	new_str = ft_calloc(1, ft_strlen(str) + ft_strlen(value) - ft_strlen(var));
	j = -1;
	l = 0;
	while (++j < *i)
		new_str[j] = str[l++];
	k = -1;
	while (value[++k])
		new_str[j++] = value[k];
	l = l + ft_strlen(var) + 1;
	while (str[++l])
		new_str[j++] = str[l];
	free(str);
	*i = *i + j;
	return (new_str);
}

int	is_envp(char *str, char **envp, char **variable)
{
	int	i;
	char	*var;

	i = 1;
	while (str[i] && ft_isalnum(str[i]))
		i++;
	var = ft_calloc(1, i);
	i = 1;
	while (str[i] && ft_isalnum(str[i]))
	{
		var[i - 1] = str[i];
		i++;
	}
	while (envp[++i])
	{
		if (ft_strnstr(envp[i], var, ft_strlen(var)))
		{
			*variable = var;
			return (1);
		}
	}
	free(var);
	return (0);
}

void	handle_envp_var(char **str, char **envp)
{
	int	i;
	char	*var;
	i = -1;
	while ((*str)[++i])
	{
		var = NULL;
		if ((*str)[i] == '$')
		{
			if (is_envp((*str) + i, envp, &var))
				*str = transform_value(*str, &i, envp, var); 
		}
		free(var);
	}
}

void	add_envp_var(token **t_argv, char **envp)
{
	token	*node;

	node = *t_argv;
	while (node)
	{
		if (node->type == T_WORD && !node->s_quote_flag)
			handle_envp_var(&node->value, envp);
		node = node->next;
	}
}
