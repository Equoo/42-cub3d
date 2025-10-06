/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:26:53 by dderny            #+#    #+#             */
/*   Updated: 2025/04/02 20:51:14 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_puthex_addr(unsigned long long int n)
{
	int		i;
	char	addr[17];

	i = 0;
	addr[16] = '\0';
	while (i++ < 16)
	{
		addr[16 - i] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	write(1, addr, 16);
	write(1, ": ", 2);
}

void	add_to_buffer(unsigned char *buf, int i, unsigned char c)
{
	int	pos;

	pos = i * 2 + i / 2;
	if (c < 10)
		buf[pos++] = '0';
	else
		buf[pos++] = "0123456789abcdef"[c / 16 % 16];
	buf[pos++] = "0123456789abcdef"[c % 16];
	if (i % 2 == 1)
		buf[pos] = ' ';
	if (c >= 32 && c <= 126)
		buf[40 + i % 16] = c;
	else
		buf[40 + i % 16] = '.';
}

void	empty_by_space(unsigned char *buf)
{
	int	i;

	i = -1;
	while (++i < 56)
		buf[i] = ' ';
}

void	iter_char(void *addr, int i, unsigned char *buf, int size)
{
	unsigned int	index;
	unsigned char	*add;

	add = (unsigned char *)addr;
	index = i - 16;
	if (i == size - 1)
	{
		index = i - i % 16;
		add_to_buffer(buf, i % 16, add[i]);
	}
	if ((i != 0 && i % 16 == 0) || i == size - 1)
	{
		ft_puthex_addr((intptr_t)(addr + index));
		write(1, buf, 56);
		write(1, "\n", 1);
		empty_by_space(buf);
	}
	add_to_buffer(buf, i % 16, add[i]);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	buf[57];
	unsigned int	i;

	i = -1;
	empty_by_space(buf);
	buf[56] = '\0';
	while (++i < size)
	{
		iter_char(addr, i, buf, size);
	}
	return ((void *)addr);
}
