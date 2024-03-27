/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:44:55 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/27 18:37:24 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_coordinates	screen_size(t_data *mlx, char **map)
{
	t_coordinates	n;

	n.x = ft_strlen(*map) * 64;
	n.y = find_len_strs(map) * 64;
	if (n.x > LENGTH || n.y > WIDTH)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		free_arrs((void **)map);
		print_and_exit("Map too big");
	}
	return (n);
}

int	end_game(t_data *data)
{
	free_mlx(data, data->xpm);
	return (0);
}

int	close_game(t_data *data)
{
	data->x = 0;
	data->y = 0;
	free_mlx(data, data->xpm);
	return (0);
}

void	replace_and_put(t_data *data, t_coordinates pos, t_coordinates pos_prev,
		char *file)
{
	if (data->map[pos.x][pos.y] == COLLECTIBLE)
	{
		data->map[pos.x][pos.y] = EMPTY;
		data->collectibles--;
	}
	if (BONUS && data->map[pos.x][pos.y] == ENEMY)
	{
		ft_putendl_fd("The people won.", 1);
		close_game(data);
	}
	if (data->map[pos_prev.x][pos_prev.y] == EXIT)
		put_element(data, HELICOPTER, pos_prev.y * 64, pos_prev.x * 64);
	else
		put_element(data, GROUND, pos_prev.y * 64, pos_prev.x * 64);
	put_element(data, file, pos.y * 64, pos.x * 64);
	if (BONUS)
		enemy_move(data);
}

// void	key_press(t_data *mlx, int key)
// {
// 	if (key == W_KEY)

// }

/*
code moi strlen
*/