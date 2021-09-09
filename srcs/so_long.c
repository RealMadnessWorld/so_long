#include "so_long.h"

void	so_long(t_vars *d)
{
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, d->map.map_len * 64,
							d->map.map_wid * 64, TITLE);
	map_building(d);
	mlx_hook(d->win, KEYPRESS, 0, &key_handler, d);
	mlx_hook(d->win, X_EVENT_KEY_EXIT, 1L << 2, &close_x_button, d);
	//mlx_loop_hook(d->mlx, enemy_move, d);
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

int	close_win(t_vars *d, char code)
{
	mlx_destroy_window(d->mlx, d->win);
	if (code == 'E')
		ft_putendl_fd("How dare you close me >:[", 1);
	else if (code == 'W')
		ft_putendl_fd("You won an ez game... yay...", 1);
	else if (code == 'L')
		ft_putendl_fd("You lost... How? Like... HOW?", 1);
	exit(EXIT_SUCCESS);
}

int	close_x_button(t_vars *d)
{
	mlx_destroy_window(d->mlx, d->win);
	ft_putendl_fd("How dare you close me >:[", 1);
	exit(EXIT_SUCCESS);
}