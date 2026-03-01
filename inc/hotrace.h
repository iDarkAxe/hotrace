/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 10:47:28 by ppontet           #+#    #+#             */
/*   Updated: 2026/03/01 14:59:17 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "garbage.h"
#include <stdbool.h>

#define NO_PRINT 1

typedef struct s_hash	t_hash;
typedef struct s_elem	t_elem;
typedef struct s_ret	t_ret;

struct					s_hash
{
	t_elem				*data;
	t_garbage			*garbage;
	size_t				data_size;
	size_t				n_elements;
};

struct					s_elem
{
	char				*key;
	char				*value;
};

struct					s_ret
{
	size_t				index;
	bool				success;
};

t_ret					find_suitable_index(t_hash *hashmap, size_t index,
							char *key);

t_hash					*create_hashmap(t_hash *hashmap);
void					free_hashmap(t_hash *hashmap);
bool					insert(t_hash *hashmap, char *key, char *value);
char					*get(t_hash *hashmap, char *key);

enum					e_hash_strat
{
	FNV1,
	FNV1A,
	FNV0,
	END_VAL = -1
};

size_t					hash(char *str);
void					change_hash_strat(enum e_hash_strat value);
enum e_hash_strat		find_hash_strategy(void);

// Print
void					print_value(char *key, char *value);
void					ft_printf_err(int error);
