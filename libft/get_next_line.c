/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:47:55 by csilva-m          #+#    #+#             */
/*   Updated: 2023/10/12 18:45:21 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read(int fd, char *buffer)
{
	char	*buff;
	int		byte_read;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	byte_read = 1;
	while (!(ft_strchr_gnl(buffer, '\n')) && byte_read != 0)
	{
		byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			free(buff);
			return (NULL);
		}
		buff[byte_read] = '\0';
		buffer = ft_strjoin_gnl(buffer, buff);
	}
	free(buff);
	return (buffer);
}

char	*ft_line(char *buffer)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = malloc((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_rest(char *buffer)
{
	char	*str;
	char	*nl_pos;

	str = NULL;
	nl_pos = ft_strchr_gnl(buffer, '\n');
	if (nl_pos != NULL)
		str = ft_strdup_gnl(nl_pos + 1);
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_rest(buffer);
	return (line);
}
