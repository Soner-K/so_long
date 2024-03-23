/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:05:32 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/23 11:32:41 by sokaraku         ###   ########.fr       */
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



// int	close_it(int keycode, t_data *vars)
// {
// 	// mlx_destroy_window(vars->mlx, vars->win);
// 	printf("%d\n", keycode);
// 	(void) vars;
// 	return (0);
// }

// int	main(void)
// {
// 	t_data	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
// 	mlx_hook(vars.win, 2, 1L<<0, close_it, &vars);
// 	mlx_loop(vars.mlx);
// }

int	keypressed(int keycode, t_data *param)
{
	printf("keycode is %d\n", keycode);
	(void) param;
	return (0);
}

int main(void)
{
	t_data mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1920, 1080, "ttt");
	mlx_hook(mlx.win, KeyPress, W_KEY, keypressed, &mlx);
	mlx_loop(mlx.mlx);
}


// int	keypressed(int keycode, t_data *param)
// {
// 	printf("Keycode is %d\n", keycode);
// 	(void)param;  // Avoid unused parameter warning
// 	return (0);
// }

// int main(void)
// {
// 	t_data mlx;

// 	mlx.mlx = mlx_init();
// 	mlx.win = mlx_new_window(mlx.mlx, 1920, 1080, "ttt");
// 	mlx_hook(mlx.win, KeyPress, 1L << 0, keypressed, &mlx);
// 	mlx_loop(mlx.mlx);

// 	return (0);
// }


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

// int	main(void)
// {
// 	t_win	mlx;
// 	// void	*ptr;
	
// 	mlx.mlx_ptr = mlx_init();
// 	printf("%d", NB_SPRITES);
// 	// if (!mlx.mlx_ptr)
// 	// 	exit(-1);
// 	// mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 1920, 1080, "ftg");
// 	// if (!mlx.win_ptr)
// 	// 	return (mlx_destroy_display(mlx.mlx_ptr), free(mlx.mlx_ptr),
// 	// 		exit(EXIT_FAILURE), 1);
// 	// ptr = mlx_xpm_file_to_image(mlx.mlx_ptr, "assets/xpm/face_up.xpm", &mlx.x, &mlx.y);
// 	// mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, ptr, 0, 0);
// 	// free(ptr);
// 	// mlx_loop(mlx.mlx_ptr);
// }

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