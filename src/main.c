/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:57:21 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/30 11:43:59 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/**
 * @brief Returns the screen size needed to represent a given map,
 * while checking if the map isn'too big for the screen's size.
 * @param data Adress of a structure containing a pointer to the mlx's adress,
 * the window's adress, the map array, the number of collectibles and the
 * number of enemies.
 * @param map An array of strings, containing each line of the .ber file
 * acting as the map.
 * @returns The length and width needed to represent the map in the screen.
 * Exits the program if the map is too big for the screen.
 */
t_coordinates	check_screen_size(t_data *data)
{
	t_coordinates	len_map;
	int				x;
	int				y;

	mlx_get_screen_size(data->mlx, &x, &y);
	len_map.x = ft_strlen(data->map[0]) * 64;
	len_map.y = find_len_strs(data->map) * 64;
	if (BONUS)
		len_map.y += 64;
	if (len_map.x > x || len_map.y > y - 64)
	{
		ft_printf("Error\nMap too big.\n");
		ft_printf("Length %d\n", len_map.x);
		ft_printf("Width %d\n", len_map.y);
		free_arrs((void **)data->map);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(EXIT_FAILURE);
	}
	return (len_map);
}

static void	prepare_data(t_data *data, char *path)
{
	t_coordinates	sizes;
	int				fds[NB_ASSETS];
	int				fds_2[10];

	check_assets(-1, fds);
	check_assets2(-1, fds_2);
	data->map = create_map(path, 0);
	if (!data->map)
		print_and_exit(MKO);
	data->mlx = mlx_init();
	if (!data->mlx)
		free_and_quit("Issue while creating mlx", data->map);
	sizes = check_screen_size(data);
	data->win = mlx_new_window(data->mlx, sizes.x, sizes.y, "so_long");
	if (!data->win)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		free_and_quit("Issue while creating the window", data->map);
	}
	data->collectibles = count_element(data->map, COLLECTIBLE);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		print_and_exit("Format : ./so_long map.ber");
	prepare_data(&data, av[1]);
	set_map(&data, data.map);
	mlx_hook(data.win, KeyPress, 1L << 0, player_movement, &data);
	mlx_hook(data.win, DestroyNotify, 1L << 2, quit_game, &data);
	mlx_loop(data.mlx);
}
