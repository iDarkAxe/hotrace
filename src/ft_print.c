/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 14:54:37 by ppontet           #+#    #+#             */
/*   Updated: 2026/03/01 14:57:49 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include "get_next_line.h"

void	ft_printf_err(int error)
{
	char	*err;

	err = strerror(error);
	write(2, err, ft_strlen(err));
}

void		print_value(char *key, char *value);

#if NO_PRINT == 0

inline void	print_value(char *key, char *value)
{
	if (!value)
	{
		write(1, key, ft_strlen(key));
		write(1, ": Not found.\n", 13);
	}
	else
	{
		write(1, value, ft_strlen(value));
		write(1, "\n", 1);
	}
}

#else

inline void	print_value(char *key, char *value)
{
	(void)key;
	(void)value;
}

#endif
