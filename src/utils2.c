/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:44:55 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/29 17:49:44 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_coordinates	screen_size(t_data *mlx, char **map)
{
	t_coordinates	n;

	n.x = ft_strlen(*map) * 64;
	n.y = find_len_strs(map) * 64;
	if (BONUS)
		n.y += 64;
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

/**
 * @brief Puts all the xpm files to images.
 * @param mlx Adress of a structure containing a pointer to the mlx's adress
 * and the window's adress. 
 * @param sprites Adress of a structure containing pointers to all the images'
 * files.
 * @param x Length in pixels.
 * @param y Width in pixels.
 * @returns void.
 */
void	set_xpm_files(t_data *data, t_xpm *sprites, int x, int y)
{
	sprites->player_u = mlx_xpm_file_to_image(data->mlx, PLAYER_U, &x, &y);
	sprites->player_r = mlx_xpm_file_to_image(data->mlx, PLAYER_R, &x, &y);
	sprites->player_d = mlx_xpm_file_to_image(data->mlx, PLAYER_D, &x, &y);
	sprites->player_l = mlx_xpm_file_to_image(data->mlx, PLAYER_L, &x, &y);
	sprites->card = mlx_xpm_file_to_image(data->mlx, CARD, &x, &y);
	sprites->ground = mlx_xpm_file_to_image(data->mlx, GROUND, &x, &y);
	sprites->heli = mlx_xpm_file_to_image(data->mlx, HELICOPTER, &x, &y);
	sprites->wall = mlx_xpm_file_to_image(data->mlx, TRASH_BIN, &x, &y);
	if (BONUS)
	{
		sprites->vest = mlx_xpm_file_to_image(data->mlx, YELLOW_VEST, &x, &y);
		sprites->zero = mlx_xpm_file_to_image(data->mlx, NB_ZERO, &x, &y);
		sprites->one = mlx_xpm_file_to_image(data->mlx, NB_ONE, &x, &y);
		sprites->two = mlx_xpm_file_to_image(data->mlx, NB_TWO, &x, &y);
		sprites->three = mlx_xpm_file_to_image(data->mlx, NB_THREE, &x, &y);
		sprites->four = mlx_xpm_file_to_image(data->mlx, NB_FOUR, &x, &y);
		sprites->five = mlx_xpm_file_to_image(data->mlx, NB_FIVE, &x, &y);
		sprites->six = mlx_xpm_file_to_image(data->mlx, NB_SIX, &x, &y);
		sprites->seven = mlx_xpm_file_to_image(data->mlx, NB_SEVEN, &x, &y);
		sprites->eight= mlx_xpm_file_to_image(data->mlx, NB_EIGHT, &x, &y);
		sprites->nine = mlx_xpm_file_to_image(data->mlx, NB_NINE, &x, &y);
	}
	data->xpm = sprites;
}

// void	key_press(t_data *mlx, int key)
// {
// 	if (key == W_KEY)

// }

/*
code moi strlen
*/