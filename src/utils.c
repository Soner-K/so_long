/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:42:58 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/30 12:04:14 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Initialize the elements of a structure.
 * @param elements An adress of a structure containing the number of times
 * an element is found inside a map.
 * @returns void.
 */
void	set_elements(t_elements *elements)
{
	elements->empty = 0;
	elements->wall = 0;
	elements->collectible = 0;
	elements->pos = 0;
	elements->exit = 0;
}

t_coordinates	find_pos(char **map, char c)
{
	t_coordinates	p;

	p.x = 0;
	p.y = -1;
	while (map[p.x])
	{
		while (map[p.x][++p.y])
			if (map[p.x][p.y] == c)
				return (p);
		p.x++;
		p.y = -1;
	}
	return (p);
}

int	count_element(char **map, char c)
{
	int	i;
	int	j;
	int	n;

	i = -1;
	j = -1;
	n = 0;
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (map[i][j] == c)
				n++;
		}
		j = -1;
	}
	return (n);
}

void	check_assets(int i, int f[NB_ASSETS])
{
	f[0] = open(PLAYER_D, O_RDONLY);
	f[1] = open(PLAYER_R, O_RDONLY);
	f[2] = open(PLAYER_D, O_RDONLY);
	f[3] = open(PLAYER_L, O_RDONLY);
	f[4] = open(CARD, O_RDONLY);
	f[5] = open(GROUND, O_RDONLY);
	f[6] = open(HELICOPTER, O_RDONLY);
	f[7] = open(TRASH_BIN, O_RDONLY);
	while (++i < NB_ASSETS)
	{
		if (f[i] < 0)
		{
			close_handler(8, *f, f[1], f[2], f[3], f[4], f[5], f[6], f[7]);
			print_and_exit("Issue with one or more asset's file opening.");
		}
	}
	close_handler(8, *f, f[1], f[2], f[3], f[4], f[5], f[6], f[7]);
}

void	check_assets2(int i, int fds[10])
{
	fds[0] = open(NB_ZERO, O_RDONLY);
	fds[1] = open(NB_ONE, O_RDONLY);
	fds[2] = open(NB_TWO, O_RDONLY);
	fds[3] = open(NB_THREE, O_RDONLY);
	fds[4] = open(NB_FOUR, O_RDONLY);
	fds[5] = open(NB_FIVE, O_RDONLY);
	fds[6] = open(NB_SIX, O_RDONLY);
	fds[7] = open(NB_SEVEN, O_RDONLY);
	fds[8] = open(NB_EIGHT, O_RDONLY);
	fds[9] = open(NB_NINE, O_RDONLY);
	while (++i < 10)
	{
		if (fds[i] < 0)
		{
			close_handler(10, fds[0], fds[1], fds[2], fds[3], fds[4], fds[5],
				fds[6], fds[7], fds[8], fds[9]);
			print_and_exit("Issue with one or more asset's file opening.");
		}
	}
	close_handler(10, fds[0], fds[1], fds[2], fds[3], fds[4], fds[5], fds[6],
		fds[7], fds[8], fds[9]);
}
