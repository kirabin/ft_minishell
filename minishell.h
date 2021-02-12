/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 12:24:48 by dmilan            #+#    #+#             */
/*   Updated: 2021/02/12 09:08:26 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include "built_in/built_in.h"
# include "support_functions/support_functions.h"
# include <unistd.h>
# include <sys/errno.h>
# include <stdlib.h>
# include <string.h>

/*
**  ft_env_list
*/
typedef struct			s_env_item
{
	char				*key;
	char				*value;
}						t_env_item;

typedef struct			s_env_list
{
	t_env_item			*item;
	struct s_env_list	*next;
}						t_env_list;

t_env_list				*ft_env_list_new(t_env_item *env_item);
void					ft_env_list_add_back(t_env_list **env_list,
												t_env_list *new);


typedef struct			s_vars
{
	t_env_list			*env_list;
	char				*raw_string;
	char				**envp;
}						t_vars;

#endif