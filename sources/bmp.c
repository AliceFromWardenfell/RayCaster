#include "cub3d.h"
int	write_header_1(t_d *d, int fd)
{
	unsigned char	header_1[14];
	size_t			size;

	ft_bzero(header_1, 14);
	size = 54 + (d->bits_per_pixel / 8
			* d->win_lenght * d->win_height);
	header_1[0] = 'B';
	header_1[1] = 'M';
	header_1[2] = (unsigned char)(size % 256);
	header_1[3] = (unsigned char)(size / 256 % 256);
	header_1[4] = (unsigned char)(size / 256 / 256 % 256);
	header_1[5] = (unsigned char)(size / 256 / 256 / 256);
	header_1[10] = 54;
	if (write(fd, header_1, 14) < 0)
		return (-1);
	return (0);
}

int	write_header_2(t_d *d, int fd)
{
	unsigned char	header_2[40];

	ft_bzero(header_2, 40);
	header_2[0] = 40;
	header_2[4] = (unsigned char)(d->win_lenght % 256);
	header_2[5] = (unsigned char)(d->win_lenght / 256 % 256);
	header_2[6] = (unsigned char)(d->win_lenght / 256 / 256 % 256);
	header_2[7] = (unsigned char)(d->win_lenght / 256 / 256 / 256);
	header_2[8] = (unsigned char)(d->win_height % 256);
	header_2[9] = (unsigned char)(d->win_height / 256 % 256);
	header_2[10] = (unsigned char)(d->win_height / 256 / 256 % 256);
	header_2[11] = (unsigned char)(d->win_height / 256 / 256 / 256);
	header_2[12] = 1;
	header_2[14] = 32;
	if (write(fd, header_2, 40) < 0)
		return (-1);
	return (0);
}

int	write_image(t_d *d, int fd)
{
	int		win_h;
	int		size;

	win_h = d->win_height;
	size = d->win_lenght * d->bits_per_pixel / 8;
	while (win_h >= 0)
	{
		if (write(fd, (unsigned char *)(d->addr + win_h
				* d->line_length), size) < 0)
			return (-1);
		win_h--;
	}
	return (0);
}

int	save(t_d *d)
{
	int	fd;

	fd = open("first_rendered_image.bmp", O_WRONLY | O_TRUNC | O_CREAT, 0655);
	if (fd < 0)
		return (print_error());
	if (write_header_1(d, fd) == -1)
		return (print_error());
	if (write_header_2(d, fd) == -1)
		return (print_error());
	if (write_image(d, fd) == -1)
		return (print_error());
	return (0);
}
