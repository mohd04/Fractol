/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatel <mpatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:34:16 by mpatel            #+#    #+#             */
/*   Updated: 2021/12/18 21:15:25 by mpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	init_fractol(t_img *img)
{
	img->max_iter = 20;
	img->iter = 0;
	img->color = 0xd7afd7;
	img->zoom = 2.5;
	img->move_x = 0.02;
	img->move_y = 0.01;
}

// void	init_fractol(t_all->img *all->img)
// {
// 	all->img->max_iter = 100;
// 	all->img->iter = 0;
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

	// all = (t_all *)malloc(sizeof(all));
	all.data.mlx = mlx_init();
	all.data.mlx_win = mlx_new_window(all.data.mlx, WIDTH, HEIGHT, "Hello world!");
	all.data.img = mlx_new_image(all.data.mlx, WIDTH, HEIGHT);
	all.data.addr = mlx_get_data_addr(all.data.img, &all.data.bits_per_pixel, &all.data.line_length,
								&all.data.endian);
	init_fractol(&all.img);
	mlx_key_hook(all.data.mlx_win, keys, &all);
	mlx_mouse_hook(all.data.mlx_win, zoom, &all.img);
	mlx_loop_hook(all.data.mlx, loop_mand, &all);
	mlx_loop(all.data.mlx);
}
