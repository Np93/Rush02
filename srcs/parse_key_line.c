/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_key_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 22:20:32 by nhirzel           #+#    #+#             */
/*   Updated: 2021/07/25 23:19:54 by trossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "dict.h"
#include "ft.h"

char	*ft_strdup(char *srci, int size)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc((1 + size) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (i < size)
	{
		dest[i] = srci[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*trim(char *str)
{
	char	*dest;
	int		i;
	int		i_dest;

	i = 1;
	i_dest = 1;
	dest = malloc(ft_strlen(str) + 1);
	if (dest == NULL)
		return (NULL);
	dest[0] = str[0];
	while (i < ft_strlen(str))
	{
		if (str[i] != ' ' || dest[i_dest - 1] != ' ')
		{
			dest[i_dest] = str[i];
			i_dest++;
		}
		i++;
	}
	if (dest[i_dest - 1] == ' ')
		i_dest--;
	dest[i_dest] = '\0';
	free(str);
	return (dest);
}

char	*ft_lecture_auto_num(char *lign, int length)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	while (i < length && (lign[i] == ' ' || (lign[i] >= 9 && lign[i] <= 13)))
		i++;
	while (i < length && lign[i] == '+')
		i++;
	start = i;
	while (i < length && lign[i] >= '0' && lign[i] <= '9')
		i++;
	end = i;
	while (i < length && lign[i] != ':')
	{
		if (lign[i] != ' ')
			return (NULL);
		i++;
	}
	return (ft_strdup(&lign[start], end - start));
}

char	*ft_lecture_auto_num_let(char *lign, int length)
{
	int		ii;
	int		c;

	ii = 0;
	c = 0;
	while (lign[ii] != ':' && ii < length)
		ii++;
	ii++;
	while (lign[ii] == ' ' && ii < length)
		ii++;
	c = ii;
	while (c < length)
	{
		c++;
	}
	return (trim(ft_strdup(&lign[ii], c - ii)));
}

t_key	*parse_key_from_line(char *line, int length)
{
	t_key	*k;
	int		i;
	int		n_colon;

	i = 0;
	n_colon = 0;
	while (i < length)
	{
		if (line[i++] == ':')
			n_colon++;
	}
	if (n_colon != 1)
		return (NULL);
	k = malloc(sizeof(t_key));
	if (!k)
		return (k);
	k->num = ft_lecture_auto_num(line, length);
	k->value = ft_lecture_auto_num_let(line, length);
	k->n_digit = ft_strlen(k->num);
	k->freeable = 2;
	k->original = 0;
	return (k);
}
