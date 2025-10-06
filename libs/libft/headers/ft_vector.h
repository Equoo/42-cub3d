/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:25:29 by dderny            #+#    #+#             */
/*   Updated: 2025/05/12 13:01:39 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>

# define ALLOC_VECTOR 1024

typedef struct t_vec_header
{
	size_t			type_size;
	size_t			capacity;
	size_t			size;
	unsigned char	data[];
}					t_vec_header;

typedef void		*t_vec;

t_vec_header		*_vec_header(t_vec vector);

t_vec				vec_new(size_t element_size, size_t initial_capacity);
t_vec				vec_copy(t_vec *vector);
void				*vec_free(t_vec vector);

size_t				vec_size(t_vec vector);
size_t				vec_capacity(t_vec vector);
int 				vec_append(t_vec *vector, void *element);
t_vec				vec_pop(t_vec *vector);
t_vec				vec_insert(t_vec *vector, size_t index, void *element);
t_vec				vec_cat(t_vec *a, t_vec *b);
void				vec_remove(t_vec vector, size_t index);
void				vec_clear(t_vec vector);

#endif
