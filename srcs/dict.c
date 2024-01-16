/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 22:18:56 by nhirzel           #+#    #+#             */
/*   Updated: 2021/07/25 23:12:04 by trossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "dict.h"
#include "ft.h"

const char	*g_original_value[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8",
	"9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "30",
	"40", "50", "60", "70", "80", "90", "100", "1000", "1000000", "1000000000",
	"1000000000000", "1000000000000000", "1000000000000000000",
	"1000000000000000000000", "1000000000000000000000000",
	"1000000000000000000000000000", "1000000000000000000000000000000",
	"1000000000000000000000000000000000",
	"1000000000000000000000000000000000000"};

int	is_original(char *s)
{
	int	i;

	i = 0;
	while (i < 41)
	{
		if (!ft_strcmp(s, g_original_value[i]))
			return (1);
		i++;
	}
	return (0);
}

t_key	*find_key_with_num_and_size(t_dict *dict, char *num, int size)
{
	t_key	*key;
	t_key	*best_key;

	best_key = NULL;
	key = dict->keys;
	while (key != NULL)
	{
		if (is_original(key->num) && key->n_digit <= size)
		{
			if (!best_key)
				best_key = key;
			else if (key->n_digit > best_key->n_digit)
				best_key = key;
			else if (ft_strcmp(key->num, best_key->num) > 0
				 && ft_strcmp(num, key->num) >= 0)
				best_key = key;
		}
		key = key->next;
	}
	return (best_key);
}
