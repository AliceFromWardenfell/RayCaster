#include "cub3d.h"

void	shortest_ray_prep(t_d *d, double *delta_angle,
		double *len_hray, double *len_vray)
{
	*delta_angle = d->angle - d->curr_ray_angle;
	if (*delta_angle < EPS)
		*delta_angle += PI_2;
	if (*delta_angle - PI_2 > EPS)
		*delta_angle -= PI_2;
	*len_hray = d->map_lenght * d->cube_size + d->map_height * d->cube_size;
	*len_vray = d->map_lenght * d->cube_size + d->map_height * d->cube_size;
}

void	choose_shortest_ray(t_d *d, double len_hray, double len_vray, int i)
{
	if (len_hray <= len_vray)
	{
		d->curr_ray_len = len_hray;
		if (!d->curr_ray_len)
			d->curr_ray_len = 1;
		d->dists[i] = d->curr_ray_len;
		d->curr_ray_x = d->ray_hx;
		d->curr_ray_y = d->ray_hy;
		d->h_ray_shorter = 1;
	}
	else
	{
		d->curr_ray_len = len_vray;
		if (!d->curr_ray_len)
			d->curr_ray_len = 1;
		d->dists[i] = d->curr_ray_len;
		d->curr_ray_x = d->ray_vx;
		d->curr_ray_y = d->ray_vy;
		d->h_ray_shorter = 0;
	}
}

void	shortest_ray(t_d *d, int horizontal_hit, int vertical_hit, int i)
{
	double		len_hray;
	double		len_vray;
	double		delta_angle;

	shortest_ray_prep(d, &delta_angle, &len_hray, &len_vray);
	if (horizontal_hit)
		len_hray = fabs((d->ray_hy - d->y_current) / sin(d->curr_ray_angle));
	if (vertical_hit)
		len_vray = fabs((d->ray_vx - d->x_current) / cos(d->curr_ray_angle));
	choose_shortest_ray(d, len_hray, len_vray, i);
	d->curr_ray_len *= cos(delta_angle);
}
