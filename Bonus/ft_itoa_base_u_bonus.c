/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas <khatlas@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:12:07 by khatlas           #+#    #+#             */
/*   Updated: 2022/04/29 17:56:30 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdlib.h>

static size_t	count_digits(unsigned long n, size_t len)
{
	size_t	i;

	i = 0;
	while (n > 0)
	{
		n = n / len;
		i++;
	}
	return (i);
}

static int	fill_string(char *str, unsigned long n, char *base, size_t len)
{
	size_t	i;

	i = 0;
	if (n / len != 0)
		i = fill_string(str, n / len, base, len);
	str[i] = base[n % len];
	i++;
	str[i] = '\0';
	return (i);
}

char	*ft_itoa_base_u(unsigned long n, char *base)
{
	char	*ptr;
	size_t	len;

	if (!ft_strlen(base))
		return (NULL);
	len = count_digits(n, ft_strlen(base));
	if (len == 0)
		len = 1;
	ptr = (char *) malloc ((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	fill_string(ptr, n, base, ft_strlen(base));
	return (ptr);
}
