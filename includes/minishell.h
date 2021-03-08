/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 12:24:48 by dmilan            #+#    #+#             */
/*   Updated: 2021/03/08 15:11:26 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"
# include <unistd.h>
# include <sys/errno.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>

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

typedef struct			s_command
{
	char				**com;
	int					pipe;
}						t_command;


typedef struct			s_vars
{
	t_env_list			*env_list;
	char				*raw_input;
	int					end;
}						t_vars;

# define BUFF_SIZE 999

t_env_item				*ft_env_item_new(char *key, char *value);
t_env_list				*ft_env_list_new(t_env_item *env_item);
void					ft_env_list_add_back(t_env_list **env_list,
												t_env_list *new);
void					ft_env_list_print(t_env_list *env_list);
void					ft_env_list_print_with_declare(t_env_list *env_list);
char					*ft_env_list_get_value(t_env_list *env_list, char *key);
bool					ft_env_key_exists(t_env_list *list, char *key);
t_env_item				*ft_env_item_new(char *key, char *value);
void					ft_env_list_replace(t_env_list *list, char *key,
												char *new_value);
void					ft_env_item_del(t_env_item *item);
void					ft_env_list_remove(t_env_list **list, char *key);
int						ft_env_list_len(t_env_list *env_list);
t_env_list				*convert_envp_to_list(char **envp);
char					**ft_env_to_charpp(t_env_list *list);
void					ft_env_list_clear(t_env_list **lst);
void					parse_row_string(t_vars *vars);
void					replacement(t_vars *vars);
void						parse_command(char **cur_ptr, char **buf, t_command *com, t_vars *vars);

/*
**	Built_IN
*/
int						ft_pwd();
void					ft_unset(t_env_list **list, char *key);
int						ft_cd(const char *new_path);
void					ft_env(t_env_list *env_list);
void					ft_export(char *key, char *value,
									t_env_list **env_list);

#endif
