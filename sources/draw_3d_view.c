#include "cub3d.h"

double	tex_orientation(t_d *d)
{
	double	y_step;

	y_step = 0;
	if (d->h_ray_shorter)
	{
		if (d->curr_ray_angle - PI_1 < EPS)
			y_step = d->tex.height_n
				/ (1.5 * (d->cube_size * d->win_height / d->curr_ray_len));
		else
			y_step = d->tex.height_s
				/ (1.5 * (d->cube_size * d->win_height / d->curr_ray_len));
	}
	else
	{
		if (d->curr_ray_angle - PI_12 > EPS && PI_32 - d->curr_ray_angle > EPS)
			y_step = d->tex.height_e
				/ (1.5 * (d->cube_size * d->win_height / d->curr_ray_len));
		else
			y_step = d->tex.height_w
				/ (1.5 * (d->cube_size * d->win_height / d->curr_ray_len));
	}
	return (y_step);
}

void	calc_delta(t_d *d, int *delta)
{
	if (d->h_ray_shorter)
	{
		*delta = (int)round(d->curr_ray_x)
			- ((int)round(d->curr_ray_x) >> CUBE_POW << CUBE_POW);
		if (d->curr_ray_angle - PI_1 < EPS)
			*delta = d->cube_size - 1 - *delta;
	}
	else
	{
		*delta = (int)round(d->curr_ray_y)
			- ((int)round(d->curr_ray_y) >> CUBE_POW << CUBE_POW);
		if (d->curr_ray_angle - PI_12 > EPS && PI_32 - d->curr_ray_angle > EPS)
			*delta = d->cube_size - 1 - *delta;
	}
}

void	draw_column(t_d *d, int dx, int dy, double col_up_y_cpy)
{
	int		i;
	double	y_curr;
	double	y_step;
	int		delta;
	int		color;

	i = 0;
	y_curr = 0;
	y_step = tex_orientation(d);
	if (col_up_y_cpy < EPS)
		y_curr = y_step * -col_up_y_cpy;
	calc_delta(d, &delta);
	while (d->column_up_y + i <= dy)
	{
		color = get_tex_pixel_color(d, delta, (int)y_curr);
		my_mlx_pixel_put(d, dx, d->column_up_y + i, color);
		i++;
		y_curr += y_step;
	}
}

void	print_3dview(t_d *d, int i)
{
	double	column_len;
	double	col_down_y;
	int		column_width;
	double	col_up_y_cpy;

	column_width = 1;
	column_len = 1.5 * (d->cube_size * d->win_height / d->curr_ray_len);
	d->column_up_y = (int)round(d->win_height / 2 - column_len / 2);
	col_up_y_cpy = d->column_up_y;
	if (d->column_up_y < 0)
		d->column_up_y = 0;
	col_down_y = (int)round(d->win_height / 2 + column_len / 2);
	if (col_down_y >= d->win_height)
		col_down_y = d->win_height - 1;
	d->col_up_x = i * column_width;
	while (column_width > 0)
	{
		if (d->h_ray_shorter)
			draw_column(d, d->col_up_x, (int)round(col_down_y), col_up_y_cpy);
		else
			draw_column(d, d->col_up_x, (int)round(col_down_y), col_up_y_cpy);
		d->col_up_x++;
		column_width--;
	}
}
