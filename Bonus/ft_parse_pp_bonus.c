/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_pp_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas <khatlas@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:19:42 by khatlas           #+#    #+#             */
/*   Updated: 2022/04/29 17:57:00 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdarg.h>
#include <stdlib.h>

char	*ft_parse_pp(void)
{
	char	*allocated;

	allocated = NULL;
	allocated = (char *) malloc (sizeof (char));
	if (!allocated)
		return (NULL);
	ft_memcpy(allocated, "%", 1);
	return (allocated);
}
