/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarsenio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:09:35 by jarsenio          #+#    #+#             */
/*   Updated: 2021/03/05 20:12:15 by jarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		counter(char const *s, char c)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	if (s[i] != c)
		word++;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			while (s[i] == c && s[i] != '\0')
				i++;
			if (s[i] != '\0')
				word++;
		}
		else
			i++;
	}
	return (word);
}

char			**ft_split(char const *s, char c)
{
	char	**dst;
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (!(dst = (char **)malloc(sizeof(char *) * counter(s, c) + 1)))
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			str = (char *)s;
			while (*s && *s != c)
				s++;
			if (!(dst[i] = (char *)malloc(s - str + 1)))
				return (0);
			ft_strlcpy(dst[i++], str, s - str + 1);
		}
		else
			s++;
	}
	dst[i] = 0;
	return (dst);
}
