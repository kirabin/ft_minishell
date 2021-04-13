/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:37:42 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/13 08:28:21 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *s, char delimiter)
{
	int		counter;

	counter = 0;
	while (*s)
	{
		while (*s && *s == delimiter)
			s++;
		counter++;
		if (*s == '\0')
			counter--;
		while (*s && *s != delimiter)
			s++;
	}
	return (counter);
}

static char	*get_next_word(const char *s, char delimiter)
{
	char	*word;
	int		len;
	int		i;
	int		j;

	i = 0;
	len = 0;
	while (s[i] && s[i] == delimiter)
		i++;
	while (s[i + len] && s[i + len] != delimiter)
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (j < len)
	{
		word[j] = s[i + j];
		j++;
	}
	word[len] = '\0';
	return (word);
}

static int	skip_delimiters(const char *s, char delimiter)
{
	int		i;

	i = 0;
	while (s[i] && s[i] == delimiter)
		i++;
	return (i);
}

static void	free_array(char **array, int len)
{
	int		i;

	i = 0;
	while (i < len)
		if (array + i && array[i])
			free(array[i]);
	free(array);
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	char	*word;
	int		array_len;
	int		i;

	if (!s)
		return (NULL);
	array_len = count_words((char *)s, c);
	array = malloc(sizeof(char *) * (array_len + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (i < array_len)
	{
		word = get_next_word(s, c);
		if (!word)
		{
			free_array(array, i);
			return (NULL);
		}
		array[i++] = word;
		s += skip_delimiters(s, c) + ft_strlen(word);
	}
	array[array_len] = NULL;
	return (array);
}
