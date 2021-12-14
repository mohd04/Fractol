int		find_n(double cr, double ci, double max_n)
{
	int			i;
	double		zr;
	double		zi;
	double		temp;
	i = 0;
	zr = 0;
	zi = 0;
	while (i < max_n && zr * zr + zi * zi < 4.0)
	{
		temp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = temp;
		i++;
	}
	return (i);
}
void	mandelbrot(t_data *data)
{
	int		x;
	int		y;
	int		n;
	x = 100;
	y = 100;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 500, 40, 0xffffff,
		"Mandelbrot Set");
	while (x < data->width)
	{
		while (y < data->height)
		{
			data->cre = find_real(x, data);
			data->cim = find_imaginary(y, data);
			n = find_n(data->cre, data->cim, data->max_n);
			if (n == data->max_n)
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0x000000);
			else
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y,
					(data->color * n / 100));
			y++;
		}
		x++;
		y = 100;
	}
}
/*
** Find out the real and imaginary part for mandelbrot seperately
*/
double	find_real(int x, t_data *data)
{
	double	range;
	range = data->maxreal - data->minreal;
	return (x * (range / data->width) + data->minreal);
}
double	find_imaginary(int y, t_data *data)
{
	double range;
	range = data->max_i - data->min_i;
	return (y * (range / data->height) + data->min_i);
}
