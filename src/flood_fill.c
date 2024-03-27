/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:00:05 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/27 16:48:47 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	fill_around_exit(char **map_cp)
// {
// 	t_coordinates	exit;

// 	exit = find_pos(map_cp, EXIT);
// 	map_cp[exit.x + 1][exit.y] = '2';
// 	map_cp[exit.x - 1][exit.y] = '2';
// 	map_cp[exit.x][exit.y + 1] = '2';
// 	map_cp[exit.x + 1][exit.y - 1] = '2';
// if (BONUS && map_cp[x][y] == ENEMY)
// {
// 	if (x < 0 || y < 0 || x > row - 1 || y > col - 1)
// 		return ;
// 	if (map_cp[x + 1][y] != WALL && map_cp[x + 1][y] != ENEMY)
// 		map_cp[x + 1][y] = WALL;
// 	if (map_cp[x - 1][y] != WALL && map_cp[x + 1][y] != ENEMY)
// 		map_cp[x - 1][y] = WALL;
// 	if (map_cp[x][y + 1] != WALL && map_cp[x + 1][y] != ENEMY)
// 		map_cp[x][y + 1] = WALL;
// 	if (map_cp[x][y - 1] != WALL && map_cp[x + 1][y] != ENEMY)
// 		map_cp[x][y - 1] = WALL;
// 	return ;
// }
// }

/**
 * @brief
 * @param
 * @returns
 */
static void	flood_fill(char **map_cp, int x, int y)
{
	static int	col;
	static int	row;
	static int	i;

	if (i == 0)
	{
		col = ft_strlen(*map_cp);
		row = find_len_strs(map_cp);
		i++;
	}
	if (x < 0 || y < 0 || x > row - 1 || y > col - 1 || map_cp[x][y] == WALL)
		return ;
	if (BONUS && map_cp[x][y] == ENEMY)
		return ;
	if (map_cp[x][y] != WALL)
		map_cp[x][y] = WALL;
	// else if (BONUS && map_cp[x][y] != WALL && map_cp[x][y] != ENEMY)
	// 	map_cp[x][y] = WALL;
	flood_fill(map_cp, x + 1, y);
	flood_fill(map_cp, x - 1, y);
	flood_fill(map_cp, x, y + 1);
	flood_fill(map_cp, x, y - 1);
}

static void	flood_fill_bonus(char **map_cp, int x, int y)
{
	static int	col;
	static int	row;
	static int	i;

	if (i == 0)
	{
		col = ft_strlen(*map_cp);
		row = find_len_strs(map_cp);
		i++;
	}
	if (x < 0 || y < 0 || x > row - 1 || y > col - 1 || map_cp[x][y] == ENEMY)
		return ;
	if (map_cp[x][y] != WALL)
		map_cp[x][y] = WALL;
	flood_fill(map_cp, x + 1, y);
	flood_fill(map_cp, x - 1, y);
	flood_fill(map_cp, x, y + 1);
	flood_fill(map_cp, x, y - 1);
}

void	check_for_path_first(char **map, char **map_cp)
{
	int				x;
	int				y;
	t_coordinates	pos;

	x = -1;
	y = -1;
	pos = find_pos(map_cp, PLAYER);
	flood_fill(map_cp, pos.x, pos.y);
	while (map_cp[++x])
	{
		while (map_cp[x][++y])
		{
			if (map_cp[x][y] != WALL)
			{
				free_multiple_arrs(2, map_cp, map);
				print_and_exit("No valid path in the map.");
			}
		}
		y = -1;
	}
	free_arrs((void **)map_cp);
}
void	check_for_path_bonus(char **map, char **map_cp)
{
	int x;
	int y;
	t_coordinates pos;

	x = -1;
	y = -1;
	pos = find_pos(map_cp, PLAYER);
	flood_fill(map_cp, pos.x, pos.y);
	flood_fill_bonus(map_cp, pos.x, pos.y);
	while (map_cp[++x])
	{
		while (map_cp[x][++y])
		{
			if (map_cp[x][y] != WALL && map_cp[x][y] != ENEMY)
			{
				free_multiple_arrs(2, map_cp, map);
				print_and_exit("No valid path in the map.");
			}
		}
		y = -1;
	}
	free_arrs((void **)map_cp);
}
