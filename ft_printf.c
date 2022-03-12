/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:54:04 by supersko          #+#    #+#             */
/*   Updated: 2022/03/12 17:50:43 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int ft_printf(const char *str0, ...)
{
	va_list			ap;
	char			str;
	unsigned int	len_str;
	int				len_str_written

	str = (char *) str0;
	va_start(ap, str);
	len_str_written = 0;
	while (*str)
	{
		if (*str == '%' && ((str - 1) != '\\' || str == str0))
		{
			// len_str_written += ft_print_arg;
			str++;
		}
		else
		{
			len_str = ft_strlen_char(str, '%');
			write(1, str, len_str);
			str += len_str;
			len_str_written += len_str;
		}
	}
	va_end(ap);
	return (0);
}

//
// MAIN
int main(void)
{
	ft_printf("", 1, 2, 3);
}
