/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 10:48:08 by ppontet           #+#    #+#             */
/*   Updated: 2026/03/01 17:55:27 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "garbage.h"
#include "get_next_line.h"
#include "hotrace.h"
#include <stdbool.h>
#include <stdlib.h>

bool	insert(t_hash *hashmap, char *key, char *value)
{
	size_t	index;
	t_ret	ret;
	size_t	value_len;
	size_t	hash_value;

	if (!hashmap || !key || add_to_garbage(hashmap->garbage, key))
		return (0);
	hash_value = hash(key);
	ret = find_suitable_index(hashmap, hash_value % (hashmap->data_size), key);
	if (!ret.success)
		return (0);
	index = ret.index;
	hashmap->data[index].key = key;
	if (hashmap->data[index].value == NULL)
		hashmap->n_elements++;
	value_len = ft_strlen(value);
	if (value_len > 0 && value[value_len - 1] == '\n')
		value[value_len - 1] = '\0';
	hashmap->data[index].value = value;
	if (add_to_garbage(hashmap->garbage, value) == 1)
		return (0);
	hashmap->data[index].hash_value = hash_value;
	return (1);
}

t_ret	find_suitable_index(t_hash *hashmap, size_t hash_value, char *key)
{
	bool	looped;
	size_t	index;

	index = hash_value % (hashmap->data_size);
	looped = 0;
	while (1)
	{
		if (hashmap->data[index].key != NULL && hashmap->data[index].hash_value
			== hash_value && ft_strcmp(key, hashmap->data[index].key) != 0)
			index++;
		else
			return ((t_ret){.success = true, .index = index});
		if (index > hashmap->data_size)
		{
			if (looped == 1)
				return ((t_ret){.success = false, .index = -1});
			index = 0;
			looped = 1;
		}
	}
}

char	*get(t_hash *hashmap, char *key)
{
	size_t	index;
	size_t	hash_value;
	t_ret	ret;

	if (!hashmap || !key)
		return (NULL);
	hash_value = hash(key);
	index = hash_value % hashmap->data_size;
	if (hashmap->data[index].key == NULL)
		return (NULL);
	else if (hashmap->data[index].hash_value == hash_value
		|| ft_strcmp(key, hashmap->data[index].key) == 0)
		return (hashmap->data[index].value);
	else
	{
		ret = find_suitable_index(hashmap, index, key);
		if (!ret.success)
			return (NULL);
		else
			return (hashmap->data[ret.index].value);
	}
}

#define HASHMAP_SIZE 1000000

t_hash	*create_hashmap(t_hash *hashmap)
{
	if (!hashmap)
		return (NULL);
	hashmap->data_size = HASHMAP_SIZE;
	hashmap->n_elements = 0;
	hashmap->data = malloc(sizeof(t_elem) * hashmap->data_size);
	if (!hashmap->data)
		return (NULL);
	hashmap->garbage = malloc(sizeof(t_garbage));
	if (!hashmap->garbage)
		return (NULL);
	garbage_init(hashmap->garbage);
	ft_memset(hashmap->data, 0, sizeof(t_elem) * hashmap->data_size);
	return (hashmap);
}

void	free_hashmap(t_hash *hashmap)
{
	if (!hashmap)
		return ;
	if (hashmap->data)
		free(hashmap->data);
	free_garbage(hashmap->garbage);
	free(hashmap->garbage);
}
