#include "cub3d.h"

int	load_no(t_d *d)
{
	char	*path;

	path = ft_strtrim(&((char *)d->splitted[d->ident.no_ind])[2], " \n\t\b\v\f\r");
	if (!path)
		return (-1);
	d->tex.tex_n = mlx_xpm_file_to_image(d->mlx, path, &d->tex.width_n,
			&d->tex.height_n);
	if (!d->tex.tex_n)
		return (null_from_mlxlib(&path, &d->tex.tex_n));
	d->tex.addr_n = mlx_get_data_addr(d->tex.tex_n, &d->tex.bits_per_pixel_n,
			&d->tex.line_length_n, &d->tex.endian);
	if (!d->tex.addr_n)
		return (null_from_mlxlib(&path, &d->tex.tex_n));
	free_string(&path);
	return (0);
}

int	load_so(t_d *d)
{
	char	*path;

	path = ft_strtrim(&((char *)d->splitted[d->ident.so_ind])[2], " \n\t\b\v\f\r");
	if (!path)
		return (-1);
	d->tex.tex_s = mlx_xpm_file_to_image(d->mlx, path, &d->tex.width_s,
			&d->tex.height_s);
	if (!d->tex.tex_s)
		return (null_from_mlxlib(&path, &d->tex.tex_s));
	d->tex.addr_s = mlx_get_data_addr(d->tex.tex_s, &d->tex.bits_per_pixel_s,
			&d->tex.line_length_s, &d->tex.endian);
	if (!d->tex.addr_s)
		return (null_from_mlxlib(&path, &d->tex.tex_s));
	free_string(&path);
	return (0);
}

int	load_we(t_d *d)
{
	char	*path;

	path = ft_strtrim(&((char *)d->splitted[d->ident.we_ind])[2], " \n\t\b\v\f\r");
	if (!path)
		return (-1);
	d->tex.tex_w = mlx_xpm_file_to_image(d->mlx, path, &d->tex.width_w,
			&d->tex.height_w);
	if (!d->tex.tex_w)
		return (null_from_mlxlib(&path, &d->tex.tex_w));
	d->tex.addr_w = mlx_get_data_addr(d->tex.tex_w, &d->tex.bits_per_pixel_w,
			&d->tex.line_length_w, &d->tex.endian);
	if (!d->tex.addr_w)
		return (null_from_mlxlib(&path, &d->tex.tex_w));
	free_string(&path);
	return (0);
}

int	load_ea(t_d *d)
{
	char	*path;

	path = ft_strtrim(&((char *)d->splitted[d->ident.ea_ind])[2], " \n\t\b\v\f\r");
	if (!path)
		return (-1);
	d->tex.tex_e = mlx_xpm_file_to_image(d->mlx, path, &d->tex.width_e,
			&d->tex.height_e);
	if (!d->tex.tex_e)
		return (null_from_mlxlib(&path, &d->tex.tex_e));
	d->tex.addr_e = mlx_get_data_addr(d->tex.tex_e, &d->tex.bits_per_pixel_e,
			&d->tex.line_length_e, &d->tex.endian);
	if (!d->tex.addr_e)
		return (null_from_mlxlib(&path, &d->tex.tex_e));
	free_string(&path);
	return (0);
}

int	load_item(t_d *d)
{
	char	*path;

	path = ft_strtrim(&((char *)d->splitted[d->ident.s_ind])[2], " \n\t\b\v\f\r");
	if (!path)
		return (-1);
	d->items.item_1 = mlx_xpm_file_to_image(d->mlx, path, &d->items.width_1,
			&d->items.height_1);
	if (!d->items.item_1)
		return (null_from_mlxlib(&path, &d->items.item_1));
	d->items.addr_1 = mlx_get_data_addr(d->items.item_1,
			&d->items.bits_per_pixel_1,
			&d->items.line_length_1, &d->items.endian);
	if (!d->items.addr_1)
		return (null_from_mlxlib(&path, &d->items.item_1));
	free_string(&path);
	return (0);
}
