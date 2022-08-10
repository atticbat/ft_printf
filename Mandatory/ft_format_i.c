/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas <khatlas@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 21:36:50 by khatlas           #+#    #+#             */
/*   Updated: 2022/04/29 19:41:01 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

static int	pad_zero(t_parse *data, char *ptr, char pad)
{
	if (data->sign && ((!(data->width) && data->precision) || pad == '0'))
	{
		*ptr = data->sign;
		data->sign = 0;
		return (1);
	}
	return (0);
}

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
	i += pad_zero(data, ptr, pad);
	ft_memset(ptr + i, pad, data->width);
	i += data->width;
	if (data->sign && pad != '0')
	{
		ptr[i] = data->sign;
		i++;
	}
	ft_memset(ptr + i, '0', data->precision);
	i += data->precision;
	ft_memcpy(ptr + i, buffer, len);
	i += len;
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
	if (data->sign)
	{
		ptr[i] = data->sign;
		i++;
	}
	ft_memset(ptr + i, '0', data->precision);
	i += data->precision;
	ft_memcpy(ptr + i, buffer, len);
	i += len;
	ft_memset(ptr + i, pad, data->width);
	i += data->width;
	ptr[i] = '\0';
	return (ptr);
}

static int	calc_malloc(t_parse *data, char *buffer, int has_sign)
{
	int	len;

	len = (int) ft_strlen(buffer);
	data->precision -= len;
	if (data->precision < 0)
		data->precision = 0;
	data->width -= (data->precision + len + has_sign);
	if (data->width < 0)
		data->width = 0;
	if (*buffer == '\0')
		len++;
	return (len + has_sign + data->width + data->precision);
}

char	*ft_format_i(t_parse *data)
{
	char	pad;
	char	*buffer;
	int		has_sign;
	int		to_malloc;

	has_sign = 0;
	pad = ' ';
	buffer = NULL;
	buffer = data->arg_str;
	if (*buffer == '0' && data->dot && !(data->precision))
		*buffer = '\0';
	if (*buffer == '-')
	{
		data->sign = '-';
		buffer++;
	}
	if (data->sign != 0)
		has_sign = 1;
	to_malloc = calc_malloc(data, buffer, has_sign);
	if (data->justi_zero == '0' && !(data->dot))
		pad = '0';
	if (data->justi_zero == '-')
		return (left_just(data, pad, buffer, to_malloc));
	return (right_just(data, pad, buffer, to_malloc));
}
