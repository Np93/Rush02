/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trossel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:09:01 by trossel           #+#    #+#             */
/*   Updated: 2021/07/24 23:12:13 by trossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "dict.h"

void	free_all_keys_elements(t_key *key)
{
	if (key->freeable >= 1)
		free(key->value);
	if (key->freeable >= 2)
		free(key->num);
}

void	free_all_dict_keys(t_dict *dict)
{
	t_key	*key;
	t_key	*next_key;

	key = dict->keys;
	while (key->next != NULL)
	{
		next_key = key->next;
		free_all_keys_elements(key);
		free(key);
		key = next_key;
	}
}
