/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarsenio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:53:44 by jarsenio          #+#    #+#             */
/*   Updated: 2021/03/05 19:54:55 by jarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char		*ft_swap(char *s)
{
	int		i;
	int		leng;
	char	temp;

	leng = ft_strlen(s);
	i = 0;
	while (i < leng / 2)
	{
		temp = s[i];
		s[i] = s[leng - i - 1];
		s[leng - i - 1] = temp;
		i++;
	}
	return (s);
}

char			*ft_itoa(int n)
{
	int		sign;
	int		i;
	char	str[12];

	i = 0;
	ft_memset(str, 0, 12);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	sign = (n < 0) ? -1 : 1;
	n = (n < 0) ? -n : n;
	while (n > 0)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (sign < 0)
		str[i] = '-';
	ft_swap(str);
	return (ft_strdup(str));
}
