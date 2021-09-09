#include "so_long.h"

int	e_move_handler(int num, t_vars *d)
{
	if (num >= 1 && num <= 25)
		e_check_move(d, 0, -1);
	else if (num >= 26 && num <= 50)
		e_check_move(d, -1, 0);
	else if (num >= 51 && num <= 75)
		e_check_move(d, 0, 1);
	else if (num >= 76 && num <= 100)
		e_check_move(d, 1, 0);
	return (0);
}

void	e_check_move(t_vars *d, int x, int y)
{
	if (d->map.map[d->pos_y][d->pos_x] == 'X')
		close_win(d, 'L');
	if (d->map.map[d->e_pos_y + y][d->e_pos_x + x] != '1' && \
		d->map.map[d->e_pos_y + y][d->e_pos_x + x] != 'C')
			e_move(d, x, y);
}

void	e_move(t_vars *d, int x, int y)
{
	d->map.map[d->e_pos_y][d->e_pos_x] = '0';
	image_put('0', d, d->e_pos_y, d->e_pos_x);
	d->map.map[d->e_pos_y + y][d->e_pos_x + x] = 'X';
	image_put('X', d, d->e_pos_y + y, d->e_pos_x + x);
}

int	enemy_move(t_vars *d)
{
	if ((double)(clock()) / CLOCKS_PER_SEC - d->time >= (double)1 / 10)
	{
		d->frame++;
		d->time = (double)(clock()) / CLOCKS_PER_SEC;
	}
	if (d->frame >= 2000)
		d->frame = 0;
	if (d->frame == 1999)
		e_move_handler(random_num(), d);
	return (0);
}