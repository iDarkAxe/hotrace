/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:58:40 by ppontet           #+#    #+#             */
/*   Updated: 2026/02/28 14:42:27 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

/**
 * @brief Allocates a new string, and returns the result of
 * a concatenation of s1 and s2

 * @param s1 string 1
 * @param s2 string 2
 * @return char* new string
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*pointer;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	pointer = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (pointer == NULL)
		return (NULL);
	ft_memcpy(pointer, s1, s1_len);
	ft_memcpy(&pointer[s1_len], s2, s2_len);
	pointer[s1_len + s2_len] = '\0';
	return (pointer);
}
