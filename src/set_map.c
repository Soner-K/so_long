/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:35:58 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/30 12:02:22 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Finds the corresponding xpm file depending
 * on the encountered element.
 * @param map An array of strings, containing each line of the .ber file
 * acting as the map.
 * @param x Position in the row.
 * @param y Position in the column.
 * @returns The path towards the xpm file. NULL if file isn't found 
 *(note : returning null isn't possible, the presence of the files and
 )
 */
static char	*find_file(char **map, int x, int y)
{	
	if (map[x][y] == EXIT)
		return (HELICOPTER);
	if (map[x][y] == COLLECTIBLE)
		return (CARD);
	if (map[x][y] == PLAYER)
		return (PLAYER_U);
	if (map[x][y] == EMPTY)
		return (GROUND);
	if (map[x][y] == WALL)
		return (TRASH_BIN);
	return (NULL);
}

void	put_element(t_data *data, char *file, int x, int y)
{
	static t_xpm	sprites;
	static int		i;

	if (i++ == 0)
		set_xpm_files(data, &sprites, 64, 64);
	if (!ft_strcmp(file, PLAYER_U))
		mlx_put_image_to_window(data->mlx, data->win, sprites.player_u, x, y);
	else if (!ft_strcmp(file, PLAYER_R))
		mlx_put_image_to_window(data->mlx, data->win, sprites.player_r, x, y);
	else if (!ft_strcmp(file, PLAYER_D))
		mlx_put_image_to_window(data->mlx, data->win, sprites.player_d, x, y);
	else if (!ft_strcmp(file, PLAYER_L))
		mlx_put_image_to_window(data->mlx, data->win, sprites.player_l, x, y);
	else if (!ft_strcmp(file, CARD))
		mlx_put_image_to_window(data->mlx, data->win, sprites.card, x, y);
	else if (!ft_strcmp(file, HELICOPTER))
		mlx_put_image_to_window(data->mlx, data->win, sprites.heli, x, y);
	else if (!ft_strcmp(file, GROUND))
		mlx_put_image_to_window(data->mlx, data->win, sprites.ground, x, y);
	else if (!ft_strcmp(file, TRASH_BIN))
		mlx_put_image_to_window(data->mlx, data->win, sprites.wall, x, y);
	else
		return (data->x = 0, data->y = 0, free_mlx(data, &sprites));
}

void	set_map(t_data *mlx, char **map)
{
	t_coordinates	pos_strs;
	t_coordinates	pos_map;
	char			*str;

	pos_strs.x = -1;
	pos_strs.y = -1;
	pos_map.x = 0;
	pos_map.y = 0;
	while (map[++pos_strs.x])
	{
		while (map[pos_strs.x][++pos_strs.y])
		{
			str = find_file(map, pos_strs.x, pos_strs.y);
			if (!str)
			{
				put_element(mlx, NULL, 0, 0);
				free_and_quit("Issue while putting the map to the screen", map);
			}
			put_element(mlx, str, pos_map.y, pos_map.x);
			pos_map.y += 64;
		}
		pos_strs.y = -1;
		pos_map.y = 0;
		pos_map.x += 64;
	}
}
