/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas <khatlas@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:14:01 by khatlas           #+#    #+#             */
/*   Updated: 2022/04/29 17:58:06 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

char	*ft_parse_c(va_list args)
{
	char	*allocated;
	char	buffer;

	allocated = NULL;
	buffer = 0;
	allocated = (char *) malloc (sizeof (char));
	if (!allocated)
		return (NULL);
	buffer = va_arg(args, int);
	ft_memcpy(allocated, &buffer, 1);
	return (allocated);
}
