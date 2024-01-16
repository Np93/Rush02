/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 22:20:56 by nhirzel           #+#    #+#             */
/*   Updated: 2021/07/25 22:45:00 by trossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *srci, int size);

void	parse_beginning(char **n, int *i, int *has_zeroes_first)
{
	*has_zeroes_first = 0;
	*i = 0;
	if ((*n)[*i] == '+')
		(*i)++;
	while ((*n)[*i] == '0')
	{
		*has_zeroes_first = 1;
		(*i)++;
	}
}

char	*parse_valid_unsigned_number(char *n)
{
	int		i;
	int		start;
	int		has_zeroes_first;

	parse_beginning(&n, &i, &has_zeroes_first);
	start = i;
	while (n[i] != '\0')
	{
		if (n[i] < '0' || n[i] > '9')
			return (NULL);
		i++;
	}
	if (i == start && has_zeroes_first)
		return (ft_strdup(&n[start - 1], 1));
	else if (i == start)
		return (NULL);
	else
		return (ft_strdup(&n[start], i - start));
}
