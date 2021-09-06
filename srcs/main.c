#include "so_long.h"

void	init_vars(t_vars *d)
{
	d->map.map_len = 0;
	d->map.map_wid = 0;
	d->exit = 0;
	d->collect = 0;
	d->frame = 0;
	d->pos = 0;
	d->steps = 0;
	d->time = 0;
	d->imag.img_hei = 0;
	d->imag.img_wid = 0;
	d->imag.img_border = chk_img_path("./images/border.xpm");
	d->imag.img_hero = chk_img_path("./images/hero.xpm");
	d->imag.img_ground = chk_img_path("./images/ground.xpm");
	d->imag.img_cop = chk_img_path("./images/enemy.xpm");
	d->imag.img_money = chk_img_path("./images/collectible.xpm");
	d->imag.img_exit = chk_img_path("./images/exit.xpm");
}

void	checker(int argc, char **argv)
{
	if (argc == 1)
		ft_error(CLR_RED "Oi... I need a map...\n");
	if (argc > 2)
		ft_error(CLR_RED "3 arguments? Really? You want me to work or not?\n");
	if (!find_extention(argv[1], ".ber"))
		ft_error(CLR_RED "that's not a map -.-\"\n");
}

int	main(int argc, char **argv)
{
	t_vars	d;

	checker(argc, argv);
	init_vars(&d);
	map_size(argv[1], &d);
	map_parser(argv[1], &d);
	map_checker(&d);
	printf("hi\n");
	so_long(&d);
	return (0);
}