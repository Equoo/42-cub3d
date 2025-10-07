/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seed.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:00:53 by dderny            #+#    #+#             */
/*   Updated: 2025/04/14 22:00:37 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEED_H
# define SEED_H

/**
** @brief Get the seed
**
** @return int* The seed
*/
int	*getseed(void);

/**
** @brief return a random number
**
** @return int the random number
*/
int	rand_int(void);

#endif
