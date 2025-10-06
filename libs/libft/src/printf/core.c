/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:16:10 by dderny            #+#    #+#             */
/*   Updated: 2025/05/01 14:20:29 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "unistd.h"
#include <stdlib.h>

static char	*convertany(va_list ap, t_pflag pt, int *len)
{
	char	*tmp;

	tmp = NULL;
	if (pt.flag == F_PERCENT)
		return (convertchar('%', len));
	if (pt.flag == F_CHAR)
		tmp = convertchar((char)va_arg(ap, int), len);
	if (pt.flag == F_STRING)
		tmp = convertstr(ap, pt, len);
	if (pt.flag == F_POINTER)
		tmp = convertpointer(ap, pt, len);
	if (pt.flag == F_DECIMAL || pt.flag == F_INT || pt.flag == F_UNSIGNED)
		tmp = convertnbr(ap, pt, len);
	if (pt.flag == F_HEXAL)
		tmp = converthexa((long long)va_arg(ap, __uint32_t),
				(t_nbrbase){BASE16L, 16}, pt, len);
	if (pt.flag == F_HEXAU)
		tmp = converthexa((long long)va_arg(ap, __uint32_t),
				(t_nbrbase){BASE16U, 16}, pt, len);
	if (pt.flag == F_FLOAT)
		tmp = convertfloat(va_arg(ap, double), pt, len);
	return (justifytxt(tmp, pt.atributs[F_MINUS], pt.min, len));
}

static int	get_flag_type(char *flag, t_pflag *type)
{
	char	*sflag;
	int		tmp;

	sflag = flag;
	tmp = ft_strchrpos(ATRIBUTES, *flag);
	while (tmp >= 0 && flag++)
	{
		type->atributs[tmp] = 1;
		tmp = ft_strchrpos(ATRIBUTES, *flag);
	}
	type->min = m_atoi(&flag);
	if (*flag == '.' && flag++)
	{
		type->atributs[F_POINT] = m_atoi(&flag) + 1;
	}
	type->flag = F_NONE;
	if (!*flag)
		return (0);
	tmp = ft_strchrpos(FLAGS, *flag);
	if (tmp >= 0 && flag++)
	{
		type->flag = (t_prnt_flag)(ATRIBUTESLEN + tmp);
		return (flag - sflag);
	}
	return (sflag - flag - 1);
}

static int	processflag(va_list ap, char *format, t_pdata *data)
{
	t_pflag	pt;

	data->next = -2;
	if ((unsigned char)*format == '%')
	{
		pt = (t_pflag){};
		data->next = get_flag_type((char *)format + 1, &pt);
		if (!data->next)
			data->next = -1;
		else if (data->next > 0)
			data->str = convertany(ap, pt, &data->strlen);
		else
		{
			data->strlen = 1;
			data->str = ft_strdup("%");
			data->next = data->next * -1 - 1;
			if (data->next > 0)
				data->next -= 1;
		}
		if (!data->str)
			data->next = -1;
	}
	if (data->next == -1)
		data->count = -1;
	return (data->next);
}

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	int		i;
	t_pdata	data;

	i = -1;
	data = (t_pdata){0, 0, 0, NULL, 0};
	while (format[++i] && data.next != -1)
	{
		data.next = processflag(ap, (char *)format + i, &data);
		if (data.next == -1 && printf_error_free(data))
			break ;
		if (data.next == -2)
			continue ;
		if (!(write(fd, format + data.last, i - data.last) != -1
				&& write(fd, data.str, data.strlen) != -1))
			return (printf_error_free(data));
		data.count += i - data.last + data.strlen;
		free(data.str);
		i = i + data.next;
		data.last = i + 1;
	}
	if (data.count != -1)
		data.count += i - data.last;
	if (write(fd, format + data.last, i - data.last) == -1)
		return (-1);
	return (data.count);
}
