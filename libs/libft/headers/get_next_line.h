/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:25:43 by dderny            #+#    #+#             */
/*   Updated: 2025/02/07 01:39:10 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <limits.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 16
# endif

typedef enum e_gnl_state
{
	GNL_UNUSED,
	GNL_INUSE,
	GNL_ENDED,
}				t_gnl_state;

typedef struct s_gnl_data
{
	char		buf[BUFFER_SIZE + 1];
	ssize_t		pos;
	t_gnl_state	state;
	int			fd;
}				t_gnl_data;

/**
 * @brief Reads a line from the given file descriptor.
 *
 * This function reads from the file descriptor `fd` until a newline character
 * is encountered or the end of the file is reached. It returns the line read
 * as a null-terminated string. The newline character is included in the
 * returned string. If there is nothing more to read or an error occurs, the
 * function returns NULL.
 *
 * @param fd The file descriptor to read from.
 * @return A pointer to the line read, or NULL if there is nothing more to read
 *         or an error occurs.
 */
char			*get_next_line(int fd);

char			*read_line(t_gnl_data *data, char *buffer);
char			*read_until_newline(t_gnl_data *data, char *buffer);
char			*read_buffer(t_gnl_data *data);

ssize_t			get_newline(char *str);
char			*gnl_strjoin(char *s1, char *s2);
size_t			gnl_strlcpy(char *dest, const char *src, size_t n);
size_t			gnl_strlen(const char *str);
char			*gnl_strdup(const char *s, int len);

#endif
