#include "cub3d.h"

void	write_items(t_d *d)
{
	int		x;
	int		y;
	int		k;

	y = 0;
	k = 0;
	while (y < d->map_height)
	{
		x = 0;
		while (x < d->map_lenght)
		{
			if (d->level_map[d->map_lenght * y + x] == 2)
			{
				d->items.tiles[k] = d->map_lenght * y + x;
				k++;
			}
			x++;
		}
		y++;
	}
}

void	sort_items(t_d *d)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	while (i < d->map_lenght * d->map_height - 1 && d->items.tiles[i])
	{
		j = 0;
		while (j < d->map_lenght * d->map_height - i - 1
			&& d->items.tiles[j + 1])
		{
			if (long_if_func_for_sort_items(d, j))
			{
				tmp = d->items.tiles[j];
				d->items.tiles[j] = d->items.tiles[j + 1];
				d->items.tiles[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	prep_to_draw_item(t_d *d, int map_tile)
{
	double	angle_to_item;
	double	item_x;
	double	item_y;
	int		color;

	color = 0;
	item_x = (map_tile % d->map_lenght) * d->cube_size + d->cube_size / 2;
	item_y = (map_tile / d->map_lenght) * d->cube_size + d->cube_size / 2;
	angle_to_item = atan2(item_y - d->y_current, item_x - d->x_current);
	while (angle_to_item - d->angle > PI_1)
		angle_to_item -= 2 * PI_1;
	while (angle_to_item - d->angle < -PI_1)
		angle_to_item += 2 * PI_1;
	d->items.dist = sqrt((d->x_current - item_x) * (d->x_current - item_x)
			+ (d->y_current - item_y) * (d->y_current - item_y));
	d->items.item_1_size = (int)(1.5
			* d->win_height * d->cube_size / d->items.dist);
	d->items.lcorner_1x = d->win_lenght / 2 + (angle_to_item - d->angle)
		* d->win_lenght / (ONE_DEG * 66) - d->items.item_1_size / 2;
	d->items.lcorner_1y = d->win_height / 2 - d->items.item_1_size / 2;
	draw_item(d, color, 0, 0);
}

void	draw_item(t_d *d, int color, int i, int j)
{
	while (i < d->items.item_1_size)
	{
		j = 0;
		if (d->items.lcorner_1x + i < 0
			|| d->items.lcorner_1x + i >= d->win_lenght)
			i++;
		else if (d->dists[d->items.lcorner_1x + i] < d->items.dist)
			i++;
		else
		{
			while (j < d->items.item_1_size)
			{
				if (!(d->items.lcorner_1y + j < 0
						|| d->items.lcorner_1y + j >= d->win_height))
					i_hate_norminette(d, &color, i, j);
				j++;
			}
			i++;
		}
	}
}

void	item_loop(t_d *d)
{
	int		i;

	i = 0;
	write_items(d);
	sort_items(d);
	while (d->items.tiles[i])
	{
		prep_to_draw_item(d, d->items.tiles[i]);
		i++;
	}
}
