/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 10:48:08 by ppontet           #+#    #+#             */
/*   Updated: 2026/02/28 14:12:36 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdlib.h>
#include <string.h> // strdup

// -1 == error
size_t	hash(const char *str)
{
	if (!str)
		return (-1);
	return (str[0]);
}

int	insert(t_hash *hashmap, const char *key, const char *value)
{
	(void)hashmap;
	(void)key;
	(void)value;
	if (!hashmap || !key)
		return (-1);
	return (0);
}

char	*get(t_hash *hashmap, const char *key)
{
	if (!hashmap || !key)
		return (NULL);
	return (strdup("Clé trouvée"));
}

t_hash	*create_hashmap(size_t starting_size)
{
	t_hash	*hashmap;

	hashmap = malloc(sizeof(t_hash));
	if (!hashmap)
		return (NULL);
	hashmap->data_size = starting_size;
	hashmap->n_elements = 0;
	hashmap->data = 0;
	return (hashmap);
}

void	free_hashmap(t_hash *hashmap)
{
	if (!hashmap)
		return ;
	if (hashmap->data)
		free(hashmap->data);
	free(hashmap);
}
