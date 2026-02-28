/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 10:48:08 by ppontet           #+#    #+#             */
/*   Updated: 2026/02/28 18:55:16 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "garbage.h"
#include "get_next_line.h"
#include "hotrace.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> // strdup

int	ft_strcmp(const char *first, const char *second)
{
	size_t	index;

	index = 0;
	while (first[index] != '\0' && second[index] != '\0'
		&& first[index] == second[index])
		index++;
	return ((unsigned char)first[index] - (unsigned char)second[index]);
}

bool	insert(t_hash *hashmap, char *key, char *value)
{
	bool	looped;
	size_t	index;

	if (!hashmap || !key)
		return (-1);
	index = hash(key) % (hashmap->data_size);
	looped = 0;
	while (1)
	{
		if (hashmap->data[index].key != NULL && ft_strcmp(key,
				hashmap->data[index].key) != 0)
			index++;
		else
			break ;
		if (index > hashmap->data_size)
		{
			if (looped == 1)
				return (0);
			index = 0;
			looped = 1;
		}
	}
	if (hashmap->data[index].key != NULL)
		free(key);
	else
		hashmap->data[index].key = key;
	add_to_garbage(hashmap->garbage, key);
	if (hashmap->data[index].value == NULL)
		hashmap->n_elements++;
	hashmap->data[index].value = value;
	add_to_garbage(hashmap->garbage, value);
	return (1);
}

char	*get(t_hash *hashmap, const char *key)
{
	size_t	index;
	bool	looped;

	if (!hashmap || !key)
		return (NULL);
	index = hash(key) % hashmap->data_size;
	if (hashmap->data[index].key == NULL)
		return (NULL);
	else if (ft_strcmp(key, hashmap->data[index].key) == 0)
		return (hashmap->data[index].value);
	else
	{
		looped = 0;
		while (1)
		{
			if (hashmap->data[index].key != NULL && ft_strcmp(key,
					hashmap->data[index].key) != 0)
				index++;
			else
				return (hashmap->data[index].value);
			if (index > hashmap->data_size)
			{
				if (looped == 1)
					return (NULL);
				index = 0;
				looped = 1;
			}
		}
	}
}

#define HASHMAP_SIZE 1000000

t_hash	*create_hashmap(t_hash *hashmap)
{
	if (!hashmap)
		return (NULL);
	hashmap->data_size = HASHMAP_SIZE;
	hashmap->n_elements = 0;
	hashmap->data = malloc(sizeof(t_element) * hashmap->data_size);
	if (!hashmap->data)
		return (NULL);
	hashmap->garbage = malloc(sizeof(t_garbage));
	if (!hashmap->garbage)
		return (NULL);
	garbage_init(hashmap->garbage);
	ft_memset(hashmap->data, 0, sizeof(t_element) * hashmap->data_size);
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
