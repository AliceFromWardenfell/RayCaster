#include "cub3d.h"

int	reading_from_fd(t_d *d, char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	if (read(fd, NULL, 0) < 0)
		return (-1);
	d->argv_content = read_argv(fd, BUF_SIZE, NULL, NULL);
	if (!d->argv_content)
		return (-1);
	close(fd);
	return (0);
}

int	map_check_and_measure(t_d *d)
{
	int		i;
	int		j;

	i = 8;
	while (i < d->parser.amount_of_lines)
	{
		j = 0;
		while (d->splitted[i][j] != '\0')
		{
			if (d->splitted[i][j] == '0' || d->splitted[i][j] == 'N' || \
				d->splitted[i][j] == '1' || d->splitted[i][j] == 'S' || \
				d->splitted[i][j] == '2' || d->splitted[i][j] == 'W' || \
				d->splitted[i][j] == ' ' || d->splitted[i][j] == 'E')
				j++;
			else
				return (-1);
		}
		i++;
	}
	d->map_height = (d->parser.amount_of_lines - 8);
	d->parser.map_row = 8;
	return (0);
}

int	amount_of_ident_newlines(char *str)
{
	int		i;
	int		k;
	int		len_curr;

	if (!str)
		return (-1);
	i = 0;
	k = 0;
	len_curr = 0;
	while (k < 8 && str[i] != '\0')
	{
		if (str[i] != '\n')
			len_curr++;
		if (str[i] == '\n' && len_curr != 0)
		{
			k++;
			len_curr = 0;
		}
		i++;
	}
	while (str[i] == '\n')
		i++;
	if (k != 8)
		return (-1);
	return (i);
}

int	amount_of_map_newlines(char *str, int map_rows_amount, int i)
{
	int		k;

	if (!str)
		return (-1);
	k = 0;
	while (k < map_rows_amount && str[i] != '\0')
	{
		if (str[i] != '\n' && str[i - 1] == '\n')
			k++;
		else if (str[i] == '\n' && str[i - 1] == '\n')
			break ;
		i++;
	}
	if (k != map_rows_amount)
		return (-1);
	return (0);
}

int	map_check(t_d *d)
{
	int		i;

	i = amount_of_ident_newlines(d->argv_content);
	if (i < 2)
		return (-1);
	if ((amount_of_map_newlines(d->argv_content, d->map_height, i)) == -1)
		return (-1);
	return (0);
}
