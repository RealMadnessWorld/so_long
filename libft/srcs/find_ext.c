#include "libft.h"

int		find_extention(char *str, char *ext)
{
	int i;
	int x;

	i = ft_strlen(str);
	x = ft_strlen(ext);
	while (i != 0 && str[i] != '.')
	{
		if (str[i] != ext[x])
		{
			return (0);
		}
		i--;
		x--;
	}
	return (1);
}