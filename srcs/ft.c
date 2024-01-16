#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_putstr(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
	{
		write(1, &str[length], 1);
		length++;
	}
}

int	ft_strlen(char *str)
{
	char	*p;

	p = str;
	while (*p != '\0')
		p++;
	return (p - str);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	idx;
	int				val;

	idx = 0;
	while (s1[idx] != '\0' || s2[idx] != '\0')
	{
		val = s1[idx] - s2[idx];
		if (val != 0)
			return (val);
		idx++;
	}
	return (0);
}
