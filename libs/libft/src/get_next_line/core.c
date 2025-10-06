/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:25:54 by dderny            #+#    #+#             */
/*   Updated: 2025/04/02 20:51:14 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

t_gnl_data	*getfddata(int fd)
{
	static t_gnl_data	data[OPEN_MAX];
	int					i;

	if (fd < 0)
		return (NULL);
	i = 0;
	while (i < OPEN_MAX && data[i].fd != fd)
		i++;
	if (i == OPEN_MAX)
	{
		i = 0;
		while (data[i].state != GNL_UNUSED)
			i++;
		if (i == OPEN_MAX)
			return (NULL);
		data[i] = (t_gnl_data){.fd = fd, .state = GNL_INUSE};
	}
	return (&data[i]);
}

char	*get_next_line(int fd)
{
	t_gnl_data	*data;
	char		*line;

	data = getfddata(fd);
	if (!data)
		return (NULL);
	line = NULL;
	if (data->state != GNL_ENDED)
	{
		if (data->pos != -1 && !data->buf[data->pos + 1])
		{
			data->pos = -1;
			line = gnl_strdup("", 0);
			if (line)
				line = read_line(data, line);
		}
		else
			line = read_buffer(data);
	}
	if (!line)
		*data = (t_gnl_data){.state = GNL_UNUSED, .pos = 0, .fd = 0};
	return (line);
}

char	*read_line(t_gnl_data *data, char *last)
{
	int		len;
	char	*buffer;

	buffer = NULL;
	len = -1;
	while (data->pos == -1 && len)
	{
		len = read(data->fd, data->buf, BUFFER_SIZE);
		if (!len)
			data->state = GNL_ENDED;
		if (len == -1 || (!len && !buffer && !last[0]))
			return (free(last), NULL);
		data->buf[len] = 0;
		data->pos = get_newline(data->buf);
		if (data->pos != -1)
			len = data->pos;
		buffer = gnl_strdup(data->buf, len + 1);
		buffer = gnl_strjoin(last, buffer);
		if (!buffer)
			return (NULL);
		last = buffer;
	}
	if (last && !buffer && !len)
		return (last);
	return (buffer);
}

char	*read_buffer(t_gnl_data *data)
{
	ssize_t	newline;
	char	*line;

	line = data->buf + data->pos + 1;
	newline = get_newline(line);
	if (newline == -1)
	{
		line = gnl_strdup(line, 0);
		if (!line)
			return (NULL);
		data->pos = -1;
		return (read_line(data, line));
	}
	line = gnl_strdup(line, newline + 1);
	if (!line)
		line = NULL;
	data->pos += newline + 1;
	return (line);
}

// #include <fcntl.h>

// int	main(void)
// {
// 	int		fd3;
// 	int		i;
// 	char	*tmp3;

// 	fd3 = open("tets.txt", O_RDONLY);
// 	i = 0;
// 	while (1)
// 	{
// 		i++;
// 		tmp3 = get_next_line(fd3);
// 		// if (tmp)
// 		//	test1 = gnl_strjoin(test1, tmp);
// 		// if (tmp2)
// 		//	test2 = gnl_strjoin(test2, tmp2);
// 		__builtin_printf("-%s", tmp3);
// 		if (tmp3)
// 		{
// 			free(tmp3);
// 			// test3 = gnl_strjoin(test3, tmp3);
// 		}
// 		else
// 			break ;
// 	}
// 	close(fd3);
// 	return (0);
// }
