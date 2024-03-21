/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:44:55 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/21 16:04:55 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_coordinates	screen_size(t_data *mlx, char **map)
{
	t_coordinates	n;

	n.x = ft_strlen(*map) * 64;
	n.y = find_len_strs(map) * 64;
	if (n.x > LENGTH || n.y > WIDTH) // ok? need to account for task handler
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		free_arrs((void **)map);
		print_and_exit("Map too big");
	}
	return (n);
}

// void	check_assets(char bonus, int i)
// {
// 	int		fd;
// 	int		nb_assets;
// 	char	**assets;

// 	if (ASSETS[0] == 'E' || NB_ASSETS < 5)
// 		print_and_exit("Issue with assets");
// 	assets = ft_split(ASSETS, ' ');
// 	if (!assets)
// 		print_and_exit(MKO);
// 	nb_assets = NB_ASSETS;
// 	if (bonus == 0)
// 		nb_assets--;
// 	while (assets[++i])
// 	{
// 		fd = open(assets[i], O_RDONLY);
// 		if (fd < 0)
// 			free_and_quit("Issue with assets' file opening", assets);
// 		close(fd);
// 		nb_assets--;
// 	}
// 	if (nb_assets)//check if ok
// 		free_and_quit("Too many or not enough assets", assets);
// 	free_arrs((void **)assets);
// }

void	check_assets(char bonus, int i, int f[NB_ASSETS])
{
	f[0] = open(FACE_D, O_RDONLY);
	f[1] = open(FACE_R, O_RDONLY);
	f[2] = open(FACE_D, O_RDONLY);
	f[3] = open(FACE_L, O_RDONLY);
	f[4] = open(CARD, O_RDONLY);
	f[5] = open(GROUND, O_RDONLY);
	f[6] = open(HELICOPTER, O_RDONLY);
	f[7] = open(TRASH_BIN, O_RDONLY);
	if (bonus == 1)
		f[8] = open(YELLOW_VEST, O_RDONLY);
	while (++i < NB_ASSETS)
	{
		if (f[i] < 0)
		{
			if (bonus == 0)
				close_handler(8, *f, f[1], f[2], f[3], f[4], f[5], f[6], f[7]);
			else if (bonus == 1)
				close_handler(9, f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7],
					f[8]);
			print_and_exit("Issue with one or more asset's file opening.");
		}
	}
	if (bonus == 0)
		close_handler(8, f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7]);
	close_handler(9, f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7], f[8]);
}

// void	key_press(t_data *mlx, int key)
// {
// 	if (key == W_KEY)

// }