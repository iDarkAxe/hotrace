/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_strategy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:30:38 by ppontet           #+#    #+#             */
/*   Updated: 2026/03/01 13:14:42 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

#define FNV_OFFSET_BASIS 0xcbf29ce484222325
#define FNV_PRIME 1099511628211

// ref: wikipedia Fowler–Noll–Vo hash function

size_t	hash_fnv1(char *str)
{
	uint64_t	hash_ret;
	size_t		index;

	if (!str)
		return (-1);
	hash_ret = FNV_OFFSET_BASIS;
	index = 0;
	while (str[index] != '\0')
	{
		hash_ret *= FNV_PRIME;
		hash_ret ^= str[index];
		index++;
	}
	if (index >= 1 && str[index - 1] == '\n')
		str[index - 1] = '\0';
	return (hash_ret);
}

// Should have 'better' avalanche characteristics
size_t	hash_fnv1a(char *str)
{
	uint64_t	hash_ret;
	size_t		index;

	if (!str)
		return (-1);
	hash_ret = FNV_OFFSET_BASIS;
	index = 0;
	while (str[index] != '\0')
	{
		hash_ret ^= str[index];
		hash_ret *= FNV_PRIME;
		index++;
	}
	if (index >= 1 && str[index - 1] == '\n')
		str[index - 1] = '\0';
	return (hash_ret);
}

size_t	hash_fnv0(char *str)
{
	uint64_t	hash_ret;
	size_t		index;

	if (!str)
		return (-1);
	hash_ret = 0;
	index = 0;
	while (str[index] != '\0')
	{
		hash_ret *= FNV_PRIME;
		hash_ret ^= str[index];
		index++;
	}
	if (index >= 1 && str[index - 1] == '\n')
		str[index - 1] = '\0';
	return (hash_ret);
}
