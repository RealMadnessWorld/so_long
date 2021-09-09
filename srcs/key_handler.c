/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarsenio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:57:07 by jarsenio          #+#    #+#             */
/*   Updated: 2021/09/09 18:57:10 by jarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_handler(int keycode, t_vars *d)
{
	if (keycode == KEY_ESCAPE)
		close_win(d, 'E');
	else if (keycode == KEY_W)
		check_move(d, 0, -1);
	else if (keycode == KEY_A)
		check_move(d, -1, 0);
	else if (keycode == KEY_S)
		check_move(d, 0, 1);
	else if (keycode == KEY_D)
		check_move(d, 1, 0);
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
			if (d->collect == 0)
				open_exit(d);
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
	d->steps++;
	step_counter(d);
}

void	open_exit(t_vars *d)
{
	int	w;
	int	l;

	w = 0;
	while (d->map.map[w])
	{
		l = 0;
		while (d->map.map[w][l])
		{
			if (d->map.map[w][l] == 'E')
				image_put('E', d, w, l);
			l++;
		}
		w++;
	}
}
