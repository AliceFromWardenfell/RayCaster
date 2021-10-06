#include "cub3d.h"

size_t	first_trim(char const *s1, char const *set, size_t l_s1, size_t l_set)
{
	size_t		i;
	size_t		j;
	short int	found;

	i = 0;
	while (i < l_s1)
	{
		j = 0;
		found = 0;
		while (j < l_set)
		{
			if (s1[i] == set[j])
			{
				found = 1;
				break ;
			}
			else
				j++;
		}
		if (found == 1)
			i++;
		else
			break ;
	}
	return (i);
}

void	init_i(size_t *i, size_t l_s1)
{
	*i = 0;
	if (l_s1 > 0)
		*i = l_s1 - 1;
}

size_t	last_trim(char const *s1, char const *set, size_t l_s1, size_t l_set)
{
	size_t	i;
	size_t	j;
	int		found;

	init_i(&i, l_s1);
	while (i > 0)
	{
		j = 0;
		found = 0;
		while (j < l_set)
		{
			if (s1[i] == set[j])
			{
				found = 1;
				break ;
			}
			else
				j++;
		}
		if (found == 1)
			i--;
		else
			break ;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	first;
	size_t	last;
	size_t	len_s1;
	size_t	len_set;

	if (!s1 || !set)
		return (NULL);
	dest = NULL;
	len_s1 = ft_strlen(s1);
	len_set = ft_strlen(set);
	first = first_trim(s1, set, len_s1, len_set);
	last = last_trim(s1, set, len_s1, len_set);
	if (last < first)
		len_s1 = 0;
	else
		len_s1 = (last - first + 1);
	dest = (char *)malloc((len_s1 + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	last = 0;
	while (last < len_s1)
		dest[last++] = s1[first++];
	dest[last] = '\0';
	return ((char *)dest);
}
