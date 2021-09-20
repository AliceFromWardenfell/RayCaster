#include "cub3d.h"

void	i_hate_norminette(t_d *d, int *color, int i, int j)
{
	*color = get_item_pixel_color(d, (int)(i * d->items.width_1
				/ (double)d->items.item_1_size),
			(int)(j * d->items.height_1
				/ (double)d->items.item_1_size));
	if ((*color & 0x00FFFFFF) != 0 || *color == 0x00000000)
		my_mlx_pixel_put(d, d->items.lcorner_1x + i,
			d->items.lcorner_1y + j, *color);
}

void	my_mlx_pixel_put(t_d *d, int x, int y, int color)
{
	char	*dst;

	dst = d->addr + (y * d->line_length + x * (d->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_tex_pixel_color(t_d *d, int x, int y)
{
	char	*dst;

	if (d->h_ray_shorter)
	{
		if (d->curr_ray_angle - PI_1 < EPS)
			dst = d->tex.addr_n + (y * d->tex.line_length_n
					+ x * (d->tex.bits_per_pixel_n / 8));
		else
			dst = d->tex.addr_s + (y * d->tex.line_length_s
					+ x * (d->tex.bits_per_pixel_s / 8));
	}
	else
	{
		if (d->curr_ray_angle - PI_12 > EPS && PI_32 - d->curr_ray_angle > EPS)
			dst = d->tex.addr_e + (y * d->tex.line_length_e
					+ x * (d->tex.bits_per_pixel_e / 8));
		else
			dst = d->tex.addr_w + (y * d->tex.line_length_w
					+ x * (d->tex.bits_per_pixel_w / 8));
	}
	return (*(unsigned int *)dst);
}

int	get_item_pixel_color(t_d *d, int x, int y)
{
	char	*dst;

	dst = d->items.addr_1 + (y * d->items.line_length_1
			+ x * (d->items.bits_per_pixel_1 / 8));
	return (*(unsigned int *)dst);
}
