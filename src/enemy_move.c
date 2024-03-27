/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:15:35 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/27 19:41:41 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// tab static avec pos

void	enemy_tab(char **map, t_coordinates *enemies,
		t_coordinates *enemies_prev)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = -1;
	y = -1;
	while (map[++x])
	{
		while (map[x][++y])
		{
			if (map[x][y] == 'V')
			{
				enemies[i].x = x;
				enemies[i].y = y;
				enemies_prev[i].x = x;
				enemies_prev[i].y = y;
				i++;
			}
		}
		y = -1;
	}
}

// void	enemy_move(t_data *data)
// {
// }
int	pseudo_rand(void)
{
	int	fd;
	int	buf;

	fd = open("/dev/random", O_RDONLY);
	if (fd == -1)
		return (-1);
	read(fd, &buf, 1);
	close(fd);
	return (buf);
}

char	valid_move(char **map, int x, int y)
{
	static int	i;
	static int	col;
	static int	row;

	if (i == 0)
	{
		col = ft_strlen(*map);
		row = find_len_strs(map);
		i = 1;
	}
	if (x < 0 || y < 0 || x > row - 1 || y > col - 1)
		return (FALSE);
	if (map[x][y] == EMPTY)
		return (TRUE);
	return (FALSE);
}

void	do_moves(t_data *data, t_coordinates enemies[60],
		t_coordinates enemies_prev[60])
{
	int	nb;
	int	i;

	nb = count_element(data->map, ENEMY);
	i = 0;
	while (i < nb)
	{
		if (valid_move(data->map, enemies[i].x, enemies[i].y))
		{
			put_element(data, YELLOW_VEST, enemies[i].x * 64, enemies[i].y
				* 64);
			put_element(data, GROUND, enemies_prev[i].x * 64, enemies_prev[i].y
				* 64);
			data->map[enemies_prev->x][enemies_prev->y] = EMPTY;
			data->map[enemies->x][enemies->y] = ENEMY;
		}
		i++;
	}
}

void	enemy_move(t_data *data)
{
	t_coordinates enemies[60];
	t_coordinates enemies_prev[60];
	int nb;
	int i;
	char mode;

	enemy_tab(data->map, enemies, enemies_prev);
	nb = count_element(data->map, ENEMY);
	i = 0;
	while (nb--)
	{
		if (pseudo_rand() % 2)
			mode = UP_DOWN;
		else
			mode = LEFT_RIGHT;
		if (mode == UP_DOWN)
		{
			if (pseudo_rand() % 2)
				enemies[i].x++;
			else
				enemies[i].x--;
		}
		else
		{
			if (pseudo_rand() % 2)
				enemies[i].y++;
			else
				enemies[i].y--;
		}
		// if (valid_move(data->map, enemies[i].x, enemies[i].y))
		// 	break ;
		// enemies[i].x = enemies_prev[i].x;
		// enemies[i].y = enemies_prev[i].y;
		i++;
	}
	do_moves(data, enemies, enemies_prev);
}