#include "cub3d.h"

int	parse_color_f_c(char *str)
{
	int			red;
	int			green;
	int			blue;
	long int	i;

	i = 2;
	if (!str)
		return (-1);
	red = atoi_color(str, i);
	i = first_app_index(str, ',') + 1;
	green = atoi_color(str, i);
	i = last_app_index(str, ',') + 1;
	blue = atoi_color(str, i);
	if (red == -1 || green == -1 || blue == -1)
		return (-1);
	if (counter(red) + counter(green) + counter(blue) != counter_s(str))
		return (-1);
	return (red * 65536 + green * 256 + blue);
}

void	res_assignment(t_d *d, int w, int h)
{
	if (d->win_lenght < MIN_WIN_LENGHT)
		d->win_lenght = MIN_WIN_LENGHT;
	if (d->win_height < MIN_WIN_HEIGHT)
		d->win_height = MIN_WIN_HEIGHT;
	if (d->win_lenght > w)
		d->win_lenght = w;
	if (d->win_height > h)
		d->win_height = h;
}

int	atoi_res(char *str, int i)
{
	int		rez;

	rez = 0;
	if (!str)
		return (-1);
	while (str[i] >= '0' && str[i] <= '9' && rez < 16777216)
	{
		rez = rez * 10 + (str[i] - 48);
		i++;
	}
	if (rez <= 0 || rez > 65536)
		return (-1);
	return (rez);
}

int	set_res(t_d *d, char *str, int i)
{
	if (!str)
		return (-1);
	while (str[i] == ' ')
		i++;
	if (!(str[i] >= '1' && str[i] <= '9'))
		return (-1);
	d->win_lenght = atoi_res(str, i);
	if (d->win_lenght == -1)
		return (-1);
	i += counter(d->win_lenght);
	while (str[i] == ' ')
		i++;
	if (!(str[i] >= '1' && str[i] <= '9'))
		return (-1);
	d->win_height = atoi_res(str, i);
	if (d->win_height == -1)
		return (-1);
	i += counter(d->win_height);
	while (str[i] == ' ')
		i++;
	if (str[i] != '\0')
		return (-1);
	return (0);
}

int	set_ident(t_d *d)
{
	int		floor;
	int		ceiling;
	int		w;
	int		h;

	w = 0;
	h = 0;
	if (set_res(d, d->splitted[d->ident.r_ind], 2) == -1)
		return (-1);
	mlx_get_screen_size(d->mlx, &w, &h);
	res_assignment(d, w, h);
	floor = parse_color_f_c(d->splitted[d->ident.f_ind]);
	if (floor < 0)
		return (-1);
	ceiling = parse_color_f_c(d->splitted[d->ident.c_ind]);
	if (ceiling < 0)
		return (-1);
	d->floor_color = floor;
	d->ceil_color = ceiling;
	return (0);
}
