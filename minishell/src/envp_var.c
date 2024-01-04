#include "mini.h"

void	add_var()
{

}

void	create_list_var(t_var_envp *list_var, char *str, char **envp)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		
	}
}

void	add_envp_var(token **t_argv, char **envp)
{
	token	*node;

	node = *t_argv;
	while (node)
	{
		if (node->type == T_WORD && !s_quote_flag)
			create_list_var(node->envp, node->value, envp);
		node = node->next;
	}
}
