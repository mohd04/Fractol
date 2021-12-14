/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatel <mpatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:34:16 by mpatel            #+#    #+#             */
/*   Updated: 2021/12/14 15:00:51 by mpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	init_fractol(t_img *img)
{
	img->s_width = 1000;
	img->s_height = 1000;
	img->max_iter = 25;
	img->iter = 0;
	img->color = 0xd7afd7;
	img->zoom = 1;
}

// void	init_fractol(t_img *img)
// {
// 	img->s_width = 1920;
// 	img->s_height = 1080;
// 	img->max_iter = 100;
// 	img->iter = 0;
// 	img->old_x = -2.0;
// 	img->old_y = -1.0;
// 	img->new_x = 1.3;
// 	img->new_y = 1.2;
// 	img->color = 0x006600;
// 	img->zoom = 1;
// }

int	main(void)
{
	t_img	*img;
	t_data	data;
	double	tmp = 0;

	img = (t_img *)malloc(sizeof(t_img));
	init_fractol(img);
	img->x = 0;
	img->y = 0;
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, img->s_width, img->s_height, "Hello world!");
	mlx_string_put(data.mlx, data.mlx_win, img->s_width, img->s_height, 0xffffff,
		"mandelbrot Set");
	while (img->y < img->s_height)
	{
		img->x = 0;
		while (img->x < img->s_width)
		{
			tmp = mandelbrot(img);
			if (tmp == img->max_iter)
				mlx_pixel_put(data.mlx, data.mlx_win, img->x, img->y, 0x00000000);
			else
				mlx_pixel_put(data.mlx, data.mlx_win, img->x, img->y, (img->color * tmp / 10));
			img->x++;
		}
		img->y++;
	}
	// mlx_key_hook(data.mlx_win, keys, &data);
	// mlx_hook(data.mlx_win, 4, 3, mouse_hook, &data);
	mlx_loop(data.mlx);
}
