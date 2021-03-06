/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dealing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarsenio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:57:27 by jarsenio          #+#    #+#             */
/*   Updated: 2021/09/09 18:57:29 by jarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_size(char *map, t_vars *d)
{
	int		fd;
	int		gnl;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error(CLR_RED "Map directory is wrong dumbass...\n");
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
		ft_error(CLR_RED "Map directory is wrong dumbass...\n");
	d->map.map = ft_calloc(d->map.map_wid + 1, sizeof(char *));
	gnl = 1;
	while (gnl == 1)
	{
		gnl = get_next_line(fd, &line);
		d->map.map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	if (gnl == -1)
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
		ft_error(CLR_RED "Missinng elements... Do you need a drawing");
}

void	map_limits(t_vars *d)
{
	int	i;
	int	l;

	i = 0;
	l = (int)ft_strlen(d->map.map[d->map.map_wid - 1]);
	if (l != d->map.map_len)
		ft_error(CLR_RED "The map is open idiot...\n");
	while (d->map.map[0][i])
	{
		if (d->map.map[0][i] != '1')
			ft_error(CLR_RED "The top map is wrong... ugh... Whyyyyyyy???\n");
		i++;
	}
	i = 0;
	while (d->map.map[d->map.map_wid - 1][i])
	{
		if (d->map.map[d->map.map_wid - 1][i] != '1')
			ft_error(CLR_RED "The bot map is wrong... ugh... Whyyyyyyy???\n");
		i++;
	}
}

void	map_body(char *map_line, t_vars *d)
{
	int	i;

	i = 0;
	if ((int)ft_strlen(map_line) != d->map.map_len)
		ft_error(CLR_RED "Map has the wrong shape idiot...");
	if (map_line[0] != '1' || map_line[ft_strlen(map_line) - 1] != '1')
		ft_error(CLR_RED "The map is open on the sides...");
	while (map_line[i])
	{
		if (map_line[i] == 'E')
			d->exit += 1;
		else if (map_line[i] == 'C')
			d->collect += 1;
		else if (map_line[i] == 'P')
			d->pos += 1;
		else if (map_line[i] == '1' || map_line[i] == '0' || \
				map_line[i] == 'X')
			;
		else
			ft_error(CLR_RED "Wrong symbols in the map...");
		i++;
	}
}
