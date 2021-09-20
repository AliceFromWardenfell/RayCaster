#include "cub3d.h"

void	v_prep_dda(t_d *d)
{
	d->dda.ctg = -tan(d->curr_ray_angle);
	if (d->curr_ray_angle - PI_12 > EPS && PI_32 - d->curr_ray_angle > EPS)
	{
		d->ray_vx = d->x_current >> CUBE_POW << CUBE_POW;
		d->ray_vy = d->y_current + (d->x_current - d->ray_vx) * d->dda.ctg;
		d->dda.shift_x = -d->cube_size;
		d->dda.shift_y = -d->dda.shift_x * d->dda.ctg;
	}
	if (PI_12 - d->curr_ray_angle > EPS || d->curr_ray_angle - PI_32 > EPS)
	{
		d->ray_vx = (d->x_current >> CUBE_POW << CUBE_POW) + d->cube_size - 1;
		d->ray_vy = d->y_current + (d->x_current - d->ray_vx) * d->dda.ctg;
		d->dda.shift_x = d->cube_size;
		d->dda.shift_y = -d->dda.shift_x * d->dda.ctg;
	}
	if ((d->curr_ray_angle < PI_32 + EPS && d->curr_ray_angle > PI_32 - EPS)
		|| (d->curr_ray_angle < PI_12 + EPS && d->curr_ray_angle > PI_12 - EPS))
	{
		d->ray_vx = d->map_lenght * d->cube_size + d->map_height * d->cube_size;
		d->ray_vy = d->map_lenght * d->cube_size + d->map_height * d->cube_size;
	}
}

void	v_map_current(t_d *d)
{
	d->dda.map_x = (int)round(d->ray_vx) >> CUBE_POW;
	if (d->curr_ray_angle - PI_12 > EPS && PI_32 - d->curr_ray_angle > EPS)
		d->dda.map_x--;
	if (PI_12 - d->curr_ray_angle > EPS || d->curr_ray_angle - PI_32 > EPS)
		d->dda.map_x++;
	if (d->curr_ray_angle - PI_1 > EPS && PI_2 - d->curr_ray_angle > EPS)
		d->dda.map_y = (int)floor(d->ray_vy) >> CUBE_POW;
	else if (PI_1 - d->curr_ray_angle > EPS || d->curr_ray_angle - PI_2 > EPS)
		d->dda.map_y = (int)ceil(d->ray_vy) >> CUBE_POW;
	else
		d->dda.map_y = (int)round(d->ray_vy) >> CUBE_POW;
	d->dda.map_current = d->dda.map_y * d->map_lenght + d->dda.map_x;
}

void	v_jumps(t_d *d)
{
	if (d->level_map[d->dda.map_current] == 1)
		d->dda.jumps = JUMPS;
	else if (d->level_map[d->dda.map_current] == 2)
	{
		d->ray_vx += d->dda.shift_x;
		d->ray_vy += d->dda.shift_y;
		d->dda.jumps++;
	}
	else
	{
		d->ray_vx += d->dda.shift_x;
		d->ray_vy += d->dda.shift_y;
		d->dda.jumps++;
	}
}

void	v_dda(t_d *d, int *vertical_hit)
{
	if ((d->ray_vy < d->cube_size
			|| d->ray_vy > (d->map_height - 1) * d->cube_size)
		|| (d->ray_vx < d->cube_size
			|| d->ray_vx > (d->map_lenght - 1) * d->cube_size))
	{
		*vertical_hit = 0;
		d->dda.jumps = JUMPS;
	}
	else
	{
		v_map_current(d);
		if (d->dda.map_current > 0 && d->dda.map_current
			< d->map_lenght * d->map_height)
			v_jumps(d);
		else
			d->dda.jumps = JUMPS;
	}
}
