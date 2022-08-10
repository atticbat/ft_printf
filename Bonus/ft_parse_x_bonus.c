/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_x_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas <khatlas@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:19:03 by khatlas           #+#    #+#             */
/*   Updated: 2022/04/29 17:57:16 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdarg.h>
#include <stdlib.h>

char	*ft_parse_x(va_list args, char *set)
{
	unsigned int	buffer;

	buffer = 0;
	buffer = va_arg(args, unsigned int);
	return (ft_itoa_base_u((unsigned long) buffer, set));
}
