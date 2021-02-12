/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 12:24:48 by dmilan            #+#    #+#             */
/*   Updated: 2021/02/12 10:14:00 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
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

t_env_item				*ft_env_item_new(char *key, char *value);
t_env_list				*ft_env_list_new(t_env_item *env_item);
void					ft_env_list_add_back(t_env_list **env_list,
												t_env_list *new);
void					ft_env_list_print(t_env_list *env_list);
void					ft_env_list_print_with_declare(t_env_list *env_list);
char					*ft_env_list_get_value(t_env_list *env_list, char *key);

typedef struct			s_vars
{
	t_env_list			*env_list;
	char				*raw_string;
	char				**envp;
}						t_vars;

/*
**	Built_IN
*/
int						ft_pwd();
int						ft_cd(const char *new_path);
void					ft_env(t_env_list *env_list);
void					ft_export(char *key, char *value,
									t_env_list **env_list);

#endif
