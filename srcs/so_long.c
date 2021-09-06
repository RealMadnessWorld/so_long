#include "so_long.h"

void	so_long(t_vars *d)
{
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, d->map.map_len * 64,
							d->map.map_wid * 64, TITLE);
	map_building(d);
	mlx_hook(d->win, KEYPRESS, 0, &key_handler, &d);
	mlx_loop(d->mlx);
}

void	map_building(t_vars *d)
{
	int	w;
	int	l;

	w = 0;
	while (d->map.map[w])
	{
		l = 0;
		while (d->map.map[w][l])
		{
			image_put(d->map.map[w][l], d, w, l);
			l++;
		}
		w++;
	}
}