/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:45:56 by dmilan            #+#    #+#             */
/*   Updated: 2020/12/07 16:40:19 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_extra(char **extra, char **line)
{
	char	*endl;
	char	*temp;

	endl = NULL;
	if (*extra)
	{
		if ((endl = ft_strchr(*extra, '\n')))
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

void		fill_extra(char *endl, char **extra, int fd)
{
	*endl = '\0';
	extra[fd] = ft_strdup(++endl);
}

int			get_next_line(int fd, char **line)
{
	static char		*extra[1024];
	char			*endl;
	char			*buff;
	int				bytes_were_read;

	if (!line || fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 ||
		!(buff = malloc(BUFFER_SIZE + 1)))
		return (-1);
	endl = read_extra(extra + fd, line);
	bytes_were_read = -1;
	while (!endl && (bytes_were_read = read(fd, buff, BUFFER_SIZE)))
	{
		if (bytes_were_read == -1)
		{
			free(buff);
			return (-1);
		}
		buff[bytes_were_read] = '\0';
		if ((endl = ft_strchr(buff, '\n')))
			fill_extra(endl, extra, fd);
		*line = ft_strjoinfree(*line, buff);
	}
	free(buff);
	return (bytes_were_read || ft_strlen(*line));
}
