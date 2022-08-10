/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas <khatlas@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 22:01:53 by khatlas           #+#    #+#             */
/*   Updated: 2022/04/29 19:45:05 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

static char	*find_conv(const char c, va_list args, t_parse *data)
{
	if (c == 'c')
		return (ft_parse_c(args));
	else if (c == 's')
		return (ft_parse_s(args));
	else if (c == 'p')
		return (ft_parse_p(args));
	else if (c == 'i' || c == 'd')
		return (ft_parse_i(args));
	else if (c == 'u')
		return (ft_parse_u(args));
	else if (c == 'x')
		return (ft_parse_x(args, "0123456789abcdef"));
	else if (c == 'X')
		return (ft_parse_x(args, "0123456789ABCDEF"));
	else if (c == '%')
		return (ft_parse_pp());
	free (data);
	return (NULL);
}

static int	parse_width(const char **str)
{
	int		i;
	char	width[11];

	i = 0;
	while (ft_strchr("0123456789", **str) && i < 9)
	{
		width[i] = **str;
		i++;
		*str = *str + 1;
	}
	width[i] = '\0';
	return (ft_atoi(width));
}

static void	initialise_t_parse(t_parse *data)
{
	data->type = 0;
	data->sign = 0;
	data->justi_zero = 0;
	data->width = 0;
	data->dot = 0;
	data->precision = 0;
	data->arg_str = NULL;
}

static void	find_qualifiers(const char **str, t_parse *data)
{
	if (**str == ' ' || **str == '+' || **str == '#')
	{
		if (data->sign == '+' && **str == ' ')
			;
		else
			data->sign = **str;
		*str = *str + 1;
	}
	if (**str == '0' || **str == '-')
	{
		if (data->justi_zero == '-' && **str == '0')
			;
		else
			data->justi_zero = **str;
		*str = *str + 1;
	}
}

t_parse	*parse(const char **str, va_list args)
{
	t_parse	*data;

	data = malloc (sizeof (t_parse));
	if (!data)
		return (NULL);
	initialise_t_parse(data);
	while (ft_strchr(" +#0-", **str))
		find_qualifiers(str, data);
	if (ft_strchr("0123456789", **str))
		data->width = parse_width(str);
	if (**str == '.')
	{
		*str = *str + 1;
		data->dot = 1;
		data->precision = parse_width(str);
	}	
	data->arg_str = find_conv(**str, args, data);
	if (!data->arg_str)
		return (NULL);
	data->type = **str;
	if (data->sign == '#')
		data->sign = **str;
	return (data);
}
