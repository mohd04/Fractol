/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatel <mpatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:44:09 by mpatel            #+#    #+#             */
/*   Updated: 2021/12/20 12:30:06 by mpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	fractal_select(t_all *all)
{
	if (all->fractal == MANDELBROT)
		return (mandelbrot(&all->img));
	else if (all->fractal == JULIA)
		return (julia(&all->img));
	else if (all->fractal == PAINT)
		return (paint(&all->img));
	else if (all->fractal == TUNNEL)
		return (tunnel(&all->img));
	else if (all->fractal == GLITCHED)
		return (glitched(&all->img));
	else
		return (whirlpools(&all->img));
	return (0);
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
			tmp = fractal_select(all);
			if (tmp == all->img.max)
				my_mlx_pixel_put(&all->data,
					all->img.x, all->img.y, 0x00000000);
			else
				my_mlx_pixel_put(&all->data, all->img.x,
					all->img.y, (all->img.color * tmp / 100));
			all->img.x++;
		}
		all->img.y++;
	}
}

int	looped(t_all *all)
{
	draw(all);
	mlx_put_image_to_window(all->data.mlx, all->data.mlx_win,
		all->data.img, 0, 0);
	return (0);
}
