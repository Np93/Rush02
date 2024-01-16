#include <stdlib.h>

#include "ft.h"

int	get_total_length(int size, char **strs, int sep_size)
{
	int	l;
	int	i_s;

	i_s = 0;
	l = 0;
	while (i_s < size)
	{
		l += ft_strlen(strs[i_s]);
		l += sep_size;
		i_s++;
	}
	l = l - sep_size + 1;
	return (l);
}

char	*ft_strcpy_without_terminating_char(char *dest, char *src)
{
	unsigned int	idx;

	idx = 0;
	while (src[idx] != '\0')
	{
		dest[idx] = src[idx];
		idx++;
	}
	return (dest + idx);
}

char	*ft_strjoin(char *s1, char *s2, char *sep)
{
	char	*s;
	int		l;
	int		i_s;
	char	*strs[2];

	strs[0] = s1;
	strs[1] = s2;
	l = get_total_length(2, strs, ft_strlen(sep));
	s = malloc(l * sizeof(char));
	i_s = 0;
	while (i_s < 2)
	{
		s = ft_strcpy_without_terminating_char(s, strs[i_s]);
		if (i_s == 1)
		{
			*(s++) = '\0';
			break ;
		}
		s = ft_strcpy_without_terminating_char(s, sep);
		i_s++;
	}
	return (s - l);
}
