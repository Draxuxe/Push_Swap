/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:20:53 by lfilloux          #+#    #+#             */
/*   Updated: 2021/12/10 18:47:09 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*reader(int fd)
{
	char	*buffer;
	int		readv;

	buffer = (char *)malloc(sizeof(char) * (1 + 1));
	if (!buffer)
		return (NULL);
	readv = read(fd, buffer, 1);
	if (readv < 0)
	{
		free (buffer);
		return (NULL);
	}
	buffer[readv] = '\0';
	return (buffer);
}

static char	*continuereading(char *save, int fd)
{
	char	*new_buffer;
	char	*dest;

	dest = reader(fd);
	if (!dest)
		return (NULL);
	if (!dest[0])
	{
		free (dest);
		return (save);
	}
	if (!save)
		return (dest);
	new_buffer = ft_strjoin_gnl(save, dest);
	free (save);
	free (dest);
	return (new_buffer);
}

static char	*findnl(char *save, char *line)
{
	char	*new_buffer;
	size_t	size_len;

	if (!save || !line)
		return (NULL);
	size_len = ft_strlen(line);
	if (size_len == ft_strlen(save))
	{
		free (save);
		return (NULL);
	}
	new_buffer = ft_substr_gnl(save, size_len, (ft_strlen(save) - size_len));
	free (save);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*save[4096];
	char		*line;
	size_t		lensize;

	if (fd < 0)
		return (NULL);
	line = 0;
	if (ft_strchr_gnl(save[fd], '\n') == -1)
	{
		lensize = ft_strlen(save[fd]);
		save[fd] = continuereading(save[fd], fd);
		if (lensize == ft_strlen(save[fd]) && save[fd])
			line = ft_substr_gnl(save[fd], 0, lensize);
	}
	if (!save[fd])
		return (NULL);
	if (!line && ft_strchr_gnl(save[fd], '\n') != -1)
		line = ft_substr_gnl(save[fd], 0, (ft_strchr_gnl(save[fd], '\n') + 1));
	if (line)
	{
		save[fd] = findnl(save[fd], line);
		return (line);
	}
	return (get_next_line(fd));
}
