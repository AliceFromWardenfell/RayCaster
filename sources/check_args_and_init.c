#include "cub3d.h"

void	ident_init(t_d *d)
{
	d->ident.r = 0;
	d->ident.f = 0;
	d->ident.c = 0;
	d->ident.s = 0;
	d->ident.no = 0;
	d->ident.so = 0;
	d->ident.we = 0;
	d->ident.ea = 0;
	d->ident.r_ind = -1;
	d->ident.f_ind = -1;
	d->ident.c_ind = -1;
	d->ident.s_ind = -1;
	d->ident.no_ind = -1;
	d->ident.so_ind = -1;
	d->ident.we_ind = -1;
	d->ident.ea_ind = -1;
}

void	initialization(t_d *d)
{
	d->floor_color = 0;
	d->ceil_color = 0;
	d->parser.map_row = -1;
	d->map_height = 0;
	d->map_lenght = 0;
	d->parser.amount_of_lines = 0;
	d->cube_size = 128;
	d->win = NULL;
	d->img = NULL;
	d->dists = NULL;
	d->items.tiles = NULL;
	d->splitted = NULL;
	d->argv_content = NULL;
	ident_init(d);
}

int	check_saveargv(const char *str1, const char *str2)
{
	if (!str1 || !str2)
		return (0);
	while (*str1 != '\0' || *str2 != '\0')
	{
		if (*str1 != *str2)
			return (0);
		str1++;
		str2++;
	}
	return (1);
}

int	names_checker(char *str1, char *str2, int k)
{
	int		i;
	int		j;
	int		counter;

	if ((!str1) || (!str2))
		return (0);
	counter = 0;
	i = ft_strlen_int(str1) - 1;
	j = ft_strlen_int(str2) - 1;
	if ((i < 0) || (j < 0))
		return (0);
	while ((counter < k) && (i >= 0) && (j >= 0))
	{
		if (str1[i] != str2[j])
			return (0);
		j--;
		i--;
		counter++;
	}
	if (counter < k && i != j && (i < 0 || j < 0))
		return (0);
	return (1);
}

int	check_args(t_d *d, int argc, char **argv)
{
	if (argc >= 4 || argc <= 1)
		return (-1);
	if (argc == 2 && (!argv[0] || !argv[1]))
		return (-1);
	if (argc == 3 && (!argv[0] || !argv[1] || !argv[2]))
		return (-1);
	if ((names_checker(argv[0], "/cub3D", 6)) != 1)
		return (-1);
	if ((names_checker(argv[1], ".cub", 4) && ft_strlen_int(argv[1]) > 4) != 1)
		return (-1);
	if (argc == 2)
		d->save = 0;
	if (argc == 3)
	{
		if (check_saveargv(argv[2], "--save") != 1)
			return (-1);
		d->save = 1;
	}
	return (1);
}
