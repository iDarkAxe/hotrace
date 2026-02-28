/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:47:08 by ppontet           #+#    #+#             */
/*   Updated: 2026/02/28 18:25:19 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "garbage.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Free an element in the garbage collector
 *
 * @param garbage garbage structure
 * @param ptr element to free
 */
void	free_element_gb(t_garbage *garbage, void *ptr)
{
	t_element_gb	*element;
	t_element_gb	*previous;

	if (!garbage)
		return ;
	element = garbage->head;
	previous = NULL;
	while (element != NULL)
	{
		if (element->ptr == ptr)
		{
			free(element->ptr);
			element->ptr = NULL;
			if (previous == NULL)
				garbage->head = garbage->head->next;
			else
				previous->next = element->next;
			free(element);
			element = NULL;
			ptr = NULL;
			return ;
		}
		previous = element;
		element = element->next;
	}
}

/**
 * @brief Print the garbage collector
 *
 */
void	print_garbage(t_garbage *garbage)
{
	t_element_gb	*element;

	element = garbage->head;
	while (element != NULL)
	{
		printf("Element %p has ptr : %p\n", (void *)element, element->ptr);
		element = element->next;
	}
}
