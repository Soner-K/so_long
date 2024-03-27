/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:23:50 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/27 12:04:24 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_move(void)
{
	static int	move;

	ft_printf("%d\n", ++move);
}

char	check_move(t_data *data, int keycode, t_coordinates *pos)
{
	t_coordinates	cp;
	char			is_valid;

	cp.x = pos->x;
	cp.y = pos->y;
	if (keycode == ESC_KEY)
		return (data->x = cp.x, data->y = cp.y, end_game(data), END_GAME);
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
		return (data->x = cp.x, data->y = cp.y, print_move(), end_game(data),
			END_GAME);
	// else if (data->map[cp.x][cp.y] == EXIT && data->collectibles != 0)
	// 	return (FALSE);
	if (is_valid)
		return (*pos = cp, TRUE);
	else
		return (FALSE);
}

void	replace_and_put(t_data *data, t_coordinates pos, t_coordinates pos_prev,
		char *file)
{
	if (data->map[pos.x][pos.y] == COLLECTIBLE)
	{
		data->map[pos.x][pos.y] = EMPTY;
		data->collectibles--;
	}
	if (BONUS && data->map[pos.x][pos.y] == ENEMY)
	{
		ft_putendl_fd("The people won.", 1);
		close_game(data);
	}
	if (data->map[pos_prev.x][pos_prev.y] == EXIT)
		put_element(data, HELICOPTER, pos_prev.y * 64, pos_prev.x * 64);
	else
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
		pos = find_pos(data->map, PLAYER);
	pos_cp.x = pos.x;
	pos_cp.y = pos.y;
	if (key == W_KEY || key == A_KEY || key == S_KEY || key == D_KEY
		|| key == ESC_KEY)
		is_valid = check_move(data, key, &pos);
	else
		return (0);
	if (is_valid)
		print_move();
	if (key == W_KEY)
		replace_and_put(data, pos, pos_cp, PLAYER_U);
	else if (key == D_KEY)
		replace_and_put(data, pos, pos_cp, PLAYER_R);
	else if (key == S_KEY)
		replace_and_put(data, pos, pos_cp, PLAYER_D);
	else if (key == A_KEY)
		replace_and_put(data, pos, pos_cp, PLAYER_L);
	return (1);
}
// check if removing map[cp.x][cp.y] != 'EXIT' is ok or not
/*
m
	check_mov validity
	replace_and_put
	print mov_to_shell

*/