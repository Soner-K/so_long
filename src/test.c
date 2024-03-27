/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:19:36 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/27 11:22:36 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	main(int ac, char **av)
// {
// 	char **map;
// 	char **map_cp;
// 	int i;
// 	t_coordinates n;

// 	if (ac != 2)
// 		exit(EXIT_FAILURE);
// 	i = 0;
// 	printf("map is %s\n", av[1]);
// 	map = parse_map(av[1], 0);
// 	map_cp = parse_map(av[1], 0);
// 	// while (map[i])
// 	// 	printf("%s\n", map[i++]);
// 	n = find_initial_pos(map);
// 	check_for_path(map, map_cp);
// 	i = 0;
// 	while (map[i])
// 		printf("%s\n", map[i++]);
// 	free_arrs((void **) map);
// 	exit(EXIT_SUCCESS);
// }

int	main(int ac, char **av)
{
	t_data	mlx;
	t_coordinates sizes;
	int			f[9];
	t_coordinates	pos;
	char **map;

	if (ac != 2)
		print_and_exit("petit con");
	f[8] = 0;
	check_assets(-1, f);
	map = create_map(av[1], 0);
	mlx.map = map;
	mlx.mlx = mlx_init();
	sizes = screen_size(&mlx, map);
	pos = find_pos(map, PLAYER);
	if (!mlx.mlx)
		print_and_exit("AAAAAAAA");
	mlx.win = mlx_new_window(mlx.mlx, sizes.x, sizes.y, "ttt");
	if (!mlx.win)
		print_and_exit("BBBBBBBB");
	mlx.collectibles = count_element(mlx.map, COLLECTIBLE);
	set_map(&mlx, map);
	mlx_hook(mlx.win, KeyPress, 1L << 0, player_movement, &mlx);
	mlx_hook(mlx.win, DestroyNotify, KeyPressMask, close_game, &mlx);
	mlx_loop(mlx.mlx);
}