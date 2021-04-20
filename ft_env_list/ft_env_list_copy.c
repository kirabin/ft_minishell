#include "minishell.h"

t_env_list	*ft_env_list_copy(t_env_list *list)
{
	t_env_list	*copy_list;
	t_env_item	*item;
	t_env_list	*node;

	copy_list = NULL;
	while (list)
	{
		item = ft_env_item_new(list->item->key, list->item->identifier,
				list->item->value);
		node = ft_env_list_new(item);
		ft_env_list_add_back(&copy_list, node);
		list = list->next;
	}
	return (copy_list);
}
