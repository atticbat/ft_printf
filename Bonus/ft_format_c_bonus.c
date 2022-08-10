/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_c_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas <khatlas@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 21:36:50 by khatlas           #+#    #+#             */
/*   Updated: 2022/04/29 17:56:24 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdarg.h>
#include <stdlib.h>

static char	*right_just(t_parse *data, char pad, char *buffer, int to_malloc)
{
	char	*ptr;
	int		i;

	ptr = NULL;
	ptr = (char *) malloc (sizeof(char) * (to_malloc));
	if (!ptr)
		return (NULL);
	i = 0;
	ft_memset(ptr + i, pad, data->width);
	i += data->width;
	ft_memcpy(ptr + i, buffer, 1);
	i += 1;
	data->width = to_malloc;
	return (ptr);
}

static char	*left_just(t_parse *data, char pad, char *buffer, int to_malloc)
{
	char	*ptr;
	int		i;

	ptr = NULL;
	i = 0;
	ptr = (char *) malloc (sizeof(char) * (to_malloc));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr + i, buffer, 1);
	i += 1;
	ft_memset(ptr + i, pad, data->width);
	i += data->width;
	data->width = to_malloc;
	return (ptr);
}

static char	*parse_simple(t_parse *data)
{
	char	*buffer;

	buffer = data->arg_str;
	data->width = 1;
	return (buffer);
}

char	*ft_format_c(t_parse *data)
{
	char	pad;
	char	*buffer;
	int		to_malloc;

	if (!data->justi_zero && !data->width)
		return (parse_simple(data));
	pad = ' ';
	buffer = NULL;
	buffer = data->arg_str;
	if (data->width > 0)
		data->width -= 1;
	to_malloc = 1 + data->width;
	if (data->justi_zero == '-')
		return (left_just(data, pad, buffer, to_malloc));
	return (right_just(data, pad, buffer, to_malloc));
}
