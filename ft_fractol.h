/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatel <mpatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:22:39 by mpatel            #+#    #+#             */
/*   Updated: 2021/12/17 20:32:12 by mpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
#define FT_FRACTOL_H

#include <stdlib.h>
#include <unistd.h>
#include "./minilibx_opengl_20191021/mlx.h"
#include "./minilibx_mms_20200219/mlx.h"
#include <math.h>
#include <time.h>

//gcc test.c ft_fractol.c hook.c -lmlx -framework OpenGL -framework AppKit -L minilibx_opengl_20191021


typedef struct s_img
{
	int		iter;
	double	max_iter;
	int		s_width;
	int		s_height;
	double	old_x;
	double	new_x;
	double	old_y;
	double	new_y;
	int		x;
	int		y;
	int		color;
	double	zoom;
	double	x0;
	double	y0;
	double	move_x;
	double	move_y;
	int		flag_mouse;
}				t_img;

typedef struct s_data
{
	void *img;
	void	*mlx;
	void	*mlx_win;
	// void	*win;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
}	t_data;

typedef struct s_all
{
	t_data	data;
	t_img	img;
}	t_all;

typedef struct s_plane
{
	double	x;
	double	y;
}				t_plane;

int	mandelbrot(t_img *img);
// int	mouse_hook(int mousecode, int x, int y, t_img *img, t_data *data);
int		keys(int key, t_all *all);
int	julia(t_img *img);
void	draw(t_all *all);
void	init_fractol(t_img *img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
