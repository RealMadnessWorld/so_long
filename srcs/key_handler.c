
#include "../includes/so_long.h"

int	key_handler(int keycode, t_vars *d)
{
	if (keycode == KEY_ESCAPE)
		close_win(d, 'E');
	else if (keycode == KEY_W)
		;
	else if (keycode == KEY_A)
		;
	else if (keycode == KEY_S)
		;
	else if (keycode == KEY_D)
		;
	return (0);
}

void	check_move(t_vars *d, int x, int y)
{
	if (d->map.map[d->pos_y + y][d->pos_x + x] != '1')
	{
		if (d->map.map[d->pos_y + y][d->pos_x + x] == 'X')
			close_win(d, 'L');
		else if (d->map.map[d->pos_y + y][d->pos_x + x] == 'E'
				&& d->collect == 0)
			close_win(d, 'W');
		else if (d->map.map[d->pos_y + y][d->pos_x + x] == 'C')
		{
			move(d, x, y);
			d->collect -= 1;
		}
		else if (d->map.map[d->pos_y + y][d->pos_x + x] == '0')
			move(d, x, y);
	}
}

void	move(t_vars *d, int x, int y)
{
	d->map.map[d->pos_y][d->pos_x] = '0';
	image_put('0', d, d->pos_y, d->pos_x);
	d->map.map[d->pos_y + y][d->pos_x + x] = 'P';
	image_put('P', d, d->pos_y + y, d->pos_x + x);
}