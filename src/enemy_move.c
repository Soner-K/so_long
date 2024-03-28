/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:15:35 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/28 15:30:39 by sokaraku         ###   ########.fr       */
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

void	enemy_tab(char **map, t_enemies *enemies)
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
				// printf("\nx %d y %d\n", enemies[i].x, enemies[i].y);
				// printf("\nup %d down %d", enemies[i].up, enemies[i].down);
				// printf("left %d right %d\n", enemies[i].left,
				// enemies[i].right);
				i++;
			}
		}
		y = -1;
	}
}

char	move_enemies(t_data *data, t_enemies *enemies, char mode)
{
	if (mode == DOWN)
	{
		// printf("x before %d y before %d\n", enemies->x, enemies->y);
		put_element(data, YELLOW_VEST, ++(enemies->x) * 64, enemies->y * 64);
		return (TRUE);
	}
	if (mode == UP)
	{
		// printf("x before %d y before %d\n", enemies->x, enemies->y);
		put_element(data, YELLOW_VEST, --(enemies->x) * 64, enemies->y * 64);
		// printf("x after %d y after %d\n", enemies->x, enemies->y);
		return (TRUE);
	}
	if (mode == RIGHT)
	{
		// printf("x before %d y before %d\n", enemies->x, enemies->y);
		put_element(data, YELLOW_VEST, (enemies->x) * 64, ++(enemies->y) * 64);
		// printf("x after %d y after %d\n", enemies->x, enemies->y);
		return (TRUE);
	}
	if (mode == LEFT)
	{
		// printf("x before %d y before %d\n", enemies->x, enemies->y);
		put_element(data, YELLOW_VEST, (enemies->x) * 64, --(enemies->y) * 64);
		// printf("x after %d y after %d\n", enemies->x, enemies->y);
		return (TRUE);
	}
	return (FALSE);
}

void	enemy_move(t_data *data, int i, int nb)
{
	t_enemies	enemies[5];
	char		true;

	// enemies = malloc(sizeof(t_enemies) * nb);
	enemy_tab(data->map, enemies);
	true = 0;
	while (i < nb)
	{
		printf("enemies[%d].x = %d enemies[%d].y = %d\n", i, enemies[i].x, i,
			enemies[i].y);
		printf("enemies[%d].x_prev = %d enemies[%d].y_prev = %d\n", i,
			enemies[i].x_prev, i, enemies[i].y_prev);
		i++;
	}
	printf("\n");
	print_strs(data->map);
	printf("\n");
	i = 0;
	while (i < nb)
	{
		if (enemies[i].down == 1)
			true = move_enemies(data, &enemies[i], DOWN);
		else if (enemies[i].up == 1)
			true = move_enemies(data, &enemies[i], UP);
		else if (enemies[i].right == 1)
			true = move_enemies(data, &enemies[i], RIGHT);
		else if (enemies[i].left == 1)
			true = move_enemies(data, &enemies[i], LEFT);
		if (true)
		{
			printf("x prev %d y prev (enemy_move) %d\n", enemies->x_prev,
			enemies->y_prev);
			data->map[enemies[i].x_prev][enemies[i].y_prev] = EMPTY;
			data->map[enemies[i].x][enemies[i].y] = ENEMY;
			printf("x after %d y after (enemy_move) %d\n", enemies->x,
			enemies->y);
			put_element(data, GROUND, enemies[i].x_prev * 64, enemies[i].y_prev
				* 64);
		}
		// free(&enemies[i]);
		i++;
	}
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