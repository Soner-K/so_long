/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:23:50 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/23 13:54:02 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	player_movement(int keyhook, t_data *mlx)
// {
// 	static t_coordinates	pos;
// 	static int				i;

// 	if (i++ == 0)
// 		pos = find_initial_pos(mlx->map);
// 	if (keyhook == W_KEY)
// 		replace_and_put(mlx, &pos, FACE_U);
// 	put_element(mlx, FACE_U, pos.y * 64, (--pos.x) * 64);
// 	else if (keyhook == D_KEY) put_element(mlx, FACE_R, pos.x, pos.y);
// 	return (1);
// }

char	check_move(t_data *data, int keycode, t_coordinates *pos)
{
	t_coordinates	cp;
	char			is_valid;

	cp.x = pos->x;
	cp.y = pos->y;
	is_valid = 0;
	if (keycode == W_KEY && data->map[--cp.x][cp.y] != WALL)
		is_valid = 1;
	else if (keycode == D_KEY && data->map[cp.x][++cp.y] != WALL)
		is_valid = 1;
	else if (keycode == S_KEY && data->map[++cp.x][cp.y] != WALL)
		is_valid = 1;
	else if (keycode == A_KEY && data->map[cp.x][--cp.y] != WALL)
		is_valid = 1;
	if (data->map[cp.x][cp.y] == EXIT && data->collectibles == 0)
		return (*pos = cp, 2);
	else if (data->map[cp.x][cp.y] == EXIT && data->collectibles != 0)
		return (FALSE);
	if (is_valid)
		return (*pos = cp, TRUE);
	else
		return (FALSE);
}

void	replace_and_put(t_data *data, t_coordinates pos, t_coordinates pos_prev,
		char *file)
{
	put_element(data, GROUND, pos_prev.y * 64, pos_prev.x * 64);
	put_element(data, file, pos.y * 64, pos.x * 64);
}

int	player_movement(int key, t_data *data)
{
	char					is_valid;
	static t_coordinates	pos;
	t_coordinates			pos_cp;
	static int				i;

	if (i++ == 0)
		pos = find_initial_pos(data->map);
	pos_cp.x = pos.x;
	pos_cp.y = pos.y;
	// if (VALID_KEY)
	is_valid = check_move(data, key, &pos);
	// else
		// return (0);
	if (is_valid)
	{
		if (key == W_KEY)
			replace_and_put(data, pos, pos_cp, FACE_U);
		else if (key == D_KEY)
			replace_and_put(data, pos, pos_cp, FACE_R);
		else if (key == S_KEY)
			replace_and_put(data, pos, pos_cp, FACE_D);
		else if (key == A_KEY)
			replace_and_put(data, pos, pos_cp, FACE_L);
	}
	return (1);
}
// check if removing map[cp.x][cp.y] != 'EXIT' is ok or not
/*
m
	check_mov validity
	replace_and_put
	print mov_to_shell

*/