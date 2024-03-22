/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:35:58 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/22 15:47:26 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Puts all the xpm files to images.
 * @param mlx Adress of a structure containing a pointer to the mlx's adress
 * and the window's adress. 
 * @param sprites Adress of a structure containing pointers to all the images'
 * files.
 * @param x Length in pixels.
 * @param y Width in pixels.
 * @returns void.
 */
static void	set_xpm_files(t_data *mlx, t_xpm *sprites, int x, int y)
{
	sprites->face_u = mlx_xpm_file_to_image(mlx->mlx, FACE_U, &x, &y);
	sprites->face_r = mlx_xpm_file_to_image(mlx->mlx, FACE_R, &x, &y);
	sprites->face_d = mlx_xpm_file_to_image(mlx->mlx, FACE_D, &x, &y);
	sprites->face_l = mlx_xpm_file_to_image(mlx->mlx, FACE_L, &x, &y);
	sprites->card = mlx_xpm_file_to_image(mlx->mlx, CARD, &x, &y);
	sprites->ground = mlx_xpm_file_to_image(mlx->mlx, GROUND, &x, &y);
	sprites->heli = mlx_xpm_file_to_image(mlx->mlx, HELICOPTER, &x, &y);
	sprites->wall = mlx_xpm_file_to_image(mlx->mlx, TRASH_BIN, &x, &y);
	if (BONUS)
		sprites->vest = mlx_xpm_file_to_image(mlx->mlx, YELLOW_VEST, &x, &y);
}

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
		return (FACE_U);
	if (map[x][y] == EMPTY)
		return (GROUND);
	if (map[x][y] == WALL)
		return (TRASH_BIN);
	if (BONUS && map[x][y] == ENNEMY)
		return (YELLOW_VEST);
	return (NULL);
}

void	put_element(t_data *mlx, char *file, int x, int y) //if file null?
{
	static t_xpm	sprites;
	static int		i;

	if (i++ == 0)
		set_xpm_files(mlx, &sprites, 64, 64);
	if (!ft_strcmp(file, FACE_U))
		mlx_put_image_to_window(mlx->mlx, mlx->win, sprites.face_u, x, y);
	else if (!ft_strcmp(file, FACE_R))
		mlx_put_image_to_window(mlx->mlx, mlx->win, sprites.face_r, x, y);
	else if (!ft_strcmp(file, FACE_D))
		mlx_put_image_to_window(mlx->mlx, mlx->win, sprites.face_d, x, y);
	else if (!ft_strcmp(file, FACE_L))
		mlx_put_image_to_window(mlx->mlx, mlx->win, sprites.face_l, x, y);
	else if (!ft_strcmp(file, CARD))
		mlx_put_image_to_window(mlx->mlx, mlx->win, sprites.card, x, y);
	else if (!ft_strcmp(file, HELICOPTER))
		mlx_put_image_to_window(mlx->mlx, mlx->win, sprites.heli, x, y);
	else if (!ft_strcmp(file, GROUND))
		mlx_put_image_to_window(mlx->mlx, mlx->win, sprites.ground, x, y);
	else if (!ft_strcmp(file, TRASH_BIN))
		mlx_put_image_to_window(mlx->mlx, mlx->win, sprites.wall, x, y);
	else if (BONUS && !ft_strcmp(file, YELLOW_VEST))
		mlx_put_image_to_window(mlx->mlx, mlx->win, sprites.vest, x, y);
	else
		free_mlx(mlx, &sprites);
}

void	set_map(t_data *mlx, char **map)//check for x and y in loop
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
