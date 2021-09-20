#include "cub3d.h"

int	counter(int number)
{
	int		rez;

	rez = 0;
	if (!number)
		return (1);
	while (number > 0)
	{
		number /= 10;
		rez++;
	}
	return (rez);
}

int	counter_s(char *str)
{
	int		i;
	int		rez;

	if (!str)
		return (-1);
	i = 0;
	rez = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			rez++;
		i++;
	}
	return (rez);
}

long	first_app_index(char *str, char c)
{
	long	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}

long	last_app_index(char *str, char c)
{
	long	i;

	if (!str)
		return (-1);
	i = (long)ft_strlen(str);
	while (str[i] != c && i > 0)
		i--;
	if (str[i] == c)
		return (i);
	return (-1);
}

int	atoi_color(char *str, long int i)
{
	int		rez;

	rez = 0;
	if (!str)
		return (-1);
	if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ')
		return (-1);
	while (str[i] == ' ')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (-1);
	while (str[i] >= '0' && str[i] <= '9' && rez < 65536)
	{
		rez = rez * 10 + (str[i] - 48);
		i++;
	}
	if (rez < 0 || rez > 255)
		return (-1);
	return (rez);
}
