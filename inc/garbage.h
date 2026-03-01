/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:09:50 by ppontet           #+#    #+#             */
/*   Updated: 2026/03/01 14:59:09 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_H
# define GARBAGE_H

# include <stdbool.h>
# include <stdlib.h>

typedef struct s_element_gb	t_elem_gb;
typedef struct s_garbage	t_garbage;

/**
 * @brief Basic node for an element of a linked list
 *
 */
struct						s_element_gb
{
	void					*ptr;
	void					*next;
};

/**
 * @brief Head of the linked list
 *
 */
struct						s_garbage
{
	size_t					n_elements;
	t_elem_gb				*head;
};

/**
 * @defgroup Garbage Garbage functions
 * @brief Functions to simulate a garbage
 * @{
 */
// Function to replace all the malloc by this to use the garbage
bool						add_to_garbage(t_garbage *garbage, void *ptr);
void						free_element_gb(t_garbage *garbage, void *ptr);

// Initialise the garbage and free it's content
void						garbage_init(t_garbage *garbage);
void						free_garbage(t_garbage *garbage);

// Private functions for garbage management
// t_garbage					*get_garbage(void);
void						print_garbage(t_garbage *garbage);

// Garbage stack management
t_elem_gb					*ft_garbagenew(void *ptr);
void						ft_garbageadd_front(t_garbage *garbage,
								t_elem_gb *new);
int							ft_garbageclear(t_garbage *data);
/** @} */
#endif
