/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:23:50 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/22 17:21:26 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	replace_and_put(t_data *mlx, t_coordinates *pos, char *put, int keyhook)
{
	if (VALID_KEY)
	put_element(mlx, GROUND, pos->y * 64, pos->x * 64);
	if (keyhook == W_KEY)
		put_element(mlx, FACE_U, pos->y * 64, (--pos->x) * 64)
	if (key_hook)
}

int	player_movement(int keyhook, t_data *mlx)
{
	static t_coordinates	pos;
	static int				i;

	if (i++ == 0)
		pos = find_initial_pos(mlx->map);
	if (keyhook == W_KEY)
		replace_and_put(mlx, &pos, FACE_U);
	put_element(mlx, FACE_U, pos.y * 64, (--pos.x) * 64);
	else if (keyhook == D_KEY) put_element(mlx, FACE_R, pos.x, pos.y);
	return (1);
}
