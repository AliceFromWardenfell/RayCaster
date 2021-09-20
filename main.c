#include "cub3d.h"

int	clean_close(t_d *d)
{
	if (d->win)
		mlx_destroy_window(d->mlx, d->win);
	if (d->img)
		mlx_destroy_image(d->mlx, d->img);
	if (d->dists)
		free(d->dists);
	if (d->items.tiles)
		free(d->items.tiles);
	global_free(d, 3);
	exit(0);
	return (0);
}

int	move_player(int keycode, t_d *d)
{
	ft_bzero(d->dists, d->win_lenght * sizeof(double));
	ft_bzero(d->items.tiles, d->map_lenght * d->map_height * sizeof(int));
	if (keycode == 65307)
		clean_close(d);
	if (keycode == W_KEY)
		move_w(d);
	if (keycode == S_KEY)
		move_s(d);
	if (keycode == A_KEY)
		move_a(d);
	if (keycode == D_KEY)
		move_d(d);
	if (keycode == LEFT_ARROW_KEY)
		rotate_left(d);
	if (keycode == RIGHT_ARROW_KEY)
		rotate_right(d);
	draw_background(d);
	main_dda(d);
	item_loop(d);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	return (0);
}

void	main_dda(t_d *d)
{
	int		horizontal_hit;
	int		vertical_hit;
	int		i;

	i = 0;
	d->curr_ray_angle = d->angle - ONE_DEG * 33;
	while (i < d->win_lenght)
	{
		remove_periods(d);
		h_prep_dda(d);
		horizontal_hit = 1;
		d->dda.jumps = 0;
		while (d->dda.jumps < JUMPS)
			h_dda(d, &horizontal_hit);
		v_prep_dda(d);
		vertical_hit = 1;
		d->dda.jumps = 0;
		while (d->dda.jumps < JUMPS)
			v_dda(d, &vertical_hit);
		shortest_ray(d, horizontal_hit, vertical_hit, i);
		print_3dview(d, i);
		d->curr_ray_angle += ONE_DEG / ((double)d->win_lenght / (double)66);
		i++;
	}
}

int	main_preparations(t_d *d, int argc, char **argv)
{
	initialization(d);
	d->mlx = mlx_init();
	if (check_args(d, argc, argv) == -1)
		return (print_error());
	if (parser(d, argv) == -1)
		return (print_error());
	pos_and_dir(d);
	d->dists = (double *)malloc(d->win_lenght * sizeof(double));
	if (!d->dists)
		return (clean_close(d));
	d->items.tiles = (int *)ft_calloc(d->map_lenght
			* d->map_height, sizeof(int));
	if (!d->items.tiles)
		return (clean_close(d));
	if (load_images(d) == -1)
		return (clean_close(d));
	return (0);
}

int	main(int argc, char **argv)
{
	t_d	d;

	if (main_preparations(&d, argc, argv) == -1)
		return (clean_close(&d));
	d.img = mlx_new_image(d.mlx, d.win_lenght, d.win_height);
	d.addr = mlx_get_data_addr(d.img, &d.bits_per_pixel,
			&d.line_length, &d.endian);
	draw_background(&d);
	main_dda(&d);
	item_loop(&d);
	if (d.save)
	{
		save(&d);
		return (clean_close(&d));
	}
	d.win = mlx_new_window(d.mlx, d.win_lenght, d.win_height, "Losedow");
	mlx_put_image_to_window(d.mlx, d.win, d.img, 0, 0);
	mlx_hook(d.win, 2, 1L << 0, move_player, &d);
	mlx_hook(d.win, 33, 1L << 0, clean_close, &d);
	mlx_loop(d.mlx);
	return (0);
}
