/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:19:36 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/23 10:41:26 by sokaraku         ###   ########.fr       */
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

// int	main(int ac, char **av)
// {
// 	t_data	mlx;
// 	t_coordinates sizes;
// 	int			f[NB_ASSETS];
// 	t_coordinates	pos;
// 	char **map;

// 	if (ac != 2)
// 		print_and_exit("petit con");
// 	check_assets(-1, f);
// 	map = create_map(av[1], 0);
// 	mlx.mlx = mlx_init();
// 	sizes = screen_size(&mlx, map);
// 	pos = find_initial_pos(map);
// 	if (!mlx.mlx)
// 		print_and_exit("AAAAAAAA");
// 	mlx.win = mlx_new_window(mlx.mlx, sizes.x, sizes.y, "ttt");
// 	if (!mlx.win)
// 		print_and_exit("BBBBBBBB");
// 	// put_element(&mlx, FACE_D, 1, 3);
// 	// put_element(&mlx, FACE_D, 1 + 32, 3 + 32);
// 	set_map(&mlx, map);
// 	mlx_key_hook(mlx.win, &player_movement, &mlx);
// 	mlx_loop(mlx.mlx);
// 	print_strs(map);
// 	free_arrs((void **)map);
// 	mlx_destroy_window(mlx.mlx, mlx.win);
// 	mlx_destroy_display(mlx.mlx);
// 	printf("bonus is %d\n", BONUS);
// 	free(mlx.mlx);
// }

// Function to handle key presses
// int handle_key_press(int keycode)
// {
//     printf("Key pressed: %d\n", keycode);
// 	if (keycode == 97)
// 		printf("sdad\n");
//     return 0;
// }

// int main()
// {
//     void *mlx_ptr;
//     void *win_ptr;

//     mlx_ptr = mlx_init();
//     win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Window");

//     // Set up a keyboard hook
//     mlx_key_hook(win_ptr, &handle_key_press, NULL);

//     mlx_loop(mlx_ptr);

//     return 0;
// }