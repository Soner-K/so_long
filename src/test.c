/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:19:36 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/01 18:04:02 by sokaraku         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	// void *t;
	// char 	*s;
	char **map;
	// int 	fd;
	int i;
	(void)argc;

	// fd = open(argv[1], O_RDONLY);
	// if (fd == -1)
	// 	exit(EXIT_FAILURE);
	check_if_ber(argv[1]);
	map = ber_to_map(argv[1]);
	i = 0;
	while (map[i])
		printf("%s\n", map[i++]);
	printf("\n%d\n", compare_top_down(map));
	// printf("map is %s\n", *map);
	check_map_elements(map, -1, -1);
	free_arrs((void **)map);
}