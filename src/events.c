/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:23:50 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/30 12:01:13 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	check_move(t_data *data, int keycode, t_coordinates *pos)
{
	t_coordinates	cp;
	char			is_valid;

	cp.x = pos->x;
	cp.y = pos->y;
	if (keycode == ESC_KEY)
		return (quit_game(data), END_GAME);
	is_valid = 0;
	if (keycode == W_KEY && data->map[--cp.x][cp.y] != WALL)
		is_valid = 1;
	else if (keycode == D_KEY && data->map[cp.x][++cp.y] != WALL)
		is_valid = 1;
	else if (keycode == S_KEY && data->map[++cp.x][cp.y] != WALL)
		is_valid = 1;
	else if (keycode == A_KEY && data->map[cp.x][--cp.y] != WALL)
		is_valid = 1;
	if (is_valid)
		return (*pos = cp, TRUE);
	else
		return (FALSE);
}

static int	move_player(t_data *data, t_coordinates pos, t_coordinates pos_prev,
		char *file)
{
	if (data->map[pos.x][pos.y] == COLLECTIBLE)
	{
		data->map[pos.x][pos.y] = EMPTY;
		data->collectibles--;
	}
	if (data->map[pos.x][pos.y] == EXIT && data->collectibles == 0)
		return (data->x = pos.x, data->y = pos.y, end_game(data));
	if (data->map[pos_prev.x][pos_prev.y] == EXIT)
		put_element(data, HELICOPTER, pos_prev.y * 64, pos_prev.x * 64);
	else
		put_element(data, GROUND, pos_prev.y * 64, pos_prev.x * 64);
	if (BONUS)
		put_element(data, file, pos.y * 64, pos.x * 64);
	else
		put_element(data, PLAYER_U, pos.y * 64, pos.x * 64);
	return (1);
}

int	player_movement(int key, t_data *data)
{
	char					is_valid;
	static t_coordinates	pos;
	t_coordinates			pos_cp;
	static int				i;

	if (i++ == 0)
		pos = find_pos(data->map, PLAYER);
	pos_cp.x = pos.x;
	pos_cp.y = pos.y;
	if (key == W_KEY || key == A_KEY || key == S_KEY || key == D_KEY
		|| key == ESC_KEY)
		is_valid = check_move(data, key, &pos);
	else
		return (0);
	if (is_valid)
		print_move(data);
	if (key == W_KEY)
		move_player(data, pos, pos_cp, PLAYER_U);
	else if (key == D_KEY)
		move_player(data, pos, pos_cp, PLAYER_R);
	else if (key == S_KEY)
		move_player(data, pos, pos_cp, PLAYER_D);
	else if (key == A_KEY)
		move_player(data, pos, pos_cp, PLAYER_L);
	return (1);
}
// check if removing map[cp.x][cp.y] != 'EXIT' is ok or not
/*
m
	check_mov validity
	replace_and_put
	print mov_to_shell

*/