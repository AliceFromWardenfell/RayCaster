#include "cub3d.h"

int	check_argv_4(t_d *d, int i)
{
	if (d->ident.no_ind > i || d->ident.r_ind > i || d->ident.s_ind > i || \
		d->ident.so_ind > i || d->ident.f_ind > i || d->ident.c_ind > i || \
		d->ident.we_ind > i || d->ident.ea_ind > i)
		return (-1);
	if (d->ident.no_ind + d->ident.so_ind + d->ident.we_ind + d->ident.r_ind + \
		d->ident.ea_ind + d->ident.s_ind + d->ident.f_ind + d->ident.c_ind != \
		sum_ints(i))
		return (-1);
	if (d->splitted[d->ident.r_ind][0] != 'R' || d->splitted[d->ident.r_ind][1] != ' ' ||\
		if_line_valid(d->splitted[d->ident.r_ind], "R 0123456789", 0, -1) != 1 || \
		if_sym_valid(d->splitted[d->ident.r_ind], 'R') != 1)
		return (-1);
	if (d->splitted[d->ident.f_ind][0] != 'F' || d->splitted[d->ident.f_ind][1] != ' ' ||\
		if_line_valid(d->splitted[d->ident.f_ind], "F ,0123456789", 0, -1) != 1 || \
		if_sym_valid(d->splitted[d->ident.f_ind], 'F') != 1)
		return (-1);
	if (d->splitted[d->ident.c_ind][0] != 'C' || d->splitted[d->ident.c_ind][1] != ' ' ||\
		if_line_valid(d->splitted[d->ident.c_ind], "C ,0123456789", 0, -1) != 1 || \
		if_sym_valid(d->splitted[d->ident.c_ind], 'C') != 1)
		return (-1);
	if ((if_sym_valid(d->splitted[d->ident.f_ind], ',') != 2) || \
		(if_sym_valid(d->splitted[d->ident.c_ind], ',') != 2))
		return (-1);
	return (0);
}

int	check_argv_3(t_d *d)
{
	int		i;

	i = 0;
	while (d->splitted[i] != NULL)
	{
		if (d->splitted[i][0] == 'R')
			d->ident.r_ind = i;
		else if (d->splitted[i][0] == 'F')
			d->ident.f_ind = i;
		else if (d->splitted[i][0] == 'C')
			d->ident.c_ind = i;
		else if (d->splitted[i][0] == 'S' && d->splitted[i][1] == ' ')
			d->ident.s_ind = i;
		else if (d->splitted[i][0] == 'N' && d->splitted[i][1] == 'O')
			d->ident.no_ind = i;
		else if (d->splitted[i][0] == 'S' && d->splitted[i][1] == 'O')
			d->ident.so_ind = i;
		else if (d->splitted[i][0] == 'W' && d->splitted[i][1] == 'E')
			d->ident.we_ind = i;
		else if (d->splitted[i][0] == 'E' && d->splitted[i][1] == 'A')
			d->ident.ea_ind = i;
		i++;
	}
	return (check_argv_4(d, 7));
}

int	check_argv_2(t_d *d)
{
	if (d->ident.r != 1 || d->ident.f != 1 || d->ident.c != 1 || \
		d->ident.s != 1 || d->ident.no != 1 || d->ident.so != 1 || \
		d->ident.we != 1 || d->ident.ea != 1)
		return (-1);
	if (d->parser.amount_of_lines < 11)
		return (-1);
	return (0);
}

int	check_argv_1(t_d *d)
{
	int		i;

	i = 0;
	while (d->splitted[i] != NULL)
	{
		if (d->splitted[i][0] == 'R')
			d->ident.r += 1;
		else if (d->splitted[i][0] == 'F')
			d->ident.f += 1;
		else if (d->splitted[i][0] == 'C')
			d->ident.c += 1;
		else if (d->splitted[i][0] == 'S' && d->splitted[i][1] == ' ')
			d->ident.s += 1;
		else if (d->splitted[i][0] == 'N' && d->splitted[i][1] == 'O')
			d->ident.no += 1;
		else if (d->splitted[i][0] == 'S' && d->splitted[i][1] == 'O')
			d->ident.so += 1;
		else if (d->splitted[i][0] == 'W' && d->splitted[i][1] == 'E')
			d->ident.we += 1;
		else if (d->splitted[i][0] == 'E' && d->splitted[i][1] == 'A')
			d->ident.ea += 1;
		i++;
	}
	d->parser.amount_of_lines = i;
	return (check_argv_2(d));
}

int	parser(t_d *d, char **argv)
{
	if (reading_from_fd(d, argv) == -1)
		return (-1);
	d->splitted = ft_split(d->argv_content, '\n', 0, 0);
	if (!d->splitted)
		return (global_free(d, 1));
	if (check_argv_1(d) == -1)
		return (global_free(d, 3));
	if (check_argv_3(d) == -1)
		return (global_free(d, 3));
	if (map_check_and_measure(d) == -1)
		return (global_free(d, 3));
	if (map_check(d) == -1)
		return (global_free(d, 3));
	global_free(d, 0);
	if (set_ident(d) == -1)
		return (global_free(d, 2));
	if (!map_parser(d))
		return (global_free(d, 2));
	return (0);
}
