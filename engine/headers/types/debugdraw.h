/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugdraw.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 01:52:53 by dderny            #+#    #+#             */
/*   Updated: 2025/11/01 02:12:38 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef enum {
	DEBUG_DRAW_DISABLED,
	DEBUG_DRAW_UNSHADED,
	DEBUG_DRAW_LIGHTING,
	DEBUG_DRAW_OVERDRAW,
	DEBUG_DRAW_WIREFRAME
}	t_debugdraw;
