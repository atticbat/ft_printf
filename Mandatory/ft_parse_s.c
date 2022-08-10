/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas <khatlas@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:13:48 by khatlas           #+#    #+#             */
/*   Updated: 2022/04/29 17:58:28 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

char	*ft_parse_s(va_list args)
{
	char	*allocated;
	char	*buffer;

	allocated = NULL;
	buffer = NULL;
	buffer = va_arg(args, char *);
	if (buffer == NULL)
	{
		allocated = (char *) malloc ((7) * sizeof (char));
		if (!allocated)
			return (NULL);
		ft_memcpy(allocated, "(null)\0", 7);
	}
	else
	{
		allocated = (char *) malloc ((ft_strlen(buffer) + 1) * sizeof (char));
		if (!allocated)
			return (NULL);
		ft_memcpy(allocated, buffer, ft_strlen(buffer) + 1);
	}
	return (allocated);
}
