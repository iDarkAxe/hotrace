/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:27:52 by ppontet           #+#    #+#             */
/*   Updated: 2026/02/28 18:25:21 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "garbage.h"
#include "get_next_line.h"
#include <stdlib.h>

/**
 * @brief Get the garbage object
 *
 * @return t_garbage* garbage access
 */
// t_garbage	*get_garbage(void)
// {
// 	static t_garbage	garbage;

// 	return (&garbage);
// }`

/**
 * @brief Initialize the garbage and sets the values to 0
 *
 */
void	garbage_init(t_garbage	*garbage)
{
	ft_memset(garbage, 0, sizeof(garbage));
	garbage->head = NULL;
	garbage->n_elements = 0;
}

/**
 * @brief Add a pointer to the garbage list
 *
 * @param garbage garbage structure
 * @param ptr pointer to add
 */
bool	add_to_garbage(t_garbage *garbage, void *ptr)
{
	void		*temp;

	temp = ft_garbagenew(ptr);
	if (temp == NULL)
	{
		free(ptr);
		free_garbage(garbage);
		return (1);
	}
	ft_garbageadd_front(garbage, temp);
	garbage->n_elements++;
	return (0);
}

/**
 * @brief Free the garbage
 *
 */
void	free_garbage(t_garbage *garbage)
{
	ft_garbageclear(garbage);
}
