
#include "../includes/so_long.h"

int	key_handler(int keycode/*, t_param *param*/)
{
	if (keycode == KEY_ESCAPE)
		exit (0);
	return (0);
}