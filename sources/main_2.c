#include "cub3d.h"

void	draw_background(t_d *d)
{
	int		i;
	int		j;

	j = 0;
	while (j < d->win_height)
	{
		i = 0;
		while (i < d->win_lenght)
		{
			if (j < d->win_height / 2)
				my_mlx_pixel_put(d, i, j, d->ceil_color);
			else
				my_mlx_pixel_put(d, i, j, d->floor_color);
			i++;
		}
		j++;
	}
}

void	set_pos_and_dir(t_d *d, int i, int side)
{
	int		x;
	int		y;

	x = i % d->map_lenght * d->cube_size;
	y = i / d->map_lenght * d->cube_size;
	d->x_current = x + d->cube_size / 2;
	d->y_current = y + d->cube_size / 2;
	if (side == 3)
		d->angle = PI_32;
	if (side == 4)
		d->angle = PI_12;
	if (side == 5)
		d->angle = PI_1;
	if (side == 6)
		d->angle = PI_2;
}

void	pos_and_dir(t_d *d)
{
	int		i;

	i = 0;
	while (i < d->map_height * d->map_lenght)
	{
		if (d->level_map[i] == 3)
			set_pos_and_dir(d, i, 3);
		if (d->level_map[i] == 4)
			set_pos_and_dir(d, i, 4);
		if (d->level_map[i] == 5)
			set_pos_and_dir(d, i, 5);
		if (d->level_map[i] == 6)
			set_pos_and_dir(d, i, 6);
		i++;
	}
	d->dx = (int)round(cos(d->angle) * MS);
	d->dy = (int)round(sin(d->angle) * MS);
}

int	load_images(t_d *d)
{
	if (load_no(d) == -1)
		return (print_error());
	if (load_so(d) == -1)
		return (print_error());
	if (load_we(d) == -1)
		return (print_error());
	if (load_ea(d) == -1)
		return (print_error());
	if (load_item(d) == -1)
		return (print_error());
	return (0);
}
