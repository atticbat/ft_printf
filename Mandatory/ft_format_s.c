/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas <khatlas@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 21:36:50 by khatlas           #+#    #+#             */
/*   Updated: 2022/04/29 19:42:40 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

static char	*right_just(t_parse *data, char pad, char *buffer, int to_malloc)
{
	char	*ptr;
	int		i;
	int		len;

	ptr = NULL;
	len = ft_strlen(buffer);
	ptr = (char *) malloc (sizeof(char) * (to_malloc + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	if (data->sign && data->width)
	{
		ptr[i] = data->sign;
		data->width--;
		i++;
	}
	ft_memset(ptr + i, pad, data->width);
	i += data->width;
	ft_memcpy(ptr + i, buffer, to_malloc - data->width);
	i += (to_malloc - data->width - 1);
	ptr[i] = '\0';
	return (ptr);
}

static char	*left_just(t_parse *data, char pad, char *buffer, int to_malloc)
{
	char	*ptr;
	int		i;
	int		len;

	ptr = NULL;
	len = (int) ft_strlen(buffer);
	i = 0;
	ptr = (char *) malloc (sizeof(char) * (to_malloc + 1));
	if (!ptr)
		return (NULL);
	if (data->sign && data->width)
	{
		ptr[i] = data->sign;
		data->width--;
		i++;
	}
	ft_memcpy(ptr + i, buffer, to_malloc - 1);
	i += (to_malloc - data->width - 1);
	ft_memset(ptr + i, pad, data->width);
	i += data->width;
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_format_s(t_parse *data)
{
	char	pad;
	char	*buffer;
	int		has_sign;
	int		to_malloc;
	int		len;

	buffer = NULL;
	buffer = data->arg_str;
	len = ft_strlen(data->arg_str);
	has_sign = 0;
	pad = ' ';
	if (data->precision < len && data->dot)
		len = data->precision;
	if (data->sign != 0)
		has_sign = 1;
	data->width -= (len);
	if (data->width < 0)
		data->width = 0;
	to_malloc = len + has_sign + data->width + 1;
	if (data->justi_zero == '-')
		return (left_just(data, pad, buffer, to_malloc));
	return (right_just(data, pad, buffer, to_malloc));
}
