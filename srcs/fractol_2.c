/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatel <mpatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:21:05 by mpatel            #+#    #+#             */
/*   Updated: 2021/12/20 12:27:40 by mpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int	glitched(t_img *img)
{
	double	r;

	img->it = 0;
	img->x0 = (1.70 * (img->x - WIDTH / 2)
			/ (0.365 * WIDTH * img->zoom) + img->move_x);
	img->y0 = ((img->y - HEIGHT / 2)
			/ (0.25 * HEIGHT * img->zoom) + img->move_y);
	while (img->it < img->max)
	{
		r = img->old_x * img->old_x + img->old_y * img->old_y;
		r *= r;
		img->old_x = img->new_x;
		img->old_y = img->new_y;
		img->new_x = (2 / (r + 1)) * img->old_x + img->x0;
		img->new_y = (2 / (r + 1)) * img->old_y + img->y0;
		img->it++;
		if (((img->new_x * img->new_x) + (img->new_y * img->new_y)) > 4)
			break ;
	}
	return (img->it);
}

int	whirlpools(t_img *img)
{
	double	r;

	img->it = 0;
	img->x0 = (1.70 * (img->x - WIDTH / 2)
			/ (0.365 * WIDTH * img->zoom) + img->move_x);
	img->y0 = ((img->y - HEIGHT / 2)
			/ (0.25 * HEIGHT * img->zoom) + img->move_y);
	while (img->it < img->max)
	{
		r = img->old_x * img->old_x + img->old_y * img->old_y;
		r *= r;
		img->old_x = img->new_x;
		img->old_y = img->new_y;
		img->new_x = exp(img->old_x - 1) * (cos(M_PI * img->old_y)) + img->x0;
		img->new_y = exp(img->old_x - 1) * (sin(M_PI * img->old_y)) + img->y0;
		img->it++;
		if (((img->new_x * img->new_x) + (img->new_y * img->new_y)) > 4)
			break ;
	}
	return (img->it);
}

int	paint(t_img *img)
{
	img->it = 0;
	img->x0 = (1.70 * (img->x - WIDTH / 2)
			/ (0.365 * WIDTH * img->zoom) + img->move_x);
	img->y0 = ((img->y - HEIGHT / 2)
			/ (0.25 * HEIGHT * img->zoom) + img->move_y);
	while (img->it < img->max)
	{
		img->old_x = img->new_x;
		img->old_y = img->new_y;
		img->new_x = sin(img->old_x) * img->old_x
			- cos(img->old_y) * img->old_y + img->y0;
		img->new_y = 2 * cos(img->old_x) * sin(img->old_y) + img->x0;
		img->it++;
		if (((img->new_x * img->new_x) + (img->new_y * img->new_y)) > 4)
			break ;
	}
	return (img->it);
}
