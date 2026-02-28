/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 15:16:45 by ppontet           #+#    #+#             */
/*   Updated: 2026/02/28 16:40:15 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdint.h>

#define USE_GLOBAL 0

size_t			hash_fnv1(const char *str);
size_t			hash_fnv1a(const char *str);
size_t			hash_fnv0(const char *str);

// -1 == error
#if USE_GLOBAL == 0

size_t	hash(const char *str)
{
	if (!str)
		return (-1);
	return (hash_fnv1(str));
}

#else

// static size_t			(*hash_strategy)(const char *key) = &hash_fnv1;

size_t	hash(const char *str)
{
	if (!str)
		return (-1);
	return (hash_strategy(str));
}

void	change_hash_strategy(enum e_hash_strategy value)
{
	if (value == FNV1)
		hash_strategy = &hash_fnv1;
	else if (value == FNV1A)
		hash_strategy = &hash_fnv1a;
	else if (value == FNV0)
		hash_strategy = &hash_fnv0;
	else
		hash_strategy = &hash_fnv1;
}

enum e_hash_strategy	find_hash_strategy(void)
{
	if (hash_strategy == &hash_fnv1)
		return (FNV1);
	if (hash_strategy == &hash_fnv1a)
		return (FNV1A);
	if (hash_strategy == &hash_fnv0)
		return (FNV0);
	return (END_VAL);
}

#endif
