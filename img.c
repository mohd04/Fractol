#include "ft_fractol.h"

void	init_fractol(t_img *img)
{
	img->max_iter = 10;
	img->start_x = ;
	img->start_y = ;
}

void	print_pixel(t_img *img)
{
	int	**iterationCount;
	int	*NumiterationsPerPixel;
	int x;
	int y;
	int i;

	i = 0;
	x = 0;
	y = 0;
	img->s_width = 600;
	img->s_height = 500;
	while (x < img->s_width)
	{
		while (y < img->s_height)
		{
			iterationCount[x][y];
			NumiterationsPerPixel[i]++;
			y++;
		}
		x++;
	}
}

int main(void)
{
	t_data *img;

	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(mlx, 600, 500, "Fractol");
	img->img = mlx_new_image(mlx, 600, 500);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length,
									&img->endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	mlx_loop(mlx);
}
