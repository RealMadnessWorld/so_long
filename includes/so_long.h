/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarsenio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 19:07:04 by jarsenio          #+#    #+#             */
/*   Updated: 2021/09/09 19:07:06 by jarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "colors.h"
# include "keycode_mac.h"
# include "../libft/includes/libft.h"
# include "limits.h"
# include "time.h"
# include <stdio.h>

/****************************\
*		  Defenitions		 *
\****************************/

# define TITLE "principle vagina"
# define WIN_H 800
# define WIN_W 1200
# define KEYPRESS 2
# define KEYRELEASE 3
# define X_EVENT_KEY_EXIT 17

# define KEY_ESCAPE 53

/****************************\
*		  Structures		 *
\****************************/

/*
**	structure for the map variables
*/

typedef struct s_map
{
	char	**map;
	int		map_len;
	int		map_wid;
}				t_map;

/*
**	variables for the image
*/

typedef struct s_img
{
	int		img_hei;
	int		img_wid;
	void	*img_hero;
	void	*img_ground;
	void	*img_border;
	void	*img_money;
	void	*img_cop;
	void	*img_exit_c;
	void	*img_exit_o;
	int		bpp;
	int		ll;
	int		endn;
}				t_img;

/*
** general variables
*/

typedef struct s_variables
{
	void	*mlx;
	void	*win;
	void	*img;
	t_map	map;
	t_img	imag;
	int		exit;
	int		collect;
	int		pos;
	int		steps;
	int		frame;
	int		time;
	int		pos_x;
	int		pos_y;
	int		e_pos_x;
	int		e_pos_y;
	char	*count;
}				t_vars;

/****************************\
*		Main functions		 *
\****************************/

void	so_long(t_vars *d);
void	checker(int argc, char **argv);
void	init_vars(t_vars *d);

/****************************\
*		 Map functions		 *
\****************************/

void	map_size(char *map, t_vars *d);
void	map_parser(char *map, t_vars *d);
void	map_checker(t_vars *d);
void	map_limits(t_vars *d);
void	map_body(char *map_line, t_vars *d);
void	put_static_image(char symb, t_vars *d);
void	put_moving_image(char symb, t_vars *d);
void	image_put(char symb, t_vars *d, int y, int x);
void	map_building(t_vars *d);
void	open_exit(t_vars *d);

/****************************\
*		 Move functions		 *
\****************************/

int		key_handler(int keycode, t_vars *d);
void	check_move(t_vars *d, int x, int y);
void	move(t_vars *d, int x, int y);
int		enemy_move(t_vars *d);
int		e_move_handler(int num, t_vars *d);
void	e_check_move(t_vars *d, int x, int y);
void	e_move(t_vars *d, int x, int y);

/****************************\
*			Utils			 *
\****************************/

int		close_x_button(t_vars *d);
int		close_win(t_vars *d, char code);
void	step_counter(t_vars *d);

#endif
