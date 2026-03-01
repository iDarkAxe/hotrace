/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 10:49:07 by ppontet           #+#    #+#             */
/*   Updated: 2026/03/01 14:53:41 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "hotrace.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void		ft_printf_err(int error);
void		read_hashmap(t_hash *hashmap);
void		fill_hashmap(t_hash *hashmap);

/**
 * @brief Executer Hotrace
 *
 * @return int
 */
int	main(void)
{
	t_hash	hashmap;

	if (create_hashmap(&hashmap) == NULL)
		return (EXIT_FAILURE);
	fill_hashmap(&hashmap);
	read_hashmap(&hashmap);
	free_hashmap(&hashmap);
	return (0);
}

bool	try_insert(t_hash *hashmap, char *key, char *value)
{
	if (insert(hashmap, key, value))
		return (true);
	else
	{
		ft_printf_err(errno);
		free(key);
		free(value);
		return (false);
	}
}

void	fill_hashmap(t_hash *hashmap)
{
	char	*key;
	char	*value;

	while (1)
	{
		key = get_next_line(0);
		if (!key)
			break ;
		if (key[0] == '\n' || (key[0] == '\r' && key[1] == '\n'))
		{
			free(key);
			break ;
		}
		value = get_next_line(0);
		if (!value)
		{
			free(key);
			break ;
		}
		if (try_insert(hashmap, key, value) == false)
			break ;
	}
}

void	read_hashmap(t_hash *hashmap)
{
	char	*key;
	char	*value;

	while (1)
	{
		key = get_next_line(0);
		if (!key)
			break ;
		if (key[0] == '\n')
		{
			free(key);
			continue ;
		}
		value = get(hashmap, key);
		print_value(key, value);
		free(key);
	}
}
