/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_functions.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 15:15:44 by dmilan            #+#    #+#             */
/*   Updated: 2021/02/10 10:05:45 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPPORT_FUNCTIONS_H
# define SUPPORT_FUNCTIONS_H

char		*get_env_value(char **envp, char *key);
char		**get_env_path_value(char **envp);

#endif