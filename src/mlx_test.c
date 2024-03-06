/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:05:32 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/06 20:42:54 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*addr;
	int		x;
	int		y;

}			t_win;

// void	ft_put_pixel(t_win *win, int x, int y, int color)
// {
// 	char	*dst;
// 	int		offset_x;
// 	int		offset_y;
// 	int		offset;

// 	offset_x = (win->bpp) / 8 * x;
// 	offset_y = (win->line_length) * (win->bpp / 8);
// 	offset = offset_x + offset_y;
// 	dst = ;
// 	mlx_new_image
// }

int	main(void)
{
	t_win	mlx;
	void	*ptr;
	
	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		exit(-1);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 1920, 1080, "ftg");
	if (!mlx.win_ptr)
		return (mlx_destroy_display(mlx.mlx_ptr), free(mlx.mlx_ptr),
			exit(EXIT_FAILURE), 1);
	ptr = mlx_xpm_file_to_image(mlx.mlx_ptr, "gamepad.xpm", &mlx.x, &mlx.y);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, ptr, mlx.x, mlx.y);
	mlx_loop(mlx.mlx_ptr);
}

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 190, 180, "Hello world!");
// 	img.img = mlx_new_image(mlx, 540, 190);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	my_mlx_pixel_put(&img, , 5, 0x00FF0000);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }