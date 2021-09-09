#include "so_long.h"

void	image_put(char symb, t_vars *d, int y, int x)
{
	if (symb == '1' || symb == '0' || symb == 'C' || symb == 'E')
		put_static_image(symb, d);
	if(symb == 'P' || symb == 'X')
	{
		if (symb == 'P')
		{
			d->pos_x = x;
			d->pos_y = y;
		}
		if (symb == 'X')
		{
			d->e_pos_x = x;
			d->e_pos_y = y;
		}
		put_moving_image(symb, d);
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img, x * d->imag.img_hei, y * d->imag.img_wid);
}

void	put_static_image(char symb, t_vars *d)
{
	if (symb == '1')
		d->img = mlx_xpm_file_to_image(d->mlx, d->imag.img_border, \
									&d->imag.img_hei, &d->imag.img_wid);
	if (symb == '0')
		d->img = mlx_xpm_file_to_image(d->mlx, d->imag.img_ground, \
									&d->imag.img_hei, &d->imag.img_wid);
	if (symb == 'E')
		d->img = mlx_xpm_file_to_image(d->mlx, d->imag.img_exit, \
									&d->imag.img_hei, &d->imag.img_wid);
	if (symb == 'C')
		d->img = mlx_xpm_file_to_image(d->mlx, d->imag.img_money, \
									&d->imag.img_hei, &d->imag.img_wid);
}

void	put_moving_image(char symb, t_vars *d)
{
	if (symb == 'P')
		d->img = mlx_xpm_file_to_image(d->mlx, d->imag.img_hero, \
									&d->imag.img_hei, &d->imag.img_wid);
	if (symb == 'X')
		d->img = mlx_xpm_file_to_image(d->mlx, d->imag.img_cop, \
									&d->imag.img_hei, &d->imag.img_wid);
}

int	random_num(void)
{
	int lower; 
	int upper;
	int num;

	lower = 1;
	upper = 4;

	srand(time(0));
	num = (rand() % (upper - lower + 1)) + lower;
	return (num);
}

