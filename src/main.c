/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 10:49:07 by ppontet           #+#    #+#             */
/*   Updated: 2026/02/28 14:12:40 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "hotrace.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	ft_printf_err(int error);
void	read_hashmap(t_hash *hashmap);
void	fill_hashmap(t_hash *hashmap);

/**
 * @brief Executer Hotrace
 *
 * @return int
 */
int	main(void)
{
	t_hash	*hashmap;

	hashmap = create_hashmap(4);
	if (!hashmap)
		return (1);
	fill_hashmap(hashmap);
	read_hashmap(hashmap);
	free_hashmap(hashmap);
	return (0);
}

void	ft_printf_err(int error)
{
	char	*err;

	err = strerror(error);
	write(2, err, ft_strlen(err));
}

void	fill_hashmap(t_hash *hashmap)
{
	char	*key;
	char	*value;

	while (1)
	{
		key = get_next_line(0);
		if (!key || key[0] == '\0')
			break ;
		value = get_next_line(0);
		if (!value || value[0] == '\0')
		{
			free(key);
			break ;
		}
		if (insert(hashmap, key, value) == 0)
		{
			ft_printf_err(errno);
			free(key);
			free(value);
			break ;
		}
		return ;
	}
}

void	read_hashmap(t_hash *hashmap)
{
	char	*key;
	char	*value;

	while (1)
	{
		key = get_next_line(0);
		if (!key || key[0] == '\0')
			break ;
		value = get(hashmap, key);
		if (!value || value[0] == '\0')
			printf("%s: Not found.\n", key);
		else
		{
			printf("%s\n", value);
			free(value);
		}
		free(key);
	}
}
