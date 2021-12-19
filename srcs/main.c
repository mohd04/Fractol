/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatel <mpatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:34:16 by mpatel            #+#    #+#             */
/*   Updated: 2021/12/19 22:59:24 by mpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	init_fractol(t_img *img)
{
	img->max = 3;
	img->it = 0;
	img->color = 0xd7afd7;
	img->zoom = 1.0;
	img->move_x = 0.02;
	img->move_y = 0.01;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int ac, char **av)
{
	t_all	all;

	if (ac >= 2 && ac <= 4)
	{
		if (!(ft_strcmp(av[1], "Mandelbrot")))
			all.fractal = MANDELBROT;
		else
		{
			all.fractal = JULIA;
			all.img.x0 = ft_atod(av[2]);
			all.img.y0 = ft_atod(av[3]);
		}
	}
	else
	{
		write(2, "Invalid argument! Please write - 'Mandelbrot' || 'Julia x y'", 61);
		exit(EXIT_FAILURE);
	}
	all.data.mlx = mlx_init();
	all.data.mlx_win = mlx_new_window(all.data.mlx, WIDTH, HEIGHT, "Fractol!");
	all.data.img = mlx_new_image(all.data.mlx, WIDTH, HEIGHT);
	all.data.addr = mlx_get_data_addr(all.data.img,
			&all.data.bits_per_pixel, &all.data.line_length,
			&all.data.endian);
	init_fractol(&all.img);
	mlx_key_hook(all.data.mlx_win, keys, &all);
	mlx_mouse_hook(all.data.mlx_win, zoom, &all.img);
	mlx_loop_hook(all.data.mlx, loop, &all);
	mlx_loop(all.data.mlx);
}
