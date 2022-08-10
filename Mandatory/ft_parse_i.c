/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas <khatlas@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:17:34 by khatlas           #+#    #+#             */
/*   Updated: 2022/04/29 17:58:11 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*ft_parse_i(va_list args)
{
	int	buffer;

	buffer = 0;
	buffer = va_arg(args, int);
	return (ft_itoa (buffer));
}
