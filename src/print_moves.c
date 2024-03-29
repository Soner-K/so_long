/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:54:28 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/29 21:12:54 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*give_unit(int *number)
{
	if ((*number) % 10 == 0 && *number != 0)
		return ((*number) /= 10, NB_ZERO);
	if ((*number) % 10 == 1)
		return ((*number) /= 10, NB_ONE);
	if ((*number) % 10 == 2)
		return ((*number) /= 10, NB_TWO);
	if ((*number) % 10 == 3)
		return ((*number) /= 10, NB_THREE);
	if ((*number) % 10 == 4)
		return ((*number) /= 10, NB_FOUR);
	if ((*number) % 10 == 5)
		return ((*number) /= 10, NB_FIVE);
	if ((*number) % 10 == 6)
		return ((*number) /= 10, NB_SIX);
	if ((*number) % 10 == 7)
		return ((*number) /= 10, NB_SEVEN);
	if ((*number) % 10 == 8)
		return ((*number) /= 10, NB_EIGHT);
	if ((*number) % 10 == 9)
		return ((*number) /= 10, NB_NINE);
	return (NULL);
}

static void	put_one(t_data *data, char *str, t_coordinates p, t_xpm sprites)
{
	if (!ft_strcmp(str, NB_ZERO))
		mlx_put_image_to_window(data->mlx, data->win, sprites.zero, p.y, p.x);
	else if (!ft_strcmp(str, NB_ONE))
		mlx_put_image_to_window(data->mlx, data->win, sprites.one, p.y, p.x);
	else if (!ft_strcmp(str, NB_TWO))
		mlx_put_image_to_window(data->mlx, data->win, sprites.two, p.y, p.x);
	else if (!ft_strcmp(str, NB_THREE))
		mlx_put_image_to_window(data->mlx, data->win, sprites.three, p.y, p.x);
	else if (!ft_strcmp(str, NB_FOUR))
		mlx_put_image_to_window(data->mlx, data->win, sprites.four, p.y, p.x);
	else if (!ft_strcmp(str, NB_FIVE))
		mlx_put_image_to_window(data->mlx, data->win, sprites.five, p.y, p.x);
	else if (!ft_strcmp(str, NB_SIX))
		mlx_put_image_to_window(data->mlx, data->win, sprites.six, p.y, p.x);
	else if (!ft_strcmp(str, NB_SEVEN))
		mlx_put_image_to_window(data->mlx, data->win, sprites.seven, p.y, p.x);
	else if (!ft_strcmp(str, NB_EIGHT))
		mlx_put_image_to_window(data->mlx, data->win, sprites.eight, p.y, p.x);
	else if (!ft_strcmp(str, NB_NINE))
		mlx_put_image_to_window(data->mlx, data->win, sprites.nine, p.y, p.x);
}

static void	one_nb_to_screen(t_data *data, char *str, int x, int y)
{
	int				fd;
	t_coordinates	pos;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("Error\nNumber not found.", 2);
		end_game(data);
	}
	close(fd);
	pos.x = x;
	pos.y = y;
	put_one(data, str, pos, *data->xpm);
}

static void	print_move_to_screen(t_data *data, int nb)
{
	char	*str;
	int		x;
	int		y;

	x = find_len_strs(data->map);
	y = ft_strlen(data->map[0]) - 1;
	while (nb)
	{
		str = give_unit(&nb);
		if (str == NULL)
			break ;
		one_nb_to_screen(data, str, x * 64, y * 64);
		y--;
	}
}

void	print_move(t_data *data)
{
	static int	move;
	static int	len_screen;

	if (BONUS && move == 0)
		len_screen = ft_strlen(data->map[0]);
	move++;
	if (BONUS && move > len_screen * 64)
	{
		ft_putendl_fd("Screen too small to print the moves", 2);
		quit_game(data);
	}
	if (BONUS == 0)
		ft_printf("%d\n", move);
	else
		print_move_to_screen(data, move);
}
