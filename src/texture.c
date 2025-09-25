/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 01:14:36 by dderny            #+#    #+#             */
/*   Updated: 2025/04/26 01:56:38 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "render.h"
#include "texture.h"
#include <errno.h>
#include <libft.h>
#include <mlx.h>
#include <stdlib.h>

void	texture_del(void *self)
{
	int			olderrno;
	t_texture	*tex;

	tex = (t_texture *)self;
	if (tex->frames)
		free(tex->frames);
	if (tex->slices)
	{
		while (tex->nb_slices-- > 0)
			free(tex->slices[tex->nb_slices].name);
		free(tex->slices);
	}
	olderrno = errno;
	if (tex->img)
		mlx_destroy_image(tex->mlx, tex->img);
	if (errno == EAGAIN)
		errno = olderrno;
	if (tex->path)
		free(tex->path);
	free(tex);
}

static t_texture	*get_from_cache(t_render *render, char *path)
{
	t_list		*cache;
	t_texture	*tex;

	cache = render->textures;
	while (cache)
	{
		tex = (t_texture *)cache->content;
		if (!ft_strcmp(tex->path, path))
			return (tex);
		cache = cache->next;
	}
	return (NULL);
}

static int	texture_err(t_list *lst, t_texture *tex)
{
	print_error("Texture data parsing");
	if (lst)
		free(lst);
	texture_del(tex);
	return (1);
}

/**
** Create a new texture
** @param path: the path of the texture
** @param mlx: the mlx pointer
** @return the texture
*/
t_texture	*ft_texture(t_render *render, char *path)
{
	t_texture	*tex;
	t_list		*lst;

	lst = NULL;
	tex = get_from_cache(render, path);
	if (tex)
		return (tex);
	tex = ft_calloc(1, sizeof(t_texture));
	if (!tex && print_error("Texture creation"))
		return (NULL);
	tex->mlx = render->mlx;
	tex->path = ft_strdup(path);
	if (tex->path)
		tex->img = mylx_xpm_to_img(render->mlx, path, &tex->width,
				&tex->height);
	if (tex->img)
		lst = ft_lstnew(tex);
	if ((!tex->path || !tex->img || !lst || read_texture_data(tex, path, NULL))
		&& texture_err(lst, tex))
		return (NULL);
	ft_lstadd_front(&render->textures, lst);
	return (tex);
}
