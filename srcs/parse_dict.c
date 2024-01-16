/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 22:19:31 by nhirzel           #+#    #+#             */
/*   Updated: 2021/07/25 22:19:47 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "ft.h"
#include "dict.h"
#include "ft_strjoin.h"

#define BUFFER_NBYTES_MAX 2048

void	add_key_to_dict(t_dict *dict, t_key *new_key)
{
	t_key	*key;

	key = dict->keys;
	new_key->next = NULL;
	if (key == NULL)
	{
		dict->keys = new_key;
		return ;
	}
	while (key->next != NULL)
	{
		if (!ft_strcmp(new_key->num, key->num))
		{
			if (ft_strcmp(new_key->value, key->value))
			{
				key->value = new_key->value;
				key->freeable = 1;
			}
			free(new_key->num);
			free(new_key);
			return ;
		}
		key = key->next;
	}
	key->next = new_key;
}

int	parse_dict_from_string(char *str, t_dict *dict)
{
	int		i;
	int		start_line;
	t_key	*key;

	i = 0;
	while (str[i] != '\0')
	{
		start_line = i;
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		if (start_line == i)
		{
			i++;
			continue ;
		}
		key = parse_key_from_line(&str[start_line], i - start_line);
		if (!key)
		{
			return (1);
		}
		add_key_to_dict(dict, key);
		i++;
	}
	return (0);
}

int	parse_dict_from_file(char *file_name, t_dict *dict)
{
	int		fd;
	int		n_bytes;
	char	buffer[BUFFER_NBYTES_MAX];
	char	*file_text;
	char	*tmp_file_text;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (1);
	file_text = malloc(1);
	file_text[0] = '\0';
	n_bytes = read(fd, &buffer, BUFFER_NBYTES_MAX - 1);
	while (n_bytes != 0)
	{
		buffer[n_bytes] = '\0';
		tmp_file_text = file_text;
		file_text = ft_strjoin(tmp_file_text, buffer, "");
		free(tmp_file_text);
		n_bytes = read(fd, &buffer, BUFFER_NBYTES_MAX - 1);
	}
	close(fd);
	fd = parse_dict_from_string(file_text, dict);
	free(file_text);
	return (fd);
}
