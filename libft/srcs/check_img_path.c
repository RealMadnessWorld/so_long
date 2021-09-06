#include "libft.h"

char	*chk_img_path(char *path)
{
	if (open((path), O_RDONLY) < 0)
		ft_error(CLR_RED "You're lacking the images... focus please\n" CLR_RST);
	return (path);
}