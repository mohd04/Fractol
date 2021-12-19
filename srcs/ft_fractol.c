/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatel <mpatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:55:09 by mpatel            #+#    #+#             */
/*   Updated: 2021/12/19 23:26:53 by mpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

// int	mandelbrot(t_img *img)
// {
// 	img->it = 0;
// 	img->x0 = (1.70 * (img->x - WIDTH / 2)
// 			/ (0.365 * WIDTH * img->zoom) + img->move_x);
// 	img->y0 = ((img->y - HEIGHT / 2)
// 			/ (0.25 * HEIGHT * img->zoom) + img->move_y);
// 	img->new_x = 0;
// 	img->new_y = 0;
// 	while (img->it < img->max && ((img->new_x * img->new_x) + (img->new_y * img->new_y)) < 4)
// 	{
// 		img->old_x = img->new_x;
// 		img->old_y = img->new_y;
// 		img->new_x = img->old_x * img->old_x
// 			- img->old_y * img->old_y + img->x0;
// 		img->new_y = 2 * img->old_x * img->old_y + img->y0;
// 		img->it++;
// 	}
// 	return (img->it);
// }

// int	julia(t_img *img)
// {
// 	img->it = 0;
// 	img->new_x = (1.7 * (img->x - WIDTH / 2) / (0.3 * WIDTH * img->zoom) + img->move_x);
// 	img->new_y = ((img->y - HEIGHT / 2) / (0.3 * HEIGHT * img->zoom) + img->move_y);
// 	while (((img->new_x * img->new_x) + (img->new_y * img->new_y)) < 4 && img->it < img->max)
// 	{
// 		img->old_x = img->new_x;
// 		img->old_y = img->new_y;
// 		img->new_x = img->old_x * img->old_x - img->old_y * img->old_y + img->y0;
// 		img->new_y = 2 * img->old_x * img->old_y + img->x0;
// 		img->it++;
// 	}
// 	return (img->it);
// }

// int	julia(t_img *img)
// {
// 	img->it = 0;
// 	img->new_y = (1.70 * (img->x - WIDTH / 2) / (0.365 * WIDTH * img->zoom) + img->move_x);
// 	img->new_x = ((img->y - HEIGHT / 2) / (0.25 * HEIGHT * img->zoom) + img->move_y);
// 	while (((img->new_x * img->new_x) + (img->new_y * img->new_y)) < 4 && img->it < img->max)
// 	{
// 		img->old_x = img->new_x;
// 		img->old_y = img->new_y;
// 		img->new_x = sin(img->old_x) * img->old_x - cos(img->old_y) * img->old_y + img->y0;
// 		img->new_y = 2 * cos(img->old_x) * sin(img->old_y) + img->x0;
// 		img->it++;
// 	}
// 	return (img->it);
// }

// int	julia(t_img *img)
// {
// 	double	r;

// 	img->it = 0;
// 	img->x0 = (1.70 * (img->x - WIDTH / 2) / (0.365 * WIDTH * img->zoom) + img->move_x);
// 	img->y0 = ((img->y - HEIGHT / 2) / (0.25 * HEIGHT * img->zoom) + img->move_y);
// 	img->new_x = 0;
// 	img->new_y = 0;
// 	while (img->it < img->max && ((img->new_x * img->new_x) + (img->new_y * img->new_y)) < 4)
// 	{
// 		r *= r;
// 		r = img->old_x * img->old_x + img->old_y * img->old_y;
// 		img->old_x = img->new_x;
// 		img->old_y = img->new_y;
// 		img->new_x = img->old_x * (sin(r*r)) - img->old_y * (cos(r*r)) + img->x0;
// 		img->new_y = img->old_x * (cos(r*r)) - img->old_y * (sin(r*r)) + img->y0;
// 		img->it++;
// 	}
// 	return (img->it);
// }

// int	mandelbrot(t_img *img)
// {
// 	double	r;

// 	img->it = 0;
// 	img->x0 = (1.70 * (img->x - WIDTH / 2) / (0.365 * WIDTH * img->zoom) + img->move_x);
// 	img->y0 = ((img->y - HEIGHT / 2) / (0.25 * HEIGHT * img->zoom) + img->move_y);
// 	img->new_x = 0;
// 	img->new_y = 0;
// 	while (img->it < img->max && ((img->new_x * img->new_x) + (img->new_y * img->new_y)) < 4)
// 	{
// 		r *= r;
// 		r = img->old_x * img->old_x + img->old_y * img->old_y;
// 		img->old_x = img->new_x;
// 		img->old_y = img->new_y;
// 		img->new_x = r * (sin(90 + r)) + img->x0;
// 		img->new_y = cos(60 - r) + img->y0;
// 		img->it++;
// 	}
// 	return (img->it);
// }

int	mandelbrot(t_img *img)
{
	double	r;

	img->it = 0;
	img->new_x = (1.70 * (img->x - WIDTH / 2) / (0.365 * WIDTH * img->zoom) + img->move_x);
	img->new_y = ((img->y - HEIGHT / 2) / (0.25 * HEIGHT * img->zoom) + img->move_y);
	// img->new_x = 0;
	// img->new_y = 0;
	while (img->it < img->max && ((img->new_x * img->new_x) + (img->new_y * img->new_y)) < 4)
	{
		r = img->old_x * img->old_x + img->old_y * img->old_y;
		r *= r;
		img->old_x = img->new_x;
		img->old_y = img->new_y;
		img->new_x = (2 / (r + 1)) * img->old_x + img->x0;
		img->new_y = (2 / (r + 1)) * img->old_y + img->y0;
		img->it++;
	}
	return (img->it);
}

int	julia(t_img *img)
{
	double	r;

	//Julia 0.862 0.334
	img->it = 0;
 	img->new_x = (1.70 * (img->x - WIDTH / 2) / (0.365 * WIDTH * img->zoom) + img->move_x);
 	img->new_y = ((img->y - HEIGHT / 2) / (0.25 * HEIGHT * img->zoom) + img->move_y);
 	// img->new_x = 0;
 	// img->new_y = 0;
	while (img->it < img->max && ((img->new_x * img->new_x) + (img->new_y * img->new_y)) < 4)
	{
		r = img->old_x * img->old_x + img->old_y * img->old_y;
		r *= r;
		img->old_x = img->new_x;
		img->old_y = img->new_y;
		img->new_x = exp(img->old_x - 1) * (cos(M_PI * img->old_y)) + img->x0;
		img->new_y = exp(img->old_x - 1) * (sin(M_PI * img->old_y)) + img->y0;
		img->it++;
	}
	return (img->it);
}

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
			if (all->fractal == MANDELBROT)
				tmp = mandelbrot(&all->img);
			else if (all->fractal == JULIA)
				tmp = julia(&all->img);
			if (tmp == all->img.max)
				my_mlx_pixel_put(&all->data, all->img.x, all->img.y, 0x00000000);
			else
				my_mlx_pixel_put(&all->data, all->img.x, all->img.y, (all->img.color * tmp / 100));
			all->img.x++;
		}
		all->img.y++;
	}
}

int	loop(t_all *all)
{
	draw(all);
	mlx_put_image_to_window(all->data.mlx, all->data.mlx_win, all->data.img, 0, 0);
	return (0);
}
