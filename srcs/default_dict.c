/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trossel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 18:46:13 by trossel           #+#    #+#             */
/*   Updated: 2021/07/25 21:36:53 by trossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "dict.h"
#include "ft.h"

int	crt_n_add(t_dict *d, char *num, char *value)
{
	t_key	*k;

	k = malloc(sizeof(t_key));
	if (!k)
		return (1);
	k->num = num;
	k->value = value;
	k->n_digit = ft_strlen(k->num);
	k->freeable = 0;
	k->original = 1;
	add_key_to_dict(d, k);
	return (0);
}

int	rest_of_crt_default_dict(t_dict *d)
{
	int	e;

	e = 0;
	e += crt_n_add(d, "20", "twenty");
	e += crt_n_add(d, "30", "thirty");
	e += crt_n_add(d, "40", "forty");
	e += crt_n_add(d, "50", "fifty");
	e += crt_n_add(d, "60", "sixty");
	e += crt_n_add(d, "70", "seventy");
	e += crt_n_add(d, "80", "eighty");
	e += crt_n_add(d, "90", "ninety");
	e += crt_n_add(d, "100", "hundred");
	e += crt_n_add(d, "1000", "thousand");
	e += crt_n_add(d, "1000000", "million");
	e += crt_n_add(d, "1000000000", "billion");
	e += crt_n_add(d, "1000000000000", "trillion");
	e += crt_n_add(d, "1000000000000000", "quadrillion");
	e += crt_n_add(d, "1000000000000000000", "quintillion");
	e += crt_n_add(d, "1000000000000000000000", "sextillion");
	e += crt_n_add(d, "1000000000000000000000000", "septillion");
	e += crt_n_add(d, "1000000000000000000000000000", "octillion");
	e += crt_n_add(d, "1000000000000000000000000000000", "nonillion");
	e += crt_n_add(d, "1000000000000000000000000000000000", "decillion");
	e += crt_n_add(d, "1000000000000000000000000000000000000", "undecillion");
	return (e);
}

int	create_default_dict(t_dict *d)
{
	int	e;

	e = 0;
	e += crt_n_add(d, "0", "zero");
	e += crt_n_add(d, "1", "one");
	e += crt_n_add(d, "2", "two");
	e += crt_n_add(d, "3", "three");
	e += crt_n_add(d, "4", "four");
	e += crt_n_add(d, "5", "five");
	e += crt_n_add(d, "6", "six");
	e += crt_n_add(d, "7", "seven");
	e += crt_n_add(d, "8", "eight");
	e += crt_n_add(d, "9", "nine");
	e += crt_n_add(d, "10", "ten");
	e += crt_n_add(d, "11", "eleven");
	e += crt_n_add(d, "12", "twelve");
	e += crt_n_add(d, "13", "thirteen");
	e += crt_n_add(d, "14", "fourteen");
	e += crt_n_add(d, "15", "fifteen");
	e += crt_n_add(d, "16", "sixteen");
	e += crt_n_add(d, "17", "seventeen");
	e += crt_n_add(d, "18", "eighteen");
	e += crt_n_add(d, "19", "nineteen");
	e += rest_of_crt_default_dict(d);
	return (e);
}
