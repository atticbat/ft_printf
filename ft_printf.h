/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas <khatlas@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 00:43:23 by khatlas           #+#    #+#             */
/*   Updated: 2022/05/01 10:34:19 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_parse
{
	char	type;
	char	sign;
	char	justi_zero;
	int		width;
	int		dot;
	int		precision;
	char	*arg_str;
}			t_parse;

int		ft_printf(const char *str, ...);
char	*ft_parse_c(va_list args);
char	*ft_parse_s(va_list args);
char	*ft_parse_i(va_list args);
char	*ft_parse_p(va_list args);
char	*ft_parse_pp(void);
char	*ft_parse_u(va_list args);
char	*ft_parse_x(va_list args, char *set);
char	*ft_itoa_base_u(unsigned long n, char *base);
t_parse	*parse(const char **str, va_list args);
char	*ft_format_i(t_parse *data);
char	*ft_format_s(t_parse *data);
char	*ft_format_c(t_parse *data);
char	*ft_format_x(t_parse *data);
char	*ft_format_pp(t_parse *data);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strchr(const char *str, int c);
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
char	*ft_itoa(int n);

#endif
