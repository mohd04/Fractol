/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatel <mpatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:34:16 by mpatel            #+#    #+#             */
/*   Updated: 2021/12/17 20:33:40 by mpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	init_fractol(t_img *img)
{
	img->s_width = 1000;
	img->s_height = 1000;
	img->max_iter = 50;
	img->iter = 0;
	img->color = 0xd7afd7;
	img->zoom = 1;
	img->move_x = 1;
	img->move_y = 1;
}

// void	init_fractol(t_all->img *all->img)
// {
// 	all->img->s_width = 1920;
// 	all->img->s_height = 1080;
// 	all->img->max_iter = 100;
// 	all->img->iter = 0;
// 	all->img->old_x = -2.0;
// 	all->img->old_y = -1.0;
// 	all->img->new_x = 1.3;
// 	all->img->new_y = 1.2;
// 	all->img->color = 0x006600;
// 	all->img->zoom = 1;
// }

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	t_all	all;
	double	tmp = 0;

	// all = (t_all *)malloc(sizeof(all));
	init_fractol(&all.img);
	all.img.x = 0;
	all.img.y = 0;
	all.data.mlx = mlx_init();
	all.data.mlx_win = mlx_new_window(all.data.mlx, all.img.s_width, all.img.s_height, "Hello world!");
	all.data.img = mlx_new_image(all.data.mlx, all.img.s_width, all.img.s_height);
	all.data.addr = mlx_get_data_addr(all.data.img, &all.data.bits_per_pixel, &all.data.line_length,
								&all.data.endian);
	mlx_string_put(all.data.mlx, all.data.mlx_win, all.img.s_width, all.img.s_height, 0xffffff,
		"mandelbrot Set");
	draw(&all);
	// my_mlx_pixel_put(&all.data, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(all.data.mlx, all.data.mlx_win, all.data.img, 0, 0);
	mlx_key_hook(all.data.mlx_win, keys, &all.data);
	// mlx_hook(all.data.mlx_win, 4, 3, mouse_hook, &all.data);
	mlx_loop(all.data.mlx);
}
