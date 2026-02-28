/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 17:12:49 by ppontet           #+#    #+#             */
/*   Updated: 2026/02/28 17:14:45 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

/**
 * @brief Set a memory zone with a value, count times
 * Faster version of ft_memset,
 *
 * @param pointer memory zone to set
 * @param value value to set
 * @param count number of times to set the value
 * @return void* pointer to the memory zone
 */
void	*ft_memset(void *pointer, int value, size_t count)
{
	size_t		i;
	uint8_t		*ptr;
	uint32_t	*ptr32;
	uint32_t	block;

	i = 0;
	ptr = (uint8_t *)pointer;
	while (i < count && ((uintptr_t)(ptr + i) % 4) != 0)
		ptr[i++] = (unsigned char)value;
	ptr32 = (uint32_t *)(void *)(ptr + i);
	block = (uint8_t)value * 0x01010101;
	while (i + 4 <= count)
	{
		*ptr32++ = block;
		i += 4;
	}
	ptr = (uint8_t *)ptr32;
	while (i < count)
		ptr[i++ - ((uintptr_t)ptr - (uintptr_t)pointer)] = (unsigned char)value;
	return (pointer);
}
