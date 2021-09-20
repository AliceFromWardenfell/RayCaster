#include "cub3d.h"

void	h_prep_dda(t_d *d)
{
	if ((d->curr_ray_angle > PI_2 + EPS || d->curr_ray_angle < PI_2 - EPS)
		&& (d->curr_ray_angle > PI_1 + EPS || d->curr_ray_angle < PI_1 - EPS))
		d->dda.ctg = -1 / tan(d->curr_ray_angle);
	else
		d->dda.ctg = 0;
	if (d->curr_ray_angle - PI_1 > EPS && PI_2 - d->curr_ray_angle > EPS)
	{
		d->ray_hy = d->y_current >> CUBE_POW << CUBE_POW;
		d->ray_hx = d->x_current + (d->y_current - d->ray_hy) * d->dda.ctg;
		d->dda.shift_y = -d->cube_size;
		d->dda.shift_x = -d->dda.shift_y * d->dda.ctg;
	}
	if (PI_1 - d->curr_ray_angle > EPS || d->curr_ray_angle - PI_2 > EPS)
	{
		d->ray_hy = (d->y_current >> CUBE_POW << CUBE_POW) + d->cube_size - 1;
		d->ray_hx = d->x_current + (d->y_current - d->ray_hy) * d->dda.ctg;
		d->dda.shift_y = d->cube_size;
		d->dda.shift_x = -d->dda.shift_y * d->dda.ctg;
	}
	if ((d->curr_ray_angle < PI_2 + EPS && d->curr_ray_angle > PI_2 - EPS)
		|| (d->curr_ray_angle < PI_1 + EPS && d->curr_ray_angle > PI_1 - EPS))
	{
		d->ray_hx = d->map_lenght * d->cube_size + d->map_height * d->cube_size;
		d->ray_hy = d->map_lenght * d->cube_size + d->map_height * d->cube_size;
	}
}

void	h_map_current(t_d *d)
{
	d->dda.map_y = (int)round(d->ray_hy) >> CUBE_POW;
	if (d->curr_ray_angle - PI_1 > EPS
		&& (d->curr_ray_angle > PI_2 + EPS || d->curr_ray_angle < PI_2 - EPS))
		d->dda.map_y--;
	if (PI_1 - d->curr_ray_angle > EPS)
		d->dda.map_y++;
	if (d->curr_ray_angle - PI_12 > EPS && PI_32 - d->curr_ray_angle > EPS)
		d->dda.map_x = (int)floor(d->ray_hx) >> CUBE_POW;
	else if (PI_12 - d->curr_ray_angle > EPS || d->curr_ray_angle - PI_32 > EPS)
		d->dda.map_x = (int)ceil(d->ray_hx) >> CUBE_POW;
	else
		d->dda.map_x = (int)round(d->ray_hx) >> CUBE_POW;
	d->dda.map_current = d->dda.map_y * d->map_lenght + d->dda.map_x;
}

void	h_jumps(t_d *d)
{
	if (d->level_map[d->dda.map_current] == 1)
		d->dda.jumps = JUMPS;
	else if (d->level_map[d->dda.map_current] == 2)
	{
		d->ray_hx += d->dda.shift_x;
		d->ray_hy += d->dda.shift_y;
		d->dda.jumps++;
	}
	else
	{
		d->ray_hx += d->dda.shift_x;
		d->ray_hy += d->dda.shift_y;
		d->dda.jumps++;
	}
}

void	h_dda(t_d *d, int *horizontal_hit)
{
	if ((d->ray_hy < d->cube_size
			|| d->ray_hy > (d->map_height - 1) * d->cube_size)
		|| (d->ray_hx < d->cube_size
			|| d->ray_hx > (d->map_lenght - 1) * d->cube_size))
	{
		d->dda.jumps = JUMPS;
		*horizontal_hit = 0;
	}
	else
	{
		h_map_current(d);
		if (d->dda.map_current > 0 && d->dda.map_current
			< d->map_lenght * d->map_height)
			h_jumps(d);
		else
			d->dda.jumps = JUMPS;
	}
}
