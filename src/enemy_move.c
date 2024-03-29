/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:15:35 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/29 15:13:48 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// tab static avec pos

void	valid_moves(char **map, t_enemies *enemies, int x, int y)
{
	enemies->up = 0;
	enemies->right = 0;
	enemies->down = 0;
	enemies->left = 0;
	if (map[x + 1][y] == EMPTY) // down
		enemies->down = 1;
	if (map[x - 1][y] == EMPTY) // up
		enemies->up = 1;
	if (map[x][y + 1] == EMPTY) // right
		enemies->right = 1;
	if (map[x][y - 1] == EMPTY) // left
		enemies->left = 1;
}

void	enemy_array(char **map, t_enemies *enemies)
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
			if (map[x][y] == ENEMY)
			{
				enemies[i].x = x;
				enemies[i].y = y;
				enemies[i].x_prev = x;
				enemies[i].y_prev = y;
				valid_moves(map, &enemies[i], enemies[i].x, enemies[i].y);
				i++;
			}
		}
		y = -1;
	}
}

char	move_enemies(t_enemies *enemies, char mode)
{
	if (mode == DOWN)
	{
		enemies->x += 1;
		return (TRUE);
	}
	if (mode == UP)
	{
		enemies->x -= 1;
		return (TRUE);
	}
	if (mode == RIGHT)
	{
		enemies->y += 1;
		return (TRUE);
	}
	if (mode == LEFT)
	{
		enemies->y -= 1;
		return (TRUE);
	}
	return (FALSE);
}
                      
void	reset_map(t_data *data, t_enemies *enemies)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = -1;
	y = -1;
	while (data->map[++x])
	{
		while (data->map[x][++y])
		{
			if (data->map[x][y] == ENEMY && i < count_element(data->map, ENEMY))
			{
				data->map[enemies[i].x][enemies[i].y] = ENEMY;
				data->map[enemies[i].x_prev][enemies[i].y_prev] = EMPTY;
				put_element(data, GROUND, enemies[i].x_prev * 64,
					enemies[i].y_prev * 64);
				put_element(data, YELLOW_VEST, enemies[i].x * 64, enemies[i].y
					* 64);
				i++;
				printf("dssds %d\n", i);
			}
		}
		y = -1;
	}
}

void	enemy_move(t_data *data, int i, int nb)
{
	t_enemies	enemies[15];

	enemy_array(data->map, enemies);
	while (i < nb)
	{
		if (enemies[i].down == 1)
			enemies[i].x++;
		else if (enemies[i].up == 1)
			enemies[i].x--;
		else if (enemies[i].right == 1)
			enemies[i].y++;
		else if (enemies[i].left == 1)
			enemies[i].y--;
		printf("x prev %d y prev %d (enemy_move) ", enemies[i].x_prev,
		enemies[i].y_prev);
		printf("x after %d y after  %d (enemy_move)\n", enemies[i].x,
		enemies[i].y);
		i++;
	}
	reset_map(data, enemies);
}

// void	enemy_move(t_data *data)
// {
// 	t_coordinates enemies[60];
// 	t_coordinates enemies_prev[60];
// 	int nb;
// 	int i;
// 	char mode;

// 	enemy_tab(data->map, enemies, enemies_prev);
// 	nb = count_element(data->map, ENEMY);
// 	i = 0;
// 	while (nb--)
// 	{
// 		if (pseudo_rand() % 2)
// 			mode = UP_DOWN;
// 		else
// 			mode = LEFT_RIGHT;
// 		if (mode == UP_DOWN)
// 		{
// 			if (pseudo_rand() % 2)
// 				enemies[i].x++;
// 			else
// 				enemies[i].x--;
// 		}
// 		else
// 		{
// 			if (pseudo_rand() % 2)
// 				enemies[i].y++;
// 			else
// 				enemies[i].y--;
// 		}
// 		// if (valid_move(data->map, enemies[i].x, enemies[i].y))
// 		// 	break ;
// 		// enemies[i].x = enemies_prev[i].x;
// 		// enemies[i].y = enemies_prev[i].y;
// 		i++;
// 	}
// 	do_moves(data, enemies, enemies_prev);
// }
// void	enemy_move(t_data *data)
// {
// }
// int	pseudo_rand(void)
// {
// 	int	fd;
// 	int	buf;

