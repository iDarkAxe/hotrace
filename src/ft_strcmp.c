/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 14:52:22 by ppontet           #+#    #+#             */
/*   Updated: 2026/03/01 14:52:34 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strcmp(const char *first, const char *second);

int	ft_strcmp(const char *first, const char *second)
{
	size_t	index;

	index = 0;
	while (first[index] != '\0' && second[index] != '\0'
		&& first[index] == second[index])
		index++;
	return ((unsigned char)first[index] - (unsigned char)second[index]);
}
