#include "cub3d.h"

void	move_w(t_d *d)
{
	int		x;
	int		y;
	int		tile_x;
	int		tile_y;

	x = d->x_current + d->dx;
	y = d->y_current + d->dy;
	tile_x = x >> CUBE_POW;
	tile_y = y >> CUBE_POW;
	if (d->x_current >> CUBE_POW != tile_x
		|| d->y_current >> CUBE_POW != tile_y)
		move_w_if(d, tile_x, tile_y);
	else
	{
		d->x_current += d->dx;
		d->y_current += d->dy;
	}
}

void	move_s(t_d *d)
{
	int		x;
	int		y;
	int		tile_x;
	int		tile_y;

	x = d->x_current - d->dx;
	y = d->y_current - d->dy;
	tile_x = x >> CUBE_POW;
	tile_y = y >> CUBE_POW;
	if (d->x_current >> CUBE_POW != tile_x
		|| d->y_current >> CUBE_POW != tile_y)
		move_s_if(d, tile_x, tile_y);
	else
	{
		d->x_current -= d->dx;
		d->y_current -= d->dy;
	}
}

void	move_a(t_d *d)
{
	int		x;
	int		y;
	int		tile_x;
	int		tile_y;

	x = move_dep_on_angle_x(d, 1);
	y = move_dep_on_angle_y(d, 1);
	tile_x = x >> CUBE_POW;
	tile_y = y >> CUBE_POW;
	if (d->x_current >> CUBE_POW != tile_x
		|| d->y_current >> CUBE_POW != tile_y)
		move_a_if(d, tile_x, tile_y);
	else
	{
		d->x_current = move_dep_on_angle_x(d, 1);
		d->y_current = move_dep_on_angle_y(d, 1);
	}
}

void	move_d(t_d *d)
{
	int		x;
	int		y;
	int		tile_x;
	int		tile_y;

	x = move_dep_on_angle_x(d, 2);
	y = move_dep_on_angle_y(d, 2);
	tile_x = x >> CUBE_POW;
	tile_y = y >> CUBE_POW;
	if (d->x_current >> CUBE_POW != tile_x
		|| d->y_current >> CUBE_POW != tile_y)
		move_d_if(d, tile_x, tile_y);
	else
	{
		d->x_current = move_dep_on_angle_x(d, 2);
		d->y_current = move_dep_on_angle_y(d, 2);
	}
}
