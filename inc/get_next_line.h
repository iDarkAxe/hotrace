/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:19:29 by ppontet           #+#    #+#             */
/*   Updated: 2026/02/28 14:06:34 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*get_next_line(int fd);
size_t		ft_strlcpy(char *dst, char *src, size_t size);
char		*ft_strjoin(char const *s1, char const *s2);
const char	*ft_strchr(const char *string, int searched_char);
size_t		ft_strlen(const char *the_string);

#endif
