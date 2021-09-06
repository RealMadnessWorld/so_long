#include "so_long.h"

void	image_put(char symb, t_vars *d, int y, int x)
{
	if (symb == '1' || symb == '0' || symb == 'C' || symb == 'E')
		//put_inactive_image();
	if(symb == 'P' || symb == 'D' || symb == 'X')
	{
		if (symb == 'P')
		{
			d->pos_x = x;
			d->pos_y = y;
		}
	}
}

void	put_static_image(char symb, t_vars *d)
{
	if (symb == '1')
		d->imag.img_border = mlx_xpm_file_to_image(d->mlx, d->imag.img_border, \
									&d->imag.img_wid, &d->imag.img_hei);
	if (symb == '0')
		d->imag.img_ground = mlx_xpm_file_to_image(d->mlx, d->imag.img_ground, \
									&d->imag.img_wid, &d->imag.img_hei);
	if (symb == 'C')
		d->imag.img_ground = mlx_xpm_file_to_image(d->mlx, d->imag.img_exit, \
									&d->imag.img_wid, &d->imag.img_hei);
	if (symb == 'E')
	{
		if (d->collect != 0)
		d->imag.img_ground = mlx_xpm_file_to_image(d->mlx, d->imag.img_ground, \
									&d->imag.img_wid, &d->imag.img_hei);
	}
}

void	put_moving_image()
{

}