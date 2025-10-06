/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uptime.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:28:29 by dderny            #+#    #+#             */
/*   Updated: 2025/04/02 20:51:14 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_time.h"
#include <fcntl.h>
#include <unistd.h>

#ifdef DEBUG
# include <time.h>

static double	fix_time(double time)
{
	static double	last = 0;

	time = (double)clock() / CLOCKS_PER_SEC;
	if (time < last)
		time = last;
	last = time;
	return (time);
}

#else

static double	fix_time(double time)
{
	static double	last = 0;

	if (time < last)
		time = last;
	last = time;
	if (time < 0)
		return (0);
	return (time);
}

#endif

double	ft_uptime(void)
{
	int		fd;
	int		len;
	char	line[256];
	char	*timestr;
	double	time;

	time = 0;
	fd = open("/proc/self/sched", O_RDONLY);
	if (fd < 0)
		return (-1);
	len = read(fd, line, 255);
	if (len == -1)
		return (-1);
	if (close(fd) == -1)
		return (-1);
	line[len] = 0;
	timestr = ft_strnstr(line, TIME_PARSE, len);
	if (timestr)
	{
		while (!ft_isdigit(*timestr))
			timestr++;
		time = ft_atof((const char *)(timestr)) / 1000;
	}
	return (fix_time(time));
}
