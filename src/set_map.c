/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:35:58 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/21 14:41:14 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_xpm_files(t_data *mlx, t_xpm *sprites, int x, int y)
{
	sprites->face_u = mlx_xpm_file_to_image(mlx->mlx, FACE_U, &x, &y);
	sprites->face_r = mlx_xpm_file_to_image(mlx->mlx, FACE_R, &x, &y);
	sprites->face_d = mlx_xpm_file_to_image(mlx->mlx, FACE_D, &x, &y);
	sprites->face_l = mlx_xpm_file_to_image(mlx->mlx, FACE_L, &x, &y);
	sprites->card = mlx_xpm_file_to_image(mlx->mlx, CARD, &x, &y);
	sprites->ground = mlx_xpm_file_to_image(mlx->mlx, GROUND, &x, &y);
	sprites->heli = mlx_xpm_file_to_image(mlx->mlx, HELICOPTER, &x, &y);
	sprites->wall = mlx_xpm_file_to_image(mlx->mlx, TRASH_BIN, &x, &y);
	sprites->vest = mlx_xpm_file_to_image(mlx->mlx, YELLOW_VEST, &x, &y);
}

char	*find_file(char **map, int x, int y)
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
	return (NULL);
}

// void	fill_imgs_tab(char *imgs[])
// {
// 	imgs[0] = FACE_U;
// 	imgs[1] = FACE_R;
// 	imgs[2] = FACE_D;
// 	imgs[3] = FACE_L;
// 	imgs[4] = CARD;
// 	imgs[5] = GROUND;
// 	imgs[6] = HELICOPTER;
// 	imgs[7] = WALL_SIDES;
// 	imgs[8] = WALL_UP_DOWN;
// 	imgs[9] = YELLOW_VEST;
// }

// void	init_screen(t_data *mlx, char **map)
// {
// 	static int	x;
// 	static int	y;
// 	char		*file;

// 	file = find_file(map, x, y);
// 	put_element(mlx, file, x, y);
// }

/**
 * @brief Puts one element to the window.
 * @param mlx Structure containing mlx and window pointers.
 * @param file The xpm file corresponding to the character of the map.
 * @param x Position in the row.
 * @param y Position in the column.
 * @returns void.
 */
void	put_element(t_data *mlx, char *file, int x, int y)//if file null?
{
	static t_xpm	sprites;
	static int		i;

	if (i == 0)
		set_xpm_files(mlx, &sprites, 64, 64);
	i++;
	if (!ft_strcmp(file, FACE_U))
		mlx_put_image_to_window(mlx->mlx, mlx->win, sprites.face_u, x, y);
	if (!ft_strcmp(file, FACE_R))
		mlx_put_image_to_window(mlx->mlx, mlx->win, sprites.face_r, x, y);
	if (!ft_strcmp(file, FACE_D))
		mlx_put_image_to_window(mlx->mlx, mlx->win, sprites.face_d, x, y);
	if (!ft_strcmp(file, FACE_L))
		mlx_put_image_to_window(mlx->mlx, mlx->win, sprites.face_l, x, y);
	if (!ft_strcmp(file, CARD))
		mlx_put_image_to_window(mlx->mlx, mlx->win, sprites.card, x, y);
	if (!ft_strcmp(file, HELICOPTER))
		mlx_put_image_to_window(mlx->mlx, mlx->win, sprites.heli, x, y);
	if (!ft_strcmp(file, GROUND))
		mlx_put_image_to_window(mlx->mlx, mlx->win, sprites.ground, x, y);
	if (!ft_strcmp(file, TRASH_BIN))
		mlx_put_image_to_window(mlx->mlx, mlx->win, sprites.wall, x, y);
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
			put_element(mlx, str, pos_map.y, pos_map.x);
			pos_map.y += 64;
		}
		pos_strs.y = -1;
		pos_map.y = 0;
		pos_map.x += 64;
	}
}

// int	main(int ac, char **av)
// {
// 	int x;
// 	int y;
// 	char *str;
// 	char **map;

// 	x = -1;
// 	y = -1;
// 	map = create_map(av[1], 0);
// 	(void)ac;
// 	while (map[++x])
// 	{
// 		while (map[x][++y])
// 		{
// 			str = find_file(map, x, y);
// 			printf("at map[%d][%d] is %s\n", x, y, str);
// 		}
// 		y = -1;
// 	}
// 	free_arrs((void **)map);
// }