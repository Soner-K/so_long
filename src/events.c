/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:23:50 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/29 17:12:22 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	print_move(t_data *data)
// {
// 	static int	move;

// 	ft_printf("%d\n", ++move);
// }

char	check_move(t_data *data, int keycode, t_coordinates *pos)
{
	t_coordinates	cp;
	char			is_valid;

	cp.x = pos->x;
	cp.y = pos->y;
	if (keycode == ESC_KEY)
		return (close_game(data), END_GAME);
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

int	move_player(t_data *data, t_coordinates pos, t_coordinates pos_prev,
		char *file)
{
	if (BONUS)
		enemy_move(data, 0, count_element(data->map, ENEMY));
	put_element(data, file, pos.y * 64, pos.x * 64);
	// printf("in pos [%d][%d] is %c\n", pos.x, pos.y, data->map[pos.x][pos.y]);
	if (BONUS && data->map[pos.x][pos.y] == ENEMY)
	{
		ft_putendl_fd("The people won.", 1);
		close_game(data);
	}
	if (data->map[pos.x][pos.y] == COLLECTIBLE)
	{
		data->map[pos.x][pos.y] = EMPTY;
		data->collectibles--;
	}
	if (data->map[pos.x][pos.y] == EXIT && data->collectibles == 0)
		return (data->x = pos.x, data->y = pos.y, print_move(data), end_game(data));
	if (data->map[pos_prev.x][pos_prev.y] == EXIT)
		put_element(data, HELICOPTER, pos_prev.y * 64, pos_prev.x * 64);
	else
		put_element(data, GROUND, pos_prev.y * 64, pos_prev.x * 64);
	return (1);
	// if (BONUS)
	// 	enemy_move(data, 0, count_element(data->map, ENEMY));
}

// void	actualize_map(char **map, t_coordinates pos, t_coordinates pos_prev)
// {
// 	static char	exit;

// 	if (exit == 0)
// 		map[pos_prev.x][pos_prev.y] = EMPTY;
// 	else
// 	{
// 		map[pos_prev.x][pos_prev.y] = EXIT;
// 		exit = 0;
// 	}
// 	if (map[pos.x][pos.y] == EXIT)
// 		exit = 1;
// 	map[pos.x][pos.y] = PLAYER;
// }

// besin de check pour esc_key?
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
	else
		return (0);
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