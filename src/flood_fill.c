/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:00:05 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/08 13:24:00 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	set_coordinates(t_coordinates *p, char config, char **map_cp)
{
	static int		len_strs;
	static int		len_one;
	t_coordinates	*store;

	len_strs = find_len_strs(map_cp);
	len_one = ft_strlen(*map_cp);
	store = p;
	if (config == UP)
		p->x--;
	else if (config == RIGHT)
		p->y++;
	else if (config == DOWN)
		p->x++;
	else if (config == LEFT)
		p->y--;
	if (p->y * p->x < 0)
		return (p = store, 0);
	if (p->x > len_strs - 1)
		return (p = store, -1);
	else if (p->y > len_one - 1)
		return (p = store, -2);
	return (TRUE);
}

void	fill_it(t_coordinates p, char **map_cp, char config)
{
	static int	collectibles;
	static int	count;

	collectibles = count_element(map_cp, 'C');
	if (set_coordinates(&p, config, map_cp) < 1)
		// what if not possible ?
		return ;
	// if (map_cp[p.x][p.y] == '1')
	// 	return ;
	if (map_cp[p.x][p.y] == 'C')
	{
		map_cp[p.x][p.y] = '1';
		count++;
	}
	if (map_cp[p.x][p.y] == '0' || map_cp[p.x][p.y] == 'P')
		map_cp[p.x][p.y] = '1';
	if (config + 1 == 4)
		config = 1 ;
	fill_it(p, map_cp, config + 1);
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
