/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:45:56 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/08 12:37:09 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*read_extra(char **extra, char **line)
{
	char	*endl;
	char	*temp;

	endl = NULL;
	if (*extra)
	{
		endl = ft_strchr(*extra, '\n');
		if (endl)
		{
			*endl = '\0';
			*line = ft_strdup(*extra);
			temp = *extra;
			*extra = ft_strdup(++endl);
			free(temp);
		}
		else
		{
			*line = *extra;
			*extra = NULL;
		}
	}
	else
		*line = ft_strnew(0);
	return (endl);
}

static void	fill_extra(char *endl, char **extra, int fd)
{
	*endl = '\0';
	extra[fd] = ft_strdup(++endl);
}

static int	free_and_get_minus_1(void *ptr)
{
	free(ptr);
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	static char		*extra[1024];
	char			*endl;
	char			*buff;
	int				bytes_were_read;

	buff = malloc(BUFFER_SIZE + 1);
	if (!line || fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || !buff)
		return (free_and_get_minus_1(buff));
	endl = read_extra(extra + fd, line);
	bytes_were_read = -1;
	while (!endl)
	{
		bytes_were_read = read(fd, buff, BUFFER_SIZE);
		if (!bytes_were_read)
			break ;
		if (bytes_were_read == -1)
			return (free_and_get_minus_1(buff));
		buff[bytes_were_read] = '\0';
		endl = ft_strchr(buff, '\n');
		if (endl)
			fill_extra(endl, extra, fd);
		*line = ft_strjoin_free(*line, buff);
	}
	free(buff);
	return (bytes_were_read || ft_strlen(*line));
}
