/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas <khatlas@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 21:36:50 by khatlas           #+#    #+#             */
/*   Updated: 2022/05/01 12:42:51 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

static int	put_hash(t_parse *data, char *ptr)
{
	*ptr = '0';
	*(ptr + 1) = data->sign;
	data->sign = 0;
	return (2);
}

static char	*right_just(t_parse *data, char pad, char *buffer, char *ptr)
{
	int		i;
	int		len;

	len = ft_strlen(buffer);
	i = 0;
	if ((data->sign && (pad == '0' || data->precision)) && !(data->width))
		i += put_hash(data, ptr + i);
	ft_memset(ptr + i, pad, data->width);
	i += data->width;
	if (data->width && data->sign)
		i += put_hash(data, ptr + i);
	ft_memset(ptr + i, '0', data->precision);
	i += data->precision;
	if (data->sign && *buffer)
		i += put_hash(data, ptr + i);
	ft_memcpy(ptr + i, buffer, len);
	i += len;
	ptr[i] = '\0';
	return (ptr);
}

static char	*left_just(t_parse *data, char pad, char *buffer, char *ptr)
{
	int		i;
	int		len;

	len = (int) ft_strlen(buffer);
	i = 0;
	if (data->sign)
		i += put_hash(data, ptr + i);
	ft_memset(ptr + i, '0', data->precision);
	i += data->precision;
	ft_memcpy(ptr + i, buffer, len);
	i += len;
	ft_memset(ptr + i, pad, data->width);
	i += data->width;
	ptr[i] = '\0';
	return (ptr);
}

static char	*make_malloc(t_parse *data, char *buffer, int has_sign)
{
	int		len;
	char	*ptr;

	ptr = NULL;
	len = (int) ft_strlen(buffer);
	data->precision -= len;
	if (data->precision < 0)
		data->precision = 0;
	data->width -= (data->precision + len + has_sign);
	if (data->width < 0)
		data->width = 0;
	if (*buffer == '\0')
		len++;
	len = len + has_sign + data->width + data->precision;
	ptr = (char *) malloc (sizeof(char) * (len + 1));
	return (ptr);
}

char	*ft_format_x(t_parse *data)
{
	char	pad;
	char	*buffer;
	int		has_sign;
	char	*allocated;

	has_sign = 0;
	pad = ' ';
	buffer = NULL;
	buffer = data->arg_str;
	if (*buffer == '0' && data->dot == 1 && !(data->precision))
		*buffer = '\0';
	if (data->sign != 0 && *buffer != '0')
		has_sign = 2;
	if (*buffer == '0')
		data->sign = 0;
	allocated = make_malloc(data, buffer, has_sign);
	if (!allocated)
		return (NULL);
	if (data->justi_zero == '0' && !(data->dot))
		pad = '0';
	if (data->justi_zero == '-')
		return (left_just(data, pad, buffer, allocated));
	return (right_just(data, pad, buffer, allocated));
}
