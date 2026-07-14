/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucferre <lucferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 03:07:55 by lucferre          #+#    #+#             */
/*   Updated: 2026/07/13 22:11:25 by lucferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	line_end(char *acc)
{
	size_t	i;

	if (!acc)
		return (0);
	i = 0;
	while (acc[i] != '\0')
	{
		if (acc[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static size_t	str_len(const char *s)
{
	size_t	c;

	if (!s)
		return (0);
	c = 0;
	while (s[c] != '\0')
		c++;
	return (c);
}

char	*str_join(char *acc, char *buffer)
{
	size_t	len1;
	char	*s3;
	size_t	i;

	len1 = str_len(acc);
	s3 = malloc(((len1 + str_len(buffer)) * sizeof(char)) + 1);
	if (!s3)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		s3[i] = acc[i];
		i++;
	}
	if (acc)
		free(acc);
	i = 0;
	while (i < str_len(buffer))
	{
		s3[i + len1] = buffer[i];
		i++;
	}
	s3[len1 + str_len(buffer)] = '\0';
	return (s3);
}

char	*read_line(char *acc)
{
	char	*line;
	int		c;
	int		i;

	c = 0;
	while (acc[c] != '\n' && acc[c] != '\0')
		c++;
	if (acc[c] == '\n')
		c++;
	line = malloc((c + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (i < c)
	{
		line[i] = acc[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*extract_line(char *acc, char *line)
{
	size_t	l;
	size_t	total;
	size_t	c;
	char	*new_acc;

	l = str_len(line);
	total = str_len(acc);
	if (total <= l)
		return (free(acc), NULL);
	new_acc = malloc(((total - l) + 1) * sizeof(char));
	if (!new_acc)
	{
		free(acc);
		return (NULL);
	}
	c = 0;
	while (c + l < total)
	{
		new_acc[c] = acc[c + l];
		c++;
	}
	free(acc);
	new_acc[c] = '\0';
	return (new_acc);
}
