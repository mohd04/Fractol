/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatel <mpatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:22:39 by mpatel            #+#    #+#             */
/*   Updated: 2021/12/20 12:28:45 by mpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include "../minilibx_opengl_20191021/mlx.h"
# include <math.h>

# define WIDTH 1000
# define HEIGHT 1000

typedef struct s_img
{
	int		it;
	double	max;
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
	void	*img;
	void	*mlx;
	void	*mlx_win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef enum e_mode
{
	MANDELBROT,
	JULIA,
	PAINT,
	TUNNEL,
	GLITCHED,
	WHIRLPOOLS
}			t_mode;

typedef struct s_all
{
	t_data	data;
	t_img	img;
	t_mode	fractal;
}	t_all;

typedef struct s_plane
{
	double	x;
	double	y;
}				t_plane;

void	init_fractol(t_img *img);
int		mandelbrot(t_img *img);
int		julia(t_img *img);
int		tunnel(t_img *img);
int		paint(t_img *img);
int		tunnel(t_img *img);
int		glitched(t_img *img);
int		whirlpools(t_img *img);

int		keys(int key, t_all *all);
int		zoom(int key, int x, int y, t_img *img);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw(t_all *all);
int		looped(t_all *all);

double	ft_atod(char *str);

#endif
