/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:08:38 by dderny            #+#    #+#             */
/*   Updated: 2025/10/29 17:20:25 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>
#define FORMAT_FLAGS "diuoxXfFeEgGcsp%"

typedef enum {
	FORMAT_CHAR,
	FORMAT_SINT,
	FORMAT_INT,
	FORMAT_UINT,
	FORMAT_LINT,
	FORMAT_ULINT,
	FORMAT_LLINT,
	FORMAT_ULLINT,
	FORMAT_DOUBLE
}	t_format_types;

typedef struct {
	int32_t	flags;
	size_t	width;
	size_t	precision;
	size_t	length;
}	t_format_tag;

typedef enum {
	FLAG_I,
	FLAG_U,
	FLAG_O,
	FLAG_X,
	FLAG_XU,
	FLAG_F,
	FLAG_FU,
	FLAG_C,
	FLAG_S,
	FLAG_P
}	t_format_flags;

static size_t	cp_to_next_tag(char *buffer, char **format, const size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && **format)
	{
		if (**format == '%')
		{
			if (*(*format + 1) == '%')
			{
				(*format) += 2;
				buffer[i] = **format;
				continue ;
			}
			return (i);
		}
		buffer[i] = **format;
		i++;
		(*format)++;
	}
	return (i);
}

int	internal_vformat(char *str, const size_t size, char *format, va_list ap)
{
	size_t	written;

	written = 0;
	while (*format)
	{
		written += cp_to_next_tag(str + written, &format, size - written);
		written += process_tag(str + written, &format, )
	}
}
