#include "libft.h"

void	ft_error(char *error)
{
	ft_putstr_fd(error, 1);
	exit (EXIT_FAILURE);
}