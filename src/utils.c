/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:42:58 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/20 18:56:16 by sokaraku         ###   ########.fr       */
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

char	check_assets(char **assets)
{
	int i;
	int fd;

	i = 0;
	fd = 0;
	while (assets[i])
	{
		fd = open(assets[i], O_RDONLY);
		if (fd < 0)
			return (0);
		i++;
		close(fd);
	}
	return (1);
}

void	free_imgs(t_data *mlx, t_xpm *sprites) //what if no img?
{
	mlx_destroy_image(mlx->mlx, sprites->face_u);
	mlx_destroy_image(mlx->mlx, sprites->face_r);
	mlx_destroy_image(mlx->mlx, sprites->face_d);
	mlx_destroy_image(mlx->mlx, sprites->face_l);
	mlx_destroy_image(mlx->mlx, sprites->card);
	mlx_destroy_image(mlx->mlx, sprites->ground);
	mlx_destroy_image(mlx->mlx, sprites->heli);
	mlx_destroy_image(mlx->mlx, sprites->closing);
	mlx_destroy_image(mlx->mlx, sprites->vest);
}
