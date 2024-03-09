/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:34:05 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/09 15:54:23 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*find_file(char c)
{
	if (c == '1')
		return (FILE_WALL);
	if (c == '0')
		return (FILE_EMPTY);
	if (c == 'P')
		return (FILE_CHARACTER);
	if (c == 'E')
		return (FILE_EXIT);
	if (c == 'C')
		return (FILE_COIN);
	return (NULL);
}

void	init_one(t_data *data, char *file)
{
	void	*ptr;

	ptr = mlx_xpm_file_to_image(data->mlx, file, 5, 5);
	if (!ptr) //necessaire ?
		return ;
	mlx_put_image_to_window(data->mlx, data->window, ptr, 5, 5);
	//mlx_loop?
}

void	init_screen(t_data *data, char **map)
{
	t_coordinates	i;
	char			*file;

	i.x = -1;
	i.y = -1;
	while (map[++i.x])
	{
		while (map[i.x][++i.y])
		{
			file = find_file(map[i.x][i.y]);
			init_one(data, file);
		}
		i.y = -1;
	}
}

// int main(int ac, char **av)
// {
// 	t_data	data;
// 	char	**map;

// 	map = parse_map(av[1], 0);
// 	data.mlx = mlx_init();
// 	data.window = mlx_new_window(data.mlx, 64, 64, "ftg");
// 	init_screen(&data, map);
// 	mlx_loop(data.mlx);
// 	mlx_destroy_window(data.mlx, data.window);
// 	mlx_destroy_display(data.mlx);
// 	free(data.mlx);
// 	free(data.window);
// 	return (0);
// }