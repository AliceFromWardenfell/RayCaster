#include "cub3d.h"

void	*ft_calloc(size_t amount, size_t size)
{
	size_t	i;
	size_t	len;
	void	*dst;

	i = 0;
	dst = NULL;
	len = (amount * size);
	dst = (void *)malloc(len);
	if (!dst)
		return (NULL);
	while (i < len)
		((char *)dst)[i++] = 0;
	return (dst);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*dst;
	size_t	i;
	size_t	j;
	size_t	len_1;
	size_t	len_2;

	if (!str1 || !str2)
		return (NULL);
	dst = NULL;
	len_1 = ft_strlen(str1);
	len_2 = ft_strlen(str2);
	dst = (char *)malloc((len_1 + len_2 + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len_1)
		dst[j++] = str1[i++];
	i = 0;
	while (i < len_2)
		dst[j++] = str2[i++];
	dst[j] = '\0';
	return (dst);
}

int	sum_ints(int i)
{
	int		j;
	int		rez;

	if (i < 0)
		return (-1);
	rez = 0;
	j = 0;
	while (j <= i)
	{
		rez += j;
		j++;
	}
	return (rez);
}

int	if_line_valid(const char *str, const char *sample, int k, int i)
{
	int		j;
	int		str_len;
	int		sample_len;

	str_len = ft_strlen_int(str);
	if (!str || str_len == -1)
		return (-1);
	sample_len = ft_strlen_int(sample);
	if (!sample || sample_len == -1)
		return (-1);
	while (++i < str_len)
	{
		j = -1;
		while (++j < sample_len)
		{
			if (str[i] == sample[j])
			{
				k++;
				break ;
			}
		}
	}
	if (k == str_len)
		return (1);
	return (0);
}

int	if_sym_valid(const char *str, char c)
{
	int		i;
	int		amount;

	if (!str)
		return (-1);
	amount = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			amount++;
		i++;
	}
	return (amount);
}