// 	fd = open("/dev/random", O_RDONLY);
// 	if (fd == -1)
// 		return (-1);
// 	read(fd, &buf, 1);
// 	close(fd);
// 	return (buf);
// }

// char	valid_move(char **map, int x, int y)
// {
// 	static int	i;
// 	static int	col;
// 	static int	row;

// 	if (i == 0)
// 	{
// 		col = ft_strlen(*map);
// 		row = find_len_strs(map);
// 		i = 1;
// 	}
// 	if (x < 0 || y < 0 || x > row - 1 || y > col - 1)
// 		return (FALSE);
// 	if (map[x][y] == EMPTY)
// 		return (TRUE);
// 	return (FALSE);
// }

// void	do_moves(t_data *data, t_coordinates enemies[60],
// 		t_coordinates enemies_prev[60])
// {
// 	int	nb;
// 	int	i;

// 	nb = count_element(data->map, ENEMY);
// 	i = 0;
// 	while (i < nb)
// 	{
// 		if (valid_move(data->map, enemies[i].x, enemies[i].y))
// 		{
// 			put_element(data, YELLOW_VEST, enemies[i].x * 64, enemies[i].y
// 				* 64);
// 			put_element(data, GROUND, enemies_prev[i].x * 64, enemies_prev[i].y
// 				* 64);
// 			data->map[enemies_prev->x][enemies_prev->y] = EMPTY;
// 			data->map[enemies->x][enemies->y] = ENEMY;
// 		}
// 		i++;
// 	}
// }

// void	enemy_move(t_data *data, int i, int nb)
// {
// 	t_enemies	enemies[15];
// 	char		true;

// 	// enemies = malloc(sizeof(t_enemies) * nb);
// 	enemy_tab(data->map, enemies);
// 	true = 0;
// 	// while (i < nb)
// 	// {
// 	// 	printf("enemies[%d].x = %d enemies[%d].y = %d\n", i, enemies[i].x, i,
// 	// 		enemies[i].y);
// 	// 	printf("enemies[%d].x_prev = %d enemies[%d].y_prev = %d\n", i,
// 	// 		enemies[i].x_prev, i, enemies[i].y_prev);
// 	// 	i++;
// 	// }
// 	printf("\n");
// 	print_strs(data->map);
// 	printf("\n");
// 	i = 0;
// 	reset_map()
// 	// while (i < nb)
// 	// {
// 	// 	if (enemies[i].down == 1)
// 	// 		true = move_enemies(data, &enemies[i], DOWN);
// 	// 	else if (enemies[i].up == 1)
// 	// 		true = move_enemies(data, &enemies[i], UP);
// 	// 	else if (enemies[i].right == 1)
// 	// 		true = move_enemies(data, &enemies[i], RIGHT);
// 	// 	else if (enemies[i].left == 1)
// 	// 		true = move_enemies(data, &enemies[i], LEFT);
// 	// 	if (true)
// 	// 	{
// 	// 		// printf("x prev %d y prev (enemy_move) %d\n", enemies[i].x_prev,
// 	// 		// enemies[i].y_prev);
// 	// 		data->map[enemies[i].x_prev][enemies[i].y_prev] = EMPTY;
// 	// 		data->map[enemies[i].x][enemies[i].y] = ENEMY;
// 	// 		// printf("x after %d y after (enemy_move) %d\n", enemies[i].x,
// 	// 		// enemies[i].y);
// 	// 		put_element(data, GROUND, enemies[i].x_prev * 64, enemies[i].y_prev
// 	// 			* 64);
// 	// 	}
// 	// 	// free(&enemies[i]);
// 	// 	i++;
// 	// }
// }
