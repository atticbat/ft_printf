/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas <khatlas@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:18:14 by khatlas           #+#    #+#             */
/*   Updated: 2022/04/29 17:58:33 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

char	*ft_parse_u(va_list args)
{
	char			*allocated;
	unsigned int	buffer;

	allocated = NULL;
	buffer = 0;
	buffer = va_arg(args, unsigned int);
	return (ft_itoa_base_u(buffer, "0123456789"));
}
