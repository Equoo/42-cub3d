/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memsetint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:05:30 by dderny            #+#    #+#             */
/*   Updated: 2025/05/12 13:02:42 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

static inline void	set_int(u_int *s, u_int v, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		s[i] = v;
		i++;
	}
}

// static inline void	set_int_x8(u_int *s, u_int v, size_t n)
//{
//	size_t		i;
//	__m256i		*_s;
//	__m256i		_v;

//	_v = ft_mm256_set1(v);
//	_s = (__m256i *)s;
//	i = 0;
//	while (i < n)
//	{
//		__builtin_printf("set_int_x8 %zu, %p\n", i, _s);
//		_s[i] = _v;
//		i++;
//	}
//}

// 1500
// const size_t	size = n * sizeof(u_int) / sizeof(__m256i);
// set_int_x8(s + i, v, size);
// if (n % 8)
//{
//	set_int(s + i + n / 8, v, n % 8);
//}

void	*ft_memsetint(u_int *s, u_int v, size_t n)
{
	set_int(s, v, n);
	return (s);
}
