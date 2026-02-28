/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:35:19 by ppontet           #+#    #+#             */
/*   Updated: 2026/02/28 13:51:20 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *the_string);

/**
 * @brief Len of string without '\0'
 *
 * @param the_string string to check
 * @return size_t len of the string
 */
size_t	ft_strlen(const char *the_string)
{
	size_t	count;

	if (the_string == NULL)
		return (0);
	count = 0;
	while (the_string[count] != '\0')
		count++;
	return (count);
}
