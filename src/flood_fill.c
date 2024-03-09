/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:00:05 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/09 17:14:29 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(char **map_cp, int x, int y)
{
	static int	col;
	static int	row;

	col = ft_strlen(*map_cp);
	row = find_len_strs(map_cp);
	if (x < 0 || y < 0 || x > row - 1 || y > col - 1 || map_cp[x][y] == WALL)
		return ;
	if (map_cp[x][y] != WALL)
		map_cp[x][y] = WALL;
	flood_fill(map_cp, x + 1, y);
	flood_fill(map_cp, x - 1, y);
	flood_fill(map_cp, x, y + 1);
	flood_fill(map_cp, x, y - 1);
}

void	check_for_path(char **map, char **map_cp)
{
	int				x;
	int				y;
	t_coordinates	pos;
	
	x = -1;
	y = -1;
	pos = find_initial_pos(map_cp);
	flood_fill(map_cp, pos.x, pos.y);
	while (map_cp[++x])
	{
		while (map_cp[x][++y])
		{
			if (map_cp[x][y] != WALL)
			{
				free_multiple_arrs(2, map_cp, map);
				print_and_exit("No valid path in the map");
			}
		}
			y = -1;
	}
	free_arrs((void **) map_cp);
}

// char	check_config(char **map_cp, t_coordinates p, int i)
// {
// 	t_coordinates pos;

// 	pos = find_initial_pos(map_cp);
// 	while (1)
// 	{

// 	}
// }
// void	flood_fill(char **map_cp)
// {
// 	t_coordinates	p;
// 	char			check;

// 	p = find_initial_pos(map_cp);
// 	while (1)
// 	{
// 		if ()
// 	}
// }
