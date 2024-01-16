/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number_in_english.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trossel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:21:24 by trossel           #+#    #+#             */
/*   Updated: 2021/07/25 22:17:57 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "ft.h"

int	print_number_1000(char *nb, int size, t_dict *dict);

int	is_null(char *str, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (str[i++] != '0')
			return (0);
	}
	return (1);
}

int	function_split(int *diff_digit, char **nb, int *size, t_dict *dict)
{
	t_key	*key;

	while (*size >= 4)
	{
		key = find_key_with_num_and_size(dict, *nb, *size);
		if (!key)
			return (1);
		*diff_digit = *size - key->n_digit;
		if (*diff_digit > 2)
			return (1);
		if (!is_null(*nb, *diff_digit + 1))
		{
			print_number_1000(&(*nb)[0], 1 + *diff_digit, dict);
			ft_putstr(" ");
			ft_putstr(key->value);
		}
		*nb += 1 + *diff_digit;
		*size = key->n_digit - 1;
		if (*size == 3 && (*nb)[0] == '0' && !is_null(&(*nb)[1], 2))
			ft_putstr(" and ");
		else if (!is_null(*nb, 3))
			ft_putstr(", ");
	}
	return (0);
}

int	print_number_in_english(char *nb, int size, t_dict *dict)
{
	int		diff_digit;

	diff_digit = -1;
	if (function_split(&diff_digit, &nb, &size, dict))
		return (1);
	if (diff_digit == -1 || !is_null(nb, size))
		print_number_1000(nb, size, dict);
	ft_putstr("\n");
	return (0);
}
