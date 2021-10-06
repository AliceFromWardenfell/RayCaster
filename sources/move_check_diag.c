#include "cub3d.h"

int	four_ifs_for_check_diag(t_d *d, int x, int y, int lever)
{
	if (lever == 1)
		return (d->level_map[d->map_lenght * (y - 1) + x] > 0
			&& d->level_map[y * d->map_lenght + x - 1] > 0
			&& d->level_map[d->map_lenght * (d->y_diag + 1) + d->x_diag] > 0
			&& d->level_map[d->y_diag * d->map_lenght + d->x_diag + 1] > 0);
	if (lever == 2)
		return (d->level_map[d->map_lenght * (y + 1) + x] > 0
			&& d->level_map[y * d->map_lenght + x - 1] > 0
			&& d->level_map[d->map_lenght * (d->y_diag - 1) + d->x_diag] > 0
			&& d->level_map[d->y_diag * d->map_lenght + d->x_diag + 1] > 0);
	if (lever == 3)
		return (d->level_map[d->map_lenght * (y - 1) + x] > 0
			&& d->level_map[y * d->map_lenght + x + 1] > 0
			&& d->level_map[d->map_lenght * (d->y_diag + 1) + d->x_diag] > 0
			&& d->level_map[d->y_diag * d->map_lenght + d->x_diag - 1] > 0);
	if (lever == 4)
		return (d->level_map[d->map_lenght * (y + 1) + x] > 0
			&& d->level_map[y * d->map_lenght + x + 1] > 0
			&& d->level_map[d->map_lenght * (d->y_diag - 1) + d->x_diag] > 0
			&& d->level_map[d->y_diag * d->map_lenght + d->x_diag - 1] > 0);
	return (0);
}

int	check_diag_w(t_d *d, int x, int y)
{
	int		check;

	check = 0;
	d->x_diag = d->x_current >> CUBE_POW;
	d->y_diag = d->y_current >> CUBE_POW;
	if (d->dx > 0 && d->dy > 0)
		if (four_ifs_for_check_diag(d, x, y, 1))
			check = 1;
	if (d->dx > 0 && d->dy < 0)
		if (four_ifs_for_check_diag(d, x, y, 2))
			check = 1;
	if (d->dx < 0 && d->dy > 0)
		if (four_ifs_for_check_diag(d, x, y, 3))
			check = 1;
	if (d->dx < 0 && d->dy < 0)
		if (four_ifs_for_check_diag(d, x, y, 4))
			check = 1;
	return (check);
}

int	check_diag_s(t_d *d, int x, int y)
{
	int		check;

	check = 0;
	d->x_diag = d->x_current >> CUBE_POW;
	d->y_diag = d->y_current >> CUBE_POW;
	if (d->dx < 0 && d->dy < 0)
		if (four_ifs_for_check_diag(d, x, y, 1))
			check = 1;
	if (d->dx < 0 && d->dy > 0)
		if (four_ifs_for_check_diag(d, x, y, 2))
			check = 1;
	if (d->dx > 0 && d->dy < 0)
		if (four_ifs_for_check_diag(d, x, y, 3))
			check = 1;
	if (d->dx > 0 && d->dy > 0)
		if (four_ifs_for_check_diag(d, x, y, 4))
			check = 1;
	return (check);
}

int	check_diag_a(t_d *d, int x, int y)
{
	int		check;

	check = 0;
	d->x_diag = d->x_current >> CUBE_POW;
	d->y_diag = d->y_current >> CUBE_POW;
	if (d->dx < 0 && d->dy > 0)
		if (four_ifs_for_check_diag(d, x, y, 1))
			check = 1;
	if (d->dx < 0 && d->dy < 0)
		if (four_ifs_for_check_diag(d, x, y, 2))
			check = 1;
	if (d->dx > 0 && d->dy > 0)
		if (four_ifs_for_check_diag(d, x, y, 3))
			check = 1;
	if (d->dx > 0 && d->dy < 0)
		if (four_ifs_for_check_diag(d, x, y, 4))
			check = 1;
	return (check);
}

int	check_diag_d(t_d *d, int x, int y)
{
	int		check;

	check = 0;
	d->x_diag = d->x_current >> CUBE_POW;
	d->y_diag = d->y_current >> CUBE_POW;
	if (d->dx > 0 && d->dy < 0)
		if (four_ifs_for_check_diag(d, x, y, 1))
			check = 1;
	if (d->dx > 0 && d->dy > 0)
		if (four_ifs_for_check_diag(d, x, y, 2))
			check = 1;
	if (d->dx < 0 && d->dy < 0)
		if (four_ifs_for_check_diag(d, x, y, 3))
			check = 1;
	if (d->dx < 0 && d->dy > 0)
		if (four_ifs_for_check_diag(d, x, y, 4))
			check = 1;
	return (check);
}
