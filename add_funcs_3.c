#include "cub3d.h"

int	free_level_map(t_d *d)
{
	if (d->level_map == NULL)
		return (0);
	free(d->level_map);
	d->level_map = NULL;
	return (0);
}

int	global_free(t_d *d, int code)
{
	int		i;

	if (code < 0 || code > 3)
		return (-1);
	if ((code == 0 || code == 1 || code == 3) && d->argv_content != NULL)
	{
		free((void *)d->argv_content);
		d->argv_content = NULL;
		if (code == 0)
			return (0);
	}
	if (code == 2 || code == 3)
	{
		if (!d->splitted || !*d->splitted)
			return (-1);
		i = -1;
		while (d->splitted[++i] != NULL)
		{
			free((void *)d->splitted[i]);
			d->splitted[i] = NULL;
		}
		free(d->splitted);
		d->splitted = NULL;
	}
	return (-1);
}

int	null_from_mlxlib(char **path, void **str)
{
	if (*path != NULL)
	{
		free(*path);
		*path = NULL;
	}
	if (*str != NULL)
	{
		free(*str);
		*str = NULL;
	}
	printf("error: null has been returned from mlxlib\n");
	return (-1);
}

int	long_if_func_for_sort_items(t_d *d, int j)
{
	return (((d->x_current - (d->items.tiles[j]
					% d->map_lenght * d->cube_size))
			* (d->x_current - (d->items.tiles[j]
					% d->map_lenght * d->cube_size))
			+ (d->y_current - (d->items.tiles[j]
					/ d->map_lenght * d->cube_size))
			* (d->y_current - (d->items.tiles[j]
					/ d->map_lenght * d->cube_size)))
		< ((d->x_current - (d->items.tiles[j + 1]
					% d->map_lenght * d->cube_size))
			* (d->x_current - (d->items.tiles[j + 1]
					% d->map_lenght * d->cube_size))
			+ (d->y_current - (d->items.tiles[j + 1]
					/ d->map_lenght * d->cube_size))
			* (d->y_current - (d->items.tiles[j + 1]
					/ d->map_lenght * d->cube_size))));
}

int	print_error(void)
{
	printf("Error!\n");
	return (-1);
}
