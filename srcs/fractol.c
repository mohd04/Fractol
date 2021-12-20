/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatel <mpatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:55:09 by mpatel            #+#    #+#             */
/*   Updated: 2021/12/20 12:26:54 by mpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int	mandelbrot(t_img *img)
{
	img->it = 0;
	img->x0 = (1.70 * (img->x - WIDTH / 2)
			/ (0.365 * WIDTH * img->zoom) + img->move_x);
	img->y0 = ((img->y - HEIGHT / 2)
			/ (0.25 * HEIGHT * img->zoom) + img->move_y);
	img->new_x = 0;
	img->new_y = 0;
	while (img->it < img->max)
	{
		img->old_x = img->new_x;
		img->old_y = img->new_y;
		img->new_x = img->old_x * img->old_x
			- img->old_y * img->old_y + img->x0;
		img->new_y = 2 * img->old_x * img->old_y + img->y0;
		img->it++;
		if (((img->new_x * img->new_x) + (img->new_y * img->new_y)) > 4)
			break ;
	}
	return (img->it);
}

int	julia(t_img *img)
{
	img->it = 0;
	img->new_x = (1.7 * (img->x - WIDTH / 2)
			/ (0.3 * WIDTH * img->zoom) + img->move_x);
	img->new_y = ((img->y - HEIGHT / 2)
			/ (0.3 * HEIGHT * img->zoom) + img->move_y);
	while (img->it < img->max)
	{
		img->old_x = img->new_x;
		img->old_y = img->new_y;
		img->new_x = img->old_x * img->old_x
			- img->old_y * img->old_y + img->y0;
		img->new_y = 2 * img->old_x * img->old_y + img->x0;
		img->it++;
		if (((img->new_x * img->new_x) + (img->new_y * img->new_y)) > 4)
			break ;
	}
	return (img->it);
}

int	tunnel(t_img *img)
{
	img->it = 0;
	img->x0 = (1.70 * (img->x - WIDTH / 2)
			/ (0.365 * WIDTH * img->zoom) + img->move_x);
	img->y0 = ((img->y - HEIGHT / 2)
			/ (0.25 * HEIGHT * img->zoom) + img->move_y);
	img->new_x = 0;
	img->new_y = 0;
	while (img->it < img->max)
	{
		img->old_x = img->new_x;
		img->old_y = img->new_y;
		img->new_x = sin(img->old_x) + img->x0;
		img->new_y = img->old_y + img->y0;
		img->it++;
		if (((img->new_x * img->new_x) + (img->new_y * img->new_y)) > 4)
			break ;
	}
	return (img->it);
}
