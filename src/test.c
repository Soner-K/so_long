/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:19:36 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/09 16:48:46 by sokaraku         ###   ########.fr       */
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