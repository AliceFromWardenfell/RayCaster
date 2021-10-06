#include "cub3d.h"

char	*clear_buf(char *buf)
{
	int		i;

	i = 0;
	while (i < (BUF_SIZE + 1))
	{
		buf[i] = '\0';
		i++;
	}
	return (buf);
}

char	*free_string_ret(char **str1)
{
	if (*str1 != NULL)
	{
		free((void *)*str1);
		*str1 = NULL;
	}
	return (NULL);
}

char	*free_strings_ret(char **str1, char **str2)
{
	if (*str1 != NULL)
	{
		free((void *)*str1);
		*str1 = NULL;
	}
	if (*str2 != NULL)
	{
		free((void *)*str2);
		*str2 = NULL;
	}
	return (NULL);
}

void	free_string(char **s)
{
	if (*s != NULL)
	{
		free((void *)*s);
		*s = NULL;
	}
}

char	*read_argv(int fd, int buf_size, char *tmp, char *buf)
{
	char	*rez;

	rez = NULL;
	rez = (char *)ft_calloc(1, sizeof(char));
	if (!rez)
		return (NULL);
	buf = (char *)ft_calloc((BUF_SIZE + 1), sizeof(char));
	if (!buf)
		return (free_string_ret(&rez));
	while (buf_size == BUF_SIZE)
	{
		buf_size = read(fd, buf, BUF_SIZE);
		if (buf_size < 0)
			return (free_strings_ret(&rez, &buf));
		buf[buf_size] = '\0';
		tmp = rez;
		rez = ft_strjoin(rez, buf);
		if (!rez)
			return (free_strings_ret(&rez, &buf));
		buf = clear_buf(buf);
	}
	free_string(&tmp);
	free_string(&buf);
	return (rez);
}
