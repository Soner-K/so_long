/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:00:05 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/05 18:08:34 by sokaraku         ###   ########.fr       */
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

char	set_coordinates(t_coordinates *p, char config, char **map_cp)
{
	static int	len_strs;
	static int	len_one;
	
	len_strs = find_len_strs(map_cp);
	len_one = ft_strlen(*map_cp);
	if (config == UP)
		p->x--;
	else if (config == RIGHT)
		p->y++;
	else if (config == DOWN)
		p->x++;
	else if (config == LEFT)
		p->y--;
	if (p->y * p->x < 0)
		return (0);
	if (p->x > len_strs - 1)
		return (-1);
	else if (p->y > len_one - 1)
		return (-2);
	return (TRUE);
}

// char	check_config(char **map_cp, t_coordinates p, int i)
// {
// 	t_coordinates pos;
	
// 	pos = find_initial_pos(map_cp);
// 	while (1)
// 	{
		
// 	}
// }
// void	flood_fill(char **map_cp)
// {
// 	t_coordinates	p;
// 	char			check;

// 	p = find_initial_pos(map_cp);
// 	while (1)
// 	{
// 		if ()
// 	}
// }
