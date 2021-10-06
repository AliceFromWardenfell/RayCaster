#include "cub3d.h"

void	remove_periods(t_d *d)
{
	if (d->curr_ray_angle < EPS)
		d->curr_ray_angle += PI_2;
	if (d->curr_ray_angle - PI_2 > EPS)
		d->curr_ray_angle -= PI_2;
}

int	move_dep_on_angle_x(t_d *d, int dir)
{
	int		x;

	x = 0;
	if (dir == 1)
	{
		if (d->angle - PI_12 < EPS || (d->angle - PI_1 > EPS
				&& d->angle - PI_32 < EPS))
			x = d->x_current + d->dy;
		else
			x = d->x_current + d->dy;
	}
	if (dir == 2)
	{
		if (d->angle - PI_12 < EPS || (d->angle - PI_1 > EPS
				&& d->angle - PI_32 < EPS))
			x = d->x_current - d->dy;
		else
			x = d->x_current - d->dy;
	}
	return (x);
}

int	move_dep_on_angle_y(t_d *d, int dir)
{
	int		y;

	y = 0;
	if (dir == 1)
	{
		if (d->angle - PI_12 < EPS || (d->angle - PI_1 > EPS
				&& d->angle - PI_32 < EPS))
			y = d->y_current - d->dx;
		else
			y = d->y_current - d->dx;
	}
	if (dir == 2)
	{
		if (d->angle - PI_12 < EPS || (d->angle - PI_1 > EPS
				&& d->angle - PI_32 < EPS))
			y = d->y_current + d->dx;
		else
			y = d->y_current + d->dx;
	}
	return (y);
}

void	rotate_left(t_d *d)
{
	d->angle -= ONE_DEG * DEG_PER_TURN;
	if (d->angle < EPS)
		d->angle += PI_2;
	d->dx = (int)round(cos(d->angle) * MS);
	d->dy = (int)round(sin(d->angle) * MS);
}

void	rotate_right(t_d *d)
{
	d->angle += ONE_DEG * DEG_PER_TURN;
	if (d->angle - PI_2 > EPS)
		d->angle -= PI_2;
	d->dx = (int)round(cos(d->angle) * MS);
	d->dy = (int)round(sin(d->angle) * MS);
}
