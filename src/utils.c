/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:42:58 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/22 15:08:35 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Initialize the elements of a structure.
 * @param elements An adress of a structure containing the number of times
 * an element is found inside a map.
 * @returns void.
 */
void	set_elements(t_elements *elements)
{
	elements->empty = 0;
	elements->wall = 0;
	elements->collectible = 0;
	elements->pos = 0;
	elements->exit = 0;
}

t_coordinates	find_initial_pos(char **map)
{
	t_coordinates	p;

	p.x = 0;
	p.y = -1;
	while (map[p.x])
	{
		while (map[p.x][++p.y])
			if (map[p.x][p.y] == 'P')
				return (p);
		p.x++;
		p.y = -1;
	}
	return (p);
}

int	count_element(char **map, char c)
{
	int	i;
	int	j;
	int	n;

	i = -1;
	j = -1;
	n = 0;
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (map[i][j] == c)
				n++;
		}
		j = -1;
	}
	return (n);
}

// what if no img?
void	free_mlx(t_data *mlx, t_xpm *sprites)
{
	mlx_destroy_image(mlx->mlx, sprites->face_u);
	mlx_destroy_image(mlx->mlx, sprites->face_r);
	mlx_destroy_image(mlx->mlx, sprites->face_d);
	mlx_destroy_image(mlx->mlx, sprites->face_l);
	mlx_destroy_image(mlx->mlx, sprites->card);
	mlx_destroy_image(mlx->mlx, sprites->ground);
	mlx_destroy_image(mlx->mlx, sprites->heli);
	mlx_destroy_image(mlx->mlx, sprites->wall);
	if (BONUS)
		mlx_destroy_image(mlx->mlx, sprites->vest);
	if (mlx->win)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		free(mlx->win);
	}
	mlx_destroy_display(mlx->mlx);
	free(mlx);
}

void	check_assets(int i, int f[NB_ASSETS])
{
	f[0] = open(FACE_D, O_RDONLY);
	f[1] = open(FACE_R, O_RDONLY);
	f[2] = open(FACE_D, O_RDONLY);
	f[3] = open(FACE_L, O_RDONLY);
	f[4] = open(CARD, O_RDONLY);
	f[5] = open(GROUND, O_RDONLY);
	f[6] = open(HELICOPTER, O_RDONLY);
	f[7] = open(TRASH_BIN, O_RDONLY);
	if (BONUS)
		f[8] = open(YELLOW_VEST, O_RDONLY);
	while (++i < NB_ASSETS)
	{
		if (f[i] < 0)
		{
			if (!BONUS)
				close_handler(8, *f, f[1], f[2], f[3], f[4], f[5], f[6], f[7]);
			else
				close_handler(9, f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7],
					f[8]);
			print_and_exit("Issue with one or more asset's file opening.");
		}
	}
	if (!BONUS)
		return (close_handler(8, *f, f[1], f[2], f[3], f[4], f[5], f[6], f[7]));
	close_handler(9, f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7], f[8]);
}
