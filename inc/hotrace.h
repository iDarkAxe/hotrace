/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 10:47:28 by ppontet           #+#    #+#             */
/*   Updated: 2026/02/28 14:06:07 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// Autorized Functions
// read
// write
// malloc
// free
// strerror
// The compiler directive: __asm__

#include <stddef.h>

typedef struct s_hash	t_hash;

struct					s_hash
{
	char				**data;
	size_t				data_size;
	size_t				n_elements;
};

t_hash					*create_hashmap(size_t starting_size);
void					free_hashmap(t_hash *hashmap);
size_t					hash(const char *str);
int						insert(t_hash *hashmap, const char *key,
							const char *value);
char					*get(t_hash *hashmap, const char *key);
