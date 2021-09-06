#include "so_long.h"

void	map_size(char *map, t_vars *d)
{
	int		fd;
	int		gnl;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error("Map directory is wrong dumbass...\n");
	gnl = 1;
	while (gnl == 1)
	{
		gnl = get_next_line(fd, &line);
		free(line);
		d->map.map_wid += 1;
	}
	if (gnl == -1)
		ft_error(CLR_RED "Gnl error... A mess as always...\n");
	close(fd);
}

void	map_parser(char *map, t_vars *d)
{
	int		fd;
	int		gnl;
	int		i;
	char	*line;

	i = 0;
	fd = open((map), O_RDONLY);
	if (fd < 0)
		ft_error("Map directory is wrong dumbass...\n");
	d->map.map = ft_calloc(d->map.map_wid + 1, sizeof(char *));
	gnl = 1;
	while (gnl == 1)
	{
		gnl = get_next_line(fd, &line);
		d->map.map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	if(gnl == -1)
		ft_error(CLR_RED "Gnl error... A mess as always\n");
	close(fd);
}

void	map_checker(t_vars *d)
{
	int	i;

	i = 1;
	d->map.map_len = (int)ft_strlen(d->map.map[0]);
	map_limits(d);
	while (i < d->map.map_wid)
	{
		map_body(d->map.map[i], d);
		i++;
	}
	if (d->exit == 0 || d->collect == 0 || d->pos != 1)
		ft_error("Missinng elements... Do you need a drawing");
	if (d->map.map_wid > 17 || d->map.map_len > 39)
		ft_error("The map is too big");
}

void	map_limits(t_vars *d)
{
	int	i;
	int l = (int)ft_strlen(d->map.map[d->map.map_wid - 1]);

	i = 0;
	if (l != d->map.map_len)
		ft_error("The map is open idiot...\n");
	while (d->map.map[0][i])
	{
		if (d->map.map[0][i] != '1')
			ft_error("The top map is wrong... ugh... Whyyyyyyy???\n");
		i++;
	}
	i = 0;
	while (d->map.map[d->map.map_wid - 1][i])
	{
		if (d->map.map[d->map.map_wid - 1][i] != '1')
			ft_error("The bot map is wrong... ugh... Whyyyyyyy???\n");
		i++;
	}
}

void	map_body(char *map_line, t_vars *d)
{
	int	i;

	i = 0;
	if ((int)ft_strlen(map_line) != d->map.map_len)
		ft_error("Map has the wrong shape idiot...");
	if (map_line[0] != '1' || map_line[ft_strlen(map_line) - 1] != '1')
		ft_error("The map is open on the sides...");
	while (map_line[i])
	{
		if (map_line[i] == 'E')
			d->exit += 1;
		else if (map_line[i] == 'C')
			d->collect += 1;
		else if (map_line[i] == 'P')
			d->pos += 1;
		else if (map_line[i] == '1' || map_line[i] == '0' ||
				map_line[i] == 'D')
			;
		else
			ft_error("Wrong symbols in the map...");
		i++;
	}
}