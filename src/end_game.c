/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:44:55 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/30 12:01:01 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_game(t_data *data)
{
	free_mlx(data, data->xpm);
	return (0);
}

int	quit_game(t_data *data)
{
	data->x = 0;
	data->y = 0;
	free_mlx(data, data->xpm);
	return (0);
}

static void	destroy_imgs(t_data *data, t_xpm *sprites)
{
	mlx_destroy_image(data->mlx, sprites->player_u);
	mlx_destroy_image(data->mlx, sprites->player_r);
	mlx_destroy_image(data->mlx, sprites->player_d);
	mlx_destroy_image(data->mlx, sprites->player_l);
	mlx_destroy_image(data->mlx, sprites->card);
	mlx_destroy_image(data->mlx, sprites->ground);
	mlx_destroy_image(data->mlx, sprites->heli);
	mlx_destroy_image(data->mlx, sprites->wall);
	if (BONUS)
	{
		mlx_destroy_image(data->mlx, sprites->zero);
		mlx_destroy_image(data->mlx, sprites->one);
		mlx_destroy_image(data->mlx, sprites->two);
		mlx_destroy_image(data->mlx, sprites->three);
		mlx_destroy_image(data->mlx, sprites->four);
		mlx_destroy_image(data->mlx, sprites->five);
		mlx_destroy_image(data->mlx, sprites->six);
		mlx_destroy_image(data->mlx, sprites->seven);
		mlx_destroy_image(data->mlx, sprites->eight);
		mlx_destroy_image(data->mlx, sprites->nine);
	}
}

void	free_mlx(t_data *data, t_xpm *sprites)
{
	int	x;
	int	y;

	x = data->x;
	y = data->y;
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	destroy_imgs(data, sprites);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	if (data->map[x][y] == EXIT && data->collectibles == 0)
		ft_putstr_fd("No more social security, congrats !!!\n", 1);
	free_arrs((void **)data->map);
	exit(EXIT_SUCCESS);
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
		sprites->zero = mlx_xpm_file_to_image(data->mlx, NB_ZERO, &x, &y);
		sprites->one = mlx_xpm_file_to_image(data->mlx, NB_ONE, &x, &y);
		sprites->two = mlx_xpm_file_to_image(data->mlx, NB_TWO, &x, &y);
		sprites->three = mlx_xpm_file_to_image(data->mlx, NB_THREE, &x, &y);
		sprites->four = mlx_xpm_file_to_image(data->mlx, NB_FOUR, &x, &y);
		sprites->five = mlx_xpm_file_to_image(data->mlx, NB_FIVE, &x, &y);
		sprites->six = mlx_xpm_file_to_image(data->mlx, NB_SIX, &x, &y);
		sprites->seven = mlx_xpm_file_to_image(data->mlx, NB_SEVEN, &x, &y);
		sprites->eight = mlx_xpm_file_to_image(data->mlx, NB_EIGHT, &x, &y);
		sprites->nine = mlx_xpm_file_to_image(data->mlx, NB_NINE, &x, &y);
	}
	data->xpm = sprites;
}
