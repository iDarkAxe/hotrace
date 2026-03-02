/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 15:16:45 by ppontet           #+#    #+#             */
/*   Updated: 2026/03/02 22:15:08 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdint.h>

#define USE_GLOBAL 0

size_t			hash_fnv1(char *str);
size_t			hash_fnv1a(char *str);
size_t			hash_fnv0(char *str);

// -1 == error
#if USE_GLOBAL == 0

size_t	hash(char *str)
{
	if (!str)
		return (-1);
	return (hash_fnv1a(str));
}

#else

// static size_t			(*g_hash_strategy)(char *key) = &hash_fnv1;

size_t	hash(char *str)
{
	if (!str)
		return (-1);
	return (hash_strategy(str));
}

void	change_hash_strategy(enum e_hash_strat value)
{
	if (value == FNV1)
		g_hash_strategy = &hash_fnv1;
	else if (value == FNV1A)
		g_hash_strategy = &hash_fnv1a;
	else if (value == FNV0)
		g_hash_strategy = &hash_fnv0;
	else
		g_hash_strategy = &hash_fnv1;
}

enum e_hash_strat	find_hash_strategy(void)
{
	if (g_hash_strategy == &hash_fnv1)
		return (FNV1);
	if (g_hash_strategy == &hash_fnv1a)
		return (FNV1A);
	if (g_hash_strategy == &hash_fnv0)
		return (FNV0);
	return (END_VAL);
}

#endif
