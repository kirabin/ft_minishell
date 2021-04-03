/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 12:24:48 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/03 10:49:33 by msamual          ###   ########.fr       */
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
# include <term.h>

# define PROMPT "write here your fckin text>>> "


/*
**  ft_env_list
*/

typedef struct			s_history
{
	char				com[1000];
	struct s_history	*next;
	struct s_history	*prev;	
}						t_history;

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
	int					pipein;
	int					pipeout;
}						t_command;


typedef struct			s_vars
{
	t_env_list			*env_list;
	t_history			*history;
	char				*raw_input;
	int					end;
	struct termios		term_orig_attr;
	struct termios		term;
	char				*term_name;
	int					cursor_pos;
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
int					parse_command(char **cur_ptr, char **buf, t_command *com, t_vars *vars);
int						pipe_hdl(t_command *com, char **cur_ptr);
void					read_input(t_vars *vars);
int						is_separator(char c);
void					print_tab(t_command *com);

void					init_history(t_vars *vars);
void					push_to_command_history(t_vars *vars, char *command);
void					print_history(t_history *cur);
void					remove_current_input(t_history *history);
void					remove_elem_hist(t_history **history);
void					init_history(t_vars *vars);
void					write_history(t_vars *vars);
void					ctrl_d(t_vars *vars);

int						unexpected_token(char *token);
int						puterror(char *err_msg, int code);

void					execute(t_vars *vars, t_command *com);

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
