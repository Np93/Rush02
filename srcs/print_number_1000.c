/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_en_anglais.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvincent <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:39:03 by gvincent          #+#    #+#             */
/*   Updated: 2021/07/25 18:30:20 by trossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "dict.h"

int	print_hundreds(char *nombre, int size, t_dict *dict)
{
	t_key	*key;

	if (size == 3 && nombre[size - 3] != '0')
	{
		key = find_key_with_num_and_size(dict, nombre, 1);
		ft_putstr(key->value);
		ft_putstr(" ");
		key = find_key_with_num_and_size(dict, nombre, 3);
		ft_putstr(key->value);
		return (100);
	}
	return (0);
}

int	print_tens(char *nombre, int size, int has_digit, t_dict *dict)
{
	t_key	*key;

	if (has_digit && (nombre[size - 2] != '0' || nombre[size - 1] != '0'))
		ft_putstr(" and ");
	if (size >= 2 && nombre[size - 2] != '0')
	{
		key = find_key_with_num_and_size(dict, &nombre[size - 2], 2);
		ft_putstr(key->value);
		return (10);
	}
	return (0);
}

int	print_units(char *nombre, int size, int has_digit, t_dict *dict)
{
	t_key	*key;

	if (size >= 2 && nombre[size - 2] == '1')
		return (0);
	if (has_digit && nombre[size - 1] == '0')
		return (0);
	if ((has_digit % 100) / 10 && nombre[size - 1] != '0')
		ft_putstr("-");
	if (ft_strlen(nombre) >= 1)
	{
		key = find_key_with_num_and_size(dict, &nombre[size - 1], 1);
		ft_putstr(key->value);
	}
	return (0);
}

int	print_number_1000(char *nombre, int size, t_dict *dict)
{
	int	has_digit;

	has_digit = 0;
	has_digit += print_hundreds(nombre, size, dict);
	has_digit += print_tens(nombre, size, has_digit, dict);
	has_digit += print_units(nombre, size, has_digit, dict);
	return (0);
}
