/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 09:44:47 by dmilan            #+#    #+#             */
/*   Updated: 2021/02/12 08:28:28 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

int		ft_pwd();
int		ft_cd(const char *new_path);
int		ft_env(char **envp);
int		ft_env_declare(char **envp);


#endif