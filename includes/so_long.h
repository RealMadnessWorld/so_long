#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx.h"
#include "colors.h"
#include "keycode_mac.h"
#include "../libft/includes/libft.h"
#include "limits.h"
#include <stdio.h>

/****************************\
*		  Defenitions		 *
\****************************/

# define TITLE "principle vagina"
# define WIN_H 800
# define WIN_W 1200

#define KEYPRESS 2
#define KEYRELEASE 3
#define X_EVENT_KEY_EXIT 17 //exit key code

# define KEY_ESCAPE 53

/****************************\
*		  Structures		 *
\****************************/


/*
**	structure for the map variables
*/

typedef struct	s_map
{
	char	**map;
	int		map_len;
	int		map_wid;
}				t_map;

/*
**	variables for the image
*/

typedef struct	s_img
{
	int		img_hei;
	int		img_wid;
	void	*img_hero;
	void	*img_ground;
	void	*img_border;
	void	*img_money;
	void	*img_cop;
	void	*img_exit;
	int		bpp;
	int		ll;
	int		endn;
}				t_img;

/*
**	general variables
*/

typedef struct	s_variables
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

/****************************\
*	Key handling functions	 *
\****************************/

int		key_handler(int keycode/*, t_param *param*/);


#endif