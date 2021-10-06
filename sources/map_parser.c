#include "cub3d.h"

int	check_double_spawn(t_d *d)
{
	int		amount_of_spawns;
	int		i;
	int		j;

	amount_of_spawns = 0;
	i = 0;
	while (i < d->map_height)
	{
		j = 0;
		while (j < d->map_lenght)
		{
			if (d->level_map[i * d->map_lenght + j] == 3
				|| d->level_map[i * d->map_lenght + j] == 4
				|| d->level_map[i * d->map_lenght + j] == 5
				|| d->level_map[i * d->map_lenght + j] == 6)
				amount_of_spawns++;
			j++;
		}
		i++;
	}
	if (amount_of_spawns != 1)
		return (free_level_map(d));
	return (1);
}

int	is_near_space_is_wall(t_d *d, int i, int j, int lever)
{
	if (lever)
		return (d->level_map[d->map_lenght * (i + 1) + j] == 7
			|| d->level_map[d->map_lenght * (i - 1) + j] == 7
			|| d->level_map[i * d->map_lenght + j + 1] == 7
			|| d->level_map[i * d->map_lenght + j - 1] == 7);
	else
		return (d->level_map[i * d->map_lenght + j] == 0
			|| d->level_map[i * d->map_lenght + j] == 2
			|| d->level_map[i * d->map_lenght + j] == 3
			|| d->level_map[i * d->map_lenght + j] == 4
			|| d->level_map[i * d->map_lenght + j] == 5
			|| d->level_map[i * d->map_lenght + j] == 6);
}

int	validate_map(t_d *d, int i, int j)
{
	while (i < d->map_height)
	{
		j = 0;
		while (j < d->map_lenght)
		{
			if (i == 0 || i == d->map_lenght - 1
				|| j == 0 || j == d->map_lenght - 1)
			{
				if (d->level_map[i * d->map_lenght + j] != 1
					&& d->level_map[i * d->map_lenght + j] != 7)
					return (free_level_map(d));
			}
			else
			{
				if (is_near_space_is_wall(d, i, j, 0))
					if (is_near_space_is_wall(d, i, j, 1))
						return (free_level_map(d));
			}
			j++;
		}
		i++;
	}
	return (check_double_spawn(d));
}

int	atoi_map(t_d *d, char *src, int j, int i)
{
	int		map_len;

	map_len = ft_strlen_int(src);
	if (map_len > d->map_lenght || map_len == -1)
		return (-1);
	while (++i < map_len)
	{
		if (src[i] == 'N')
			d->level_map[d->map_lenght * j + i] = 3;
		else if (src[i] == 'S')
			d->level_map[d->map_lenght * j + i] = 4;
		else if (src[i] == 'W')
			d->level_map[d->map_lenght * j + i] = 5;
		else if (src[i] == 'E')
			d->level_map[d->map_lenght * j + i] = 6;
		else if (src[i] == '0' || src[i] == '1' || src[i] == '2')
			d->level_map[d->map_lenght * j + i] = (int)(src[i] - 48);
		else if (src[i] == ' ')
			d->level_map[d->map_lenght * j + i] = 7;
		else
			return (-1);
	}
	while (i < d->map_lenght)
		d->level_map[d->map_lenght * j + i++] = 7;
	return (0);
}

int	map_parser(t_d *d)
{
	int		i;
	int		j;

	i = d->parser.map_row - 1;
	while (++i < d->parser.amount_of_lines)
	{
		j = -1;
		while (d->splitted[i][++j] != '\0')
			if (d->map_lenght < j)
				d->map_lenght = j;
	}
	d->map_lenght++;
	if (d->map_height < 3 || d->map_lenght < 3)
		return (0);
	d->level_map = ft_calloc(d->map_height * d->map_lenght, sizeof(int));
	if (!d->level_map)
		return (0);
	i = d->parser.map_row - 1;
	while (++i < d->parser.amount_of_lines)
	{
		if (atoi_map(d, d->splitted[i], i - d->parser.map_row, -1) == -1)
			return (free_level_map(d));
	}
	i = 0;
	return (validate_map(d, 0, 0));
}
