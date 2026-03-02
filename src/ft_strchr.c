/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:15:41 by ppontet           #+#    #+#             */
/*   Updated: 2026/03/02 09:53:17 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

const char	*ft_strchr(const char *string, int searched_char);

/**
 * @brief Find first occurrence of searched_char
 *
 * @param string string to search in
 * @param searched_char char to search
 * @return char* index of Char found
 */
const char	*ft_strchr(const char *string, int searched_char)
{
	unsigned long int	i;

	i = 0;
	if (string == NULL)
		return (NULL);
	while (string[i] != '\0')
	{
		if (string[i] == (char)searched_char)
			return (&string[i]);
		i++;
	}
	if (string[i] == (char)searched_char)
		return (&string[i]);
	return (NULL);
}
