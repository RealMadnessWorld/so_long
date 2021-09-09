/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarsenio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:57:42 by jarsenio          #+#    #+#             */
/*   Updated: 2021/09/09 18:57:44 by jarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(t_vars *d)
{
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, d->map.map_len * 64, \
							d->map.map_wid * 64, TITLE);
	map_building(d);
	mlx_hook(d->win, KEYPRESS, 0, &key_handler, d);
	mlx_hook(d->win, X_EVENT_KEY_EXIT, 1L << 2, &close_x_button, d);
	mlx_loop_hook(d->mlx, enemy_move, d);
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
		ft_putendl_fd(CLR_RED "How dare you close me >:[", 1);
	else if (code == 'W')
		ft_putendl_fd(CLR_GRN "You won an ez game... yay...", 1);
	else if (code == 'L')
		ft_putendl_fd(CLR_RED "You lost... How? Like... HOW?", 1);
	d->count = ft_itoa(d->steps);
	ft_putstr_fd("steps:  ", 1);
	ft_putendl_fd(d->count, 1);
	exit(EXIT_SUCCESS);
}

int	close_x_button(t_vars *d)
{
	mlx_destroy_window(d->mlx, d->win);
	ft_putendl_fd(CLR_RED "How dare you close me >:[", 1);
	exit(EXIT_SUCCESS);
}

void	step_counter(t_vars *d)
{
	char	*count;

	count = ft_itoa(d->steps);
	image_put('1', d, 0, 1);
	image_put('1', d, 0, 0);
	mlx_string_put(d->mlx, d->win, 10, 20, WHITE, "steps: ");
	mlx_string_put(d->mlx, d->win, 80, 20, WHITE, count);
	free(count);
}
