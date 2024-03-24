/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:44:55 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/24 17:41:31 by sokaraku         ###   ########.fr       */
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

// void	key_press(t_data *mlx, int key)
// {
// 	if (key == W_KEY)

// }

/*
code moi strlen
*/