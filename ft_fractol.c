/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatel <mpatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:55:09 by mpatel            #+#    #+#             */
/*   Updated: 2021/12/14 12:58:02 by mpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"
#include <stdio.h>

// double	find_x(int x, t_img *data)
// {
// 	double	range;
// 	range = data->max_x - data->min_x;
// 	return (x * (range / data->s_width) + data->min_x);
// }

// double	find_y(int y, t_img *data)
// {
// 	double range;
// 	range = data->max_y - data->min_y;
// 	return (y * (range / data->s_height) + data->min_y);
// }

// int	mandelbrot(t_img *img)
// {
// 	double temp;
// 	img->iter = 0;

// 	img->x0 = find_x(img->x, img);
// 	img->y0 = find_y(img->y, img);
// 	img->x2 = 0;
// 	img->y2 = 0;
// 	temp = 0;
// 	while ((img->x2 * img->x2) + (img->y2 + img->y2) <= 4 && img->iter < img->max_iter)
// 	{
// 		temp = img->x2 * img->x2 - img->y2 * img->y2 + img->x0;
// 		img->y2 = 2.0 * img->x2 * img->y2 + img->y0;
// 		img->x2 = temp;
// 		img->iter++;
// 	}
// 	// mlx_pixel_put(data->mlx, data->mlx_win, img->x, img->y, (img->color * img->iter / 100));
// 	return (img->iter);
// }

int	mandelbrot(t_img *img)
{
	double temp;
	double	x1;
	double	y1;
	img->iter = 0;

	img->x0 = 1.70 * ((img->x - img->s_width / 2) / (0.365 * img->s_width));
	img->y0 = ((img->y - img->s_height / 2) / (0.25 * img->s_height));
	img->x2 = 0;
	img->y2 = 0;
	x1 = 0;
	y1 = 0;
	temp = 0;
	while (img->iter < img->max_iter)
	{
		x1 = img->x2;
		y1 = img->y2;
		img->x2 = x1 * x1 - y1 * y1 + img->x0;
		img->y2 = 2 * x1 * y1 + img->y0;
		if (((img->x2 * img->x2) + (img->y2 * img->y2)) > 4)
			break ;
		img->iter++;
	}
	// mlx_pixel_put(data->mlx, data->mlx_win, img->x, img->y, (img->color * img->iter / 100));
	return (img->iter);
}

int	julia(t_img *img)
{
	double temp;
	img->iter = 0;

	img->x0 = -0.7;
	img->y0 = 0.27015;
	img->new_x = 1.5 * (img->x - img->s_width / 2) / (0.3 *
				img->s_width);
	img->new_y = (img->y - img->s_height / 2) / (0.3 *
				img->s_height);
	while ((img->x2 * img->x2) + (img->y2 + img->y2) <= 4 && img->iter < img->max_iter)
	{
		img->old_x = img->new_x;
		img->old_y = img->new_y;
		img->new_x = img->old_x * img->old_x - img->old_y *
			img->old_y + img->y0;
		img->new_y = 2 * img->old_x * img->old_y + img->x0;
		img->iter++;
	}
	// mlx_pixel_put(data->mlx, data->mlx_win, img->x, img->y, (img->color * img->iter / 100));
	return (img->iter);
}
