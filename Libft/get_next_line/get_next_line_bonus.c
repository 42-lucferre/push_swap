/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucferre <lucferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 03:07:50 by lucferre          #+#    #+#             */
/*   Updated: 2026/07/13 22:10:56 by lucferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*get_next_line(int fd)
{
	char			*buffer;
	static char		*acc[4096];
	char			*line;
	ssize_t			bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer || fd < 0 || fd >= 4096)
		return (free(buffer), NULL);
	bytes_read = 1;
	while (line_end(acc[fd]) != 1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		acc[fd] = str_join(acc[fd], buffer);
		if (!acc[fd])
			break ;
	}
	free(buffer);
	if (!(acc[fd]) || acc[fd][0] == '\0' || bytes_read < 0)
		return (free(acc[fd]), acc[fd] = NULL, NULL);
	line = read_line(acc[fd]);
	acc[fd] = extract_line(acc[fd], line);
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int				fd;
// 	char			*p;
// 	static int		c;

// 	fd = open("file.txt", O_RDONLY);
// 	p = get_next_line(fd);
// 	c = 1;
// 	while (p)
// 	{
// 		printf("linha %d: %s", c, p);
// 		free(p);
// 		p = get_next_line(fd);
// 		c++;
// 	}
// 	close(fd);
// 	return (0);
// }
