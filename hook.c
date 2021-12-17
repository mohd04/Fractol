/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatel <mpatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 11:37:55 by mpatel            #+#    #+#             */
/*   Updated: 2021/12/17 20:37:26 by mpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

// void	ft_zoom(int x, int y, t_img *data)
// {
// 	data->min_x = (x / data->zoom + data->min_x) - (x / (data->zoom * 1.2));
// 	data->min_y = (y / data->zoom + data->min_y) - (y / (data->zoom * 1.2));
// 	data->zoom *= 1.2;
// 	data->max_iter++;
// }

// void	ft_dezoom(int x, int y, t_img *data)
// {
// 	data->min_x = (x / data->zoom + data->min_x) - (x / (data->zoom / 1.2));
// 	data->min_y = (y / data->zoom + data->min_y) - (y / (data->zoom / 1.2));
// 	data->zoom /= 1.2;
// 	data->max_iter--;
// }

// int		mouse_hook(int mousecode, int x, int y, t_img *img, t_data *data)
// {
// 	x = img->x;
// 	y = img->y;
// 	if (mousecode == 5 || mousecode == 2)
// 		ft_zoom(x, y, img);
// 	else if (mousecode == 4 || mousecode == 1)
// 		ft_dezoom(x, y, img);
// 	mlx_clear_window(data->mlx, data->mlx_win);
// 	mandelbrot(img, data);
// 	// put_text(data);
// 	return (0);
// }

int	zoom(int key, int x, int y, t_img *img)
{
	if (key == 4)
	{
		img->zoom += 2;
		img->move_x += 1.5 * (x - img->s_width / 2) / (0.5 * img->zoom * img->s_width);
		img->move_y += (y - img->s_width / 2) / (0.5 * img->zoom * img->s_height);
	}
	if (key == 5)
	{
		img->zoom /= 2;
	}
	return (0);
}

int		keys(int key, t_all *all)
{
	if (key == 53)
		exit(1);
	if (key == 18)
		all->img.color = 0x00ff00;
	if (key == 19)
		all->img.color = 0xff69b4;
	if (key == 20)
		all->img.color = 0xffdab9;
	if (key == 186)
		all->img.iter += 10;
	// else if (key == )
	// 	img->iter -= 10;
	// if (key == )
	// 	img->move_x += 0.05 / img->zoom;
	// else if (key == )
	// 	img->move_x -= 0.05 / img->zoom;
	// else if (key == )
	// 	img->move_y += 0.05 / img->zoom;
	// else if (key ==)
	// 	img->move_y -= 0.05 / img->zoom;
	mlx_destroy_image(all->data.mlx, all->data.img);
	mlx_new_image(all->data.mlx, all->img.s_width, all->img.s_height);
	mlx_clear_window(all->data.mlx, all->data.mlx_win);
	init_fractol(&all->img);
	draw(all);
	return (0);
}
