/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:25:29 by dderny            #+#    #+#             */
/*   Updated: 2025/05/12 13:02:06 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>

# define ALLOC_STRING 4096

typedef char	*t_str;

typedef			void(t_str_iter)(char *c, size_t index);

t_str			str_new(t_str str);
void			*str_free(t_str string);

size_t			str_size(t_str string);
size_t			str_capacity(t_str string);
t_str			str_append(t_str *string, char c);
t_str			str_pop(t_str *string);
t_str			str_insert(t_str *string, size_t index, char c);
t_str			str_cat(t_str *a, ...);
void			str_remove(t_str string, size_t index);
void			str_clear(t_str string);

t_str			str_substr(t_str string, size_t start, size_t len);
t_str			str_join(t_str *a, t_str *b);
t_str			str_split(t_str string, t_str delim);
t_str			str_trim(t_str string, char c);
t_str			str_replace(t_str string, t_str old, t_str new);
t_str			str_find(t_str string, t_str substr);
t_str			str_find_last(t_str string, t_str substr);

t_str			str_lower(t_str string);
t_str			str_upper(t_str string);
t_str			str_capitalize(t_str string);
t_str			str_reverse(t_str string);

t_str			str_fromi(int n, int base);
t_str			str_froml(long n, int base);
t_str			str_fromll(long long n, int base);
t_str			str_fromf(double n, int precision);
t_str			str_fromull(unsigned long long n, int base);
t_str			str_fromul(unsigned long n, int base);
t_str			str_fromu(unsigned int n, int base);

t_str			str_getpath(t_str string);
t_str			str_getfile(t_str string);
t_str			str_getext(t_str string);
t_str			str_getdir(t_str string);

t_str			*str_gmatch(t_str string, t_str match);
t_str			str_gsub(t_str string, t_str old, t_str new);

#endif
