#include "cub3d.h"

void	ft_bzero(void *str, size_t n)
{
	if (n != 0)
	{
		while (n != 0)
		{
			((char *)str)[n - 1] = 0;
			n--;
		}
		((char *)str)[0] = 0;
	}
}

int	ft_strlen_int(const char *s)
{
	int		i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
