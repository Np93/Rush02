/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvincent <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 10:10:48 by gvincent          #+#    #+#             */
/*   Updated: 2021/07/25 23:22:14 by trossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

#include "dict.h"
#include "ft.h"

char	*parse_valid_unsigned_number(char *n);
int		print_number_in_english(char *nb, int size, t_dict *dict);

int	rest_of_main(char *nbr, char *dict_file)
{
	t_dict	dictionary;
	int		error;

	dictionary.keys = NULL;
	nbr = parse_valid_unsigned_number(nbr);
	if (!nbr)
	{
		ft_putstr("Error\n");
		return (1);
	}
	error = parse_dict_from_file(dict_file, &dictionary);
	if (!error)
		error += print_number_in_english(nbr, ft_strlen(nbr), &dictionary);
	free(nbr);
	if (dictionary.keys != NULL)
		free_all_dict_keys(&dictionary);
	if (error)
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	return (error);
}

int	main(int argc, char **argv)
{
	if (argc > 3 || argc < 2)
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (argc == 3)
		return (rest_of_main(argv[2], argv[1]));
	else
		return (rest_of_main(argv[1], "numbers.dict"));
}
