/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:35:58 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/12 17:52:10 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_xpm_files(t_data *mlx, t_xpm *sprites, int x, int y)
{
	sprites->face_u = mlx_xpm_file_to_image(mlx, FACE_U, &x, &y);
	sprites->face_r = mlx_xpm_file_to_image(mlx, FACE_R, &x, &y);
	sprites->face_d = mlx_xpm_file_to_image(mlx, FACE_D, &x, &y);
	sprites->face_l = mlx_xpm_file_to_image(mlx, FACE_L, &x, &y);
	sprites->card = mlx_xpm_file_to_image(mlx, CARD, &x, &y);
	sprites->ground = mlx_xpm_file_to_image(mlx, GROUND, &x, &y);
	sprites->heli = mlx_xpm_file_to_image(mlx, HELICOPTER, &x, &y);
	sprites->wall_s = mlx_xpm_file_to_image(mlx, WALL_SIDES, &x, &y);
	sprites->wall_u_d = mlx_xpm_file_to_image(mlx, WALL_UP_DOWN, &x, &y);
	sprites->vest = mlx_xpm_file_to_image(mlx, YELLOW_VEST, &x, &y);
}

char	*find_file(char **map, int x, int y)
{
	static int	row;
	static int	col;

	row = find_len_strs(map);
	col = ft_strlen(*map);
	if (map[x][y] == EXIT)
		return (HELICOPTER);
	if (map[x][y] == COLLECTIBLE)
		return (CARD);
	if (map[x][y] == PLAYER)
		return (FACE_U);
	if (map[x][y] == '1' && x == 0 || x == row - 1)
		return (WALL_UP_DOWN);
	else if (map[x][y] == '1')
		return (WALL_SIDES);
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

void	put_to_screen(t_data *mlx, char *file, int x, int y)
{
}

void	put_element(t_data *mlx, char *file, int x, int y)
{
	static t_xpm	sprites;

	set_xpm_files(mlx, &sprites, 64, 64);
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
	if (!ft_strcmp(file, WALL_SIDES))
		mlx_put_image_to_window(mlx->mlx, mlx->win, sprites.wall_s, x, y);
	if (!ft_strcmp(file, WALL_UP_DOWN))
		mlx_put_image_to_window(mlx->mlx, mlx->win, sprites.wall_u_d, x, y);
}
void	set_map(t_data *mlx, char **map, char **imgs)
{
	int x;
	int y;
	char *str;

	x = -1;
	y = -1;
	while (map[++x])
	{
		while (map[x][++y])
		{
			str = find_file(map, x, y);
			put_element(mlx, str, x, y);
		}
		y = -1;
	}
}