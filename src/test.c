/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:19:36 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/05 18:05:21 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// char	compare_top_down(char **map, int i, int j)
// {
// 	int	last;
// 	int	top_size;

// 	last = find_len_strs(map) - 1;
// 	if (last == -1)
// 		exit(EXIT_FAILURE); // faire fct erreur
// 	top_size = ft_strlen(*map);
// 	while (map[0][++i] && map[last][++j] && map[0][i] == '1'
// 		&& map[last][j] == '1' && top_size > 0)
// 		top_size--;
// 	return (top_size == 0);
// }

// int	main(int argc, char **argv)
// {
// 	// void *t;
// 	// char 	*s;
// 	char **map;
// 	// int 	fd;
// 	int i;
// 	(void)argc;

// 	// fd = open(argv[1], O_RDONLY);
// 	// if (fd == -1)
// 	// 	exit(EXIT_FAILURE);
// 	printf("map is in file %s\n", argv[1]);
// 	check_if_ber(argv[1]);
// 	map = ber_to_map(argv[1]);
// 	i = 0;
// 	printf("\n");
// 	while (map[i])
// 		printf("%s\n", map[i++]);
// 	compare_top_down(map);
// 	compare_sides(map);
// 	// printf("map is %s\n", *map);
// 	check_map_elements(map, -1, -1);
// 	free_arrs((void **)map);
// 	printf("\n");
// }

// int main(int ac, char **av)
// {
// 	char	**map;
// 	int		i;
// 	t_coordinates n;
	
// 	if (ac != 2)
// 		exit(EXIT_FAILURE);
// 	i = 0;
// 	printf("map is %s\n", av[1]);
// 	map = parse_map(av[1], 0);
// 	while (map[i])
// 		printf("%s\n", map[i++]);
// 	n = find_initial_pos(map);
// 	printf("x = %d and y = %d\n", n.x, n.y);
// 	printf("Line with entry is %s\n", map[n.x]);
// 	printf("Specific case is map[%d][%d] : %c\n", n.x, n.y, map[n.x][n.y]);
// 	free_arrs((void **) map);
// 	exit(EXIT_SUCCESS);
// }