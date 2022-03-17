/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:54:04 by supersko          #+#    #+#             */
/*   Updated: 2022/03/17 12:01:50 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	while (*src && (dstsize-- - 1))
	{
		*(dst++) = *(src++);
	}
	*dst = '\0';
	return (src_len);
}

int	ft_is_flag(char c)
{
	char	flags[20];
	int		ii;

	ii = 0;
	ft_strlcpy(flags, "csdupxX%", 20);
	while (flags[ii])
		if (c == flags[ii++])
			return (1);
	return (0);
}

size_t	printing_loop(char *str, va_list *ap)
{
	size_t	len_str;
	size_t	len_str_written;
	int		is_flag;

	len_str_written = 0;
	while (*str)
	{
		is_flag = ft_is_flag(*(str + 1));
		if (*str == '%' && is_flag)
		{
			str++;
			len_str_written += ft_print_arg(ap, str);
			str++;
		}
		else if (*str == '%' && !is_flag)
			str++;
		else
		{
			len_str = ft_strlen_char(str, '%');
			len_str_written += write(1, str, len_str);
			str += len_str;
		}
	}
	return (len_str_written);
}

int	ft_printf(const char *str0, ...)
{
	va_list			ap;
	char			*str;
	size_t			len_str_written;

	str = (char *) str0;
	va_start(ap, str0);
	len_str_written = printing_loop(str, &ap);
	va_end(ap);
	return (len_str_written);
}

/*
//
// MAIN
int main(void)
{
	int strlen;

	strlen = ft_printf("%s\n%%\n%x\n%X\n%u\n%p\n",
		"0123456789", 16, 31, 999999999, &strlen);
	ft_printf("Nb args : %p\n", &strlen);
	strlen = printf("%s\n%%\n%x\n%X\n%u\n%p\n",
		"0123456789", 16, 31, 999999999, &strlen);
	ft_printf("Nb args : %p\n", &strlen);
}
*/
