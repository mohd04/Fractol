/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatel <mpatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:55:09 by mpatel            #+#    #+#             */
/*   Updated: 2021/12/18 20:06:25 by mpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	mandelbrot(t_img *img)
{
	img->iter = 0;
	img->x0 = (1.70 * (img->x - WIDTH / 2) / (0.365 * WIDTH * img->zoom) + img->move_x);
	img->y0 = ((img->y - HEIGHT / 2) / (0.25 * HEIGHT * img->zoom) + img->move_y);
	img->new_x = 0;
	img->new_y = 0;
	while (img->iter < img->max_iter && ((img->new_x * img->new_x) + (img->new_y * img->new_y)) < 4)
	{
		img->old_x = img->new_x;
		img->old_y = img->new_y;
		img->new_x = img->old_x * img->old_x - img->old_y * img->old_y + img->x0;
		img->new_y = 2 * img->old_x * img->old_y + img->y0;
		img->iter++;
	}
	return (img->iter);
}

int	julia(t_img *img)
{
	img->iter = 0;
	img->x0 = -0.70176;
	img->y0 = -0.3842;
	img->new_x = (1.7 * (img->x - WIDTH / 2) / (0.3 * WIDTH * img->zoom) + img->move_x);
	img->new_y = ((img->y - HEIGHT / 2) / (0.3 * HEIGHT * img->zoom) + img->move_y);
	while (((img->new_x * img->new_x) + (img->new_y * img->new_y)) < 4 && img->iter < img->max_iter)
	{
		img->old_x = img->new_x;
		img->old_y = img->new_y;
		img->new_x = img->old_x * img->old_x - img->old_y * img->old_y + img->y0;
		img->new_y = 2 * img->old_x * img->old_y + img->x0;
		img->iter++;
	}
	return (img->iter);
}

// int	flame(t_img *img)
// {
// 	img->iter = 0;
// 	img->x0 = 1.70 * ((img->x - WIDTH / 2) / (0.365 * WIDTH));
// 	img->y0 = ((img->y - HEIGHT / 2) / (0.25 * HEIGHT));
// 	img->new_x = 0;
// 	img->new_y = 0;
// 	while (((img->new_x * img->new_x) + (img->new_y * img->new_y)) < 4 && img->iter < img->max_iter)
// 	{
// 		img->old_x = img->new_x;
// 		img->old_y = img->new_y;

// 	}
// }
void	draw(t_all *all)
{
	double	tmp;

	tmp = 0;
	all->img.y = 0;
	while (all->img.y < HEIGHT)
	{
		all->img.x = 0;
		while (all->img.x < WIDTH)
		{
			tmp = mandelbrot(&all->img);
			if (tmp == all->img.max_iter)
				my_mlx_pixel_put(&all->data, all->img.x, all->img.y, 0x00000000);
			else
				my_mlx_pixel_put(&all->data, all->img.x, all->img.y, (all->img.color * tmp / 100));
			all->img.x++;
		}
		all->img.y++;
	}
}

int	loop_mand(t_all *all)
{
	draw(all);
	mlx_put_image_to_window(all->data.mlx, all->data.mlx_win, all->data.img, 0, 0);
	return (0);
}
