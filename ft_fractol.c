/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatel <mpatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:55:09 by mpatel            #+#    #+#             */
/*   Updated: 2021/12/14 14:47:41 by mpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	mandelbrot(t_img *img)
{
	img->iter = 0;

	img->x0 = 1.70 * ((img->x - img->s_width / 2) / (0.365 * img->s_width));
	img->y0 = ((img->y - img->s_height / 2) / (0.25 * img->s_height));
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
	double temp;
	img->iter = 0;

	img->x0 = -0.7;
	img->y0 = 0.27015;
	img->new_x = 1.7 * (img->x - img->s_width / 2) / (0.3 *
				img->s_width);
	img->new_y = (img->y - img->s_height / 2) / (0.3 *
				img->s_height);
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
