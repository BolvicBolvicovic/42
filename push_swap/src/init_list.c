//mets un header

#include "push_swap.h"

void	init_stack(char **argv, t_node **node, int new_av_flag)
{
	int	i;
	t_node	*headnode;
	t_node	*new_node;

	i = -1;
	while (argv[++i])
	{
		new_node = ft_calloc(sizeof(t_node), 1);
		new_node->num = ft_atoi(argv[i]);
		if (node == NULL)
		{
			new_node->next = NULL;
			new_node->previous = NULL;
			*node = new_node;
			headnode = *node;
		}
		else
		{
			new_node->next = NULL;
			*node->next = new_node;
			new_node->previous = *node;
		}
	}
	if (new_av_flag)
		ft_free_matrix(argv);
	*node = headnode;
}

