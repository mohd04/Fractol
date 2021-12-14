/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatel <mpatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 11:37:55 by mpatel            #+#    #+#             */
/*   Updated: 2021/11/15 16:15:39 by mpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	ft_zoom(int x, int y, t_img *data)
{
	data->min_x = (x / data->zoom + data->min_x) - (x / (data->zoom * 1.2));
	data->min_y = (y / data->zoom + data->min_y) - (y / (data->zoom * 1.2));
	data->zoom *= 1.2;
	data->max_iter++;
}

void	ft_dezoom(int x, int y, t_img *data)
{
	data->min_x = (x / data->zoom + data->min_x) - (x / (data->zoom / 1.2));
	data->min_y = (y / data->zoom + data->min_y) - (y / (data->zoom / 1.2));
	data->zoom /= 1.2;
	data->max_iter--;
}

int		mouse_hook(int mousecode, int x, int y, t_img *img, t_data *data)
{
	x = img->x;
	y = img->y;
	if (mousecode == 5 || mousecode == 2)
		ft_zoom(x, y, img);
	else if (mousecode == 4 || mousecode == 1)
		ft_dezoom(x, y, img);
	mlx_clear_window(data->mlx, data->mlx_win);
	mandelbrot(img, data);
	// put_text(data);
	return (0);
}

int		keys(int key, t_img *img, t_data *data)
{
	if (key == 53)
		exit(1);
	else if (key == 18)
		img->color = 0x00ff00;
	else if (key == 19)
		img->color = 0xff69b4;
	else if (key == 20)
		img->color = 0xffdab9;
	mlx_clear_window(data->mlx, data->mlx_win);
	mandelbrot(img, data);
	return (0);
}
