/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatel <mpatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 11:37:55 by mpatel            #+#    #+#             */
/*   Updated: 2021/12/19 22:59:24 by mpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

double	ft_atod(char *str)
{
	int		i;
	int		s;
	double	nums;
	double	n;

	n = 0.1;
	i = 0;
	s = 1;
	nums = 0.0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		nums = (str[i] - '0') + (nums * 10);
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] > 47 && str[i] < 58)
	{
		nums += (str[i] - '0') * n;
		n *= 0.1;
		i++;
	}
	return (nums);
}

int	zoom(int key, int x, int y, t_img *img)
{
	if (key == 4)
	{
		img->zoom *= 2;
		img->move_x += 1.5 * (x - WIDTH / 2) / (0.5 * img->zoom * WIDTH);
		img->move_y += (y - HEIGHT / 2) / (0.5 * img->zoom * HEIGHT);
	}
	if (key == 5)
	{
		img->zoom /= 2;
	}
	return (0);
}

int	keys(int key, t_all *all)
{
	if (key == 53)
	{
		mlx_destroy_image(all->data.mlx, all->data.mlx_win);
		exit(0);
	}
	if (key == 18)
		all->img.color = 0x00ff00;
	if (key == 19)
		all->img.color = 0xff69b4;
	if (key == 20)
		all->img.color = 0xffdab9;
	if (key == 24)
		all->img.max += 10;
	else if (key == 27)
		all->img.max -= 10;
	if (key == 123)
		all->img.move_x += 0.05 / all->img.zoom;
	else if (key == 124)
		all->img.move_x -= 0.05 / all->img.zoom;
	else if (key == 126)
		all->img.move_y += 0.05 / all->img.zoom;
	else if (key == 125)
		all->img.move_y -= 0.05 / all->img.zoom;
	return (0);
}
