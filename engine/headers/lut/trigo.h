/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 03:55:01 by zsonie            #+#    #+#             */
/*   Updated: 2025/10/30 04:52:52 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIGO_H
# define TRIGO_H

# define TABLE_SIZE 360

typedef struct
{
	float	sin_table[TABLE_SIZE];
	float	cos_table[TABLE_SIZE];
}			trigo_lut;

trigo_lut	*create_trigo_lut(void);
void		destroy_trigo_lut(trigo_lut *lut);
float		sin_lut(const trigo_lut *lut, int angle_deg);
float		cos_lut(const trigo_lut *lut, int angle_deg);

#endif
