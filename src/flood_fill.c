/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:00:05 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/03 23:07:08 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

// void	flood_fill(char **map_cp)
// {
// 	t_coordinates	p;
// 	t_coordinates	i;
// 	char			check;

// 	p = find_initial_pos(map_cp);
// 	i.x = 0;
// 	i.y = 0;
// 	while (1)
// 	{
// 		if ()
// 	}
// }
