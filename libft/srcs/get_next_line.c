/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarsenio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:16:04 by jarsenio          #+#    #+#             */
/*   Updated: 2021/03/23 16:16:18 by jarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*ft_strjoingnl(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlengnl(s1) + ft_strlengnl(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlengnl(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdupgnl(const char *str)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc(sizeof(*str) * (ft_strlengnl(str) + 1));
	if (!ptr)
		return (NULL);
	while (str[i] != '\0')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strchrgnl(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == 0)
			return (0);
		s++;
	}
	return ((char *)s);
}

char	*ft_substrgnl(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlengnl(s);
	if (start >= s_len)
	{
		p = malloc(sizeof(char));
		if (!p)
			return (0);
		*p = '\0';
		return (p);
	}
	if (s_len < len)
		return (ft_strdupgnl(s + start));
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (start < s_len && i < len)
		p[i++] = s[start++];
	p[i] = '\0';
	return (p);
}

int		gnl_lines(int fd, char **line, char **hotline)
{
	int		i;
	char	*temp;

	i = 0;
	while (hotline[fd][i] != '\n' && hotline[fd][i] != '\0')
		i++;
	if (hotline[fd][i] == '\n')
	{
		*line = ft_substrgnl(hotline[fd], 0, i);
		temp = ft_substrgnl(hotline[fd], i + 1, ft_strlengnl(hotline[fd]) - 1);
		free(hotline[fd]);
		hotline[fd] = temp;
		return (1);
	}
	else
	{
		*line = ft_substrgnl(hotline[fd], 0, i);
		free(hotline[fd]);
		hotline[fd] = 0;
		return (0);
	}
}

int		gnl_returns(int fd, char **line, char **hotline, int i)
{
	if (i == -1)
		return (-1);
	if (!hotline[fd] && !i)
	{
		*line = ft_strdupgnl("");
		return (0);
	}
	else
		return (gnl_lines(fd, line, hotline));
}

int		get_next_line(int fd, char **line)
{
	static char		*hotline[10000];
	char			buf[BUFFER_SIZE + 1];
	char			*temp;
	int				i;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while ((i = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[i] = '\0';
		if (!hotline[fd])
			hotline[fd] = ft_strdupgnl("");
		temp = ft_strjoingnl(hotline[fd], buf);
		free(hotline[fd]);
		hotline[fd] = temp;
		if (ft_strchrgnl(hotline[fd], '\n'))
			break ;
	}
	return (gnl_returns(fd, line, hotline, i));
}
