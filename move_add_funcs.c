#include "cub3d.h"

void	move_w_if(t_d *d, int tile_x, int tile_y)
{
	if (d->level_map[tile_y * d->map_lenght + tile_x] == 0
		|| d->level_map[tile_y * d->map_lenght + tile_x] > 2)
	{
		if (!check_diag_w(d, tile_x, tile_y))
		{
			d->x_current += d->dx;
			d->y_current += d->dy;
		}
	}
	else if (d->level_map[tile_y * d->map_lenght
			+ (d->x_current >> CUBE_POW)] == 0
		|| d->level_map[tile_y * d->map_lenght
			+ (d->x_current >> CUBE_POW)] > 2)
	{
		if (!check_diag_w(d, d->x_current >> CUBE_POW, tile_y))
			d->y_current += d->dy;
	}
	else if (d->level_map[d->map_lenght
			+ tile_x * (d->y_current >> CUBE_POW)] == 0
		|| d->level_map[d->map_lenght
			+ tile_x * (d->y_current >> CUBE_POW)] > 2)
	{
		if (!check_diag_w(d, tile_x, d->y_current >> CUBE_POW))
			d->x_current += d->dx;
	}
}

void	move_s_if(t_d *d, int tile_x, int tile_y)
{
	if (d->level_map[tile_y * d->map_lenght + tile_x] == 0
		|| d->level_map[tile_y * d->map_lenght + tile_x] > 2)
	{
		if (!check_diag_s(d, tile_x, tile_y))
		{
			d->x_current -= d->dx;
			d->y_current -= d->dy;
		}
	}
	else if (d->level_map[tile_y * d->map_lenght
			+ (d->x_current >> CUBE_POW)] == 0
		|| d->level_map[tile_y * d->map_lenght
			+ (d->x_current >> CUBE_POW)] > 2)
	{
		if (!check_diag_s(d, d->x_current >> CUBE_POW, tile_y))
			d->y_current -= d->dy;
	}
	else if (d->level_map[d->map_lenght
			+ tile_x * (d->y_current >> CUBE_POW)] == 0
		|| d->level_map[d->map_lenght
			+ tile_x * (d->y_current >> CUBE_POW)] > 2)
	{
		if (!check_diag_s(d, tile_x, d->y_current >> CUBE_POW))
			d->x_current -= d->dx;
	}
}

void	move_a_if(t_d *d, int tile_x, int tile_y)
{
	if (d->level_map[tile_y * d->map_lenght + tile_x] == 0
		|| d->level_map[tile_y * d->map_lenght + tile_x] > 2)
	{
		if (!check_diag_a(d, tile_x, tile_y))
		{
			d->x_current = move_dep_on_angle_x(d, 1);
			d->y_current = move_dep_on_angle_y(d, 1);
		}
	}
	else if (d->level_map[tile_y * d->map_lenght
			+ (d->x_current >> CUBE_POW)] == 0
		|| d->level_map[tile_y * d->map_lenght
			+ (d->x_current >> CUBE_POW)] > 2)
	{
		if (!check_diag_a(d, d->x_current >> CUBE_POW, tile_y))
			d->y_current = move_dep_on_angle_y(d, 1);
	}
	else if (d->level_map[d->map_lenght
			+ tile_x * (d->y_current >> CUBE_POW)] == 0
		|| d->level_map[d->map_lenght
			+ tile_x * (d->y_current >> CUBE_POW)] > 2)
	{
		if (!check_diag_a(d, tile_x, d->y_current >> CUBE_POW))
			d->x_current = move_dep_on_angle_x(d, 1);
	}
}

void	move_d_if(t_d *d, int tile_x, int tile_y)
{
	if (d->level_map[tile_y * d->map_lenght + tile_x] == 0
		|| d->level_map[tile_y * d->map_lenght + tile_x] > 2)
	{
		if (!check_diag_d(d, tile_x, tile_y))
		{
			d->x_current = move_dep_on_angle_x(d, 2);
			d->y_current = move_dep_on_angle_y(d, 2);
		}
	}
	else if (d->level_map[tile_y * d->map_lenght
			+ (d->x_current >> CUBE_POW)] == 0
		|| d->level_map[tile_y * d->map_lenght
			+ (d->x_current >> CUBE_POW)] > 2)
	{
		if (!check_diag_d(d, d->x_current >> CUBE_POW, tile_y))
			d->y_current = move_dep_on_angle_y(d, 2);
	}
	else if (d->level_map[d->map_lenght
			+ tile_x * (d->y_current >> CUBE_POW)] == 0
		|| d->level_map[d->map_lenght
			+ tile_x * (d->y_current >> CUBE_POW)] > 2)
	{
		if (!check_diag_d(d, tile_x, d->y_current >> CUBE_POW))
			d->x_current = move_dep_on_angle_x(d, 2);
	}
}
