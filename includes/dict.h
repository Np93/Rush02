#ifndef DICT_H
# define DICT_H

typedef struct s_key
{
	char			*num;
	char			*value;
	struct s_key	*next;
	int				freeable;
	int				n_digit;
	int				original;
}	t_key;

typedef struct s_dict
{
	t_key	*keys;
}	t_dict;

t_key	*find_key_with_num_and_size(t_dict *dict, char *num, int size);

int		create_default_dict(t_dict *d);

int		parse_dict_from_file(char *file_name, t_dict *dict);

t_key	*parse_key_from_line(char *line, int length);

void	add_key_to_dict(t_dict *dict, t_key *new_key);

void	free_all_dict_keys(t_dict *dict);

void	free_all_keys_elements(t_key *key);

#endif
