/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:54:04 by supersko          #+#    #+#             */
/*   Updated: 2022/03/15 12:36:52 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printf(const char *str0, ...)
{
	va_list			ap;
	char			*str;
	size_t			len_str_written;
	size_t			len_str;

	str = (char *) str0;
	va_start(ap, str0);
	len_str_written = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			len_str_written += ft_print_arg(&ap, str++);
		}
		else
		{
			len_str = ft_strlen_char(str, '%');
			len_str_written += write(1, str, len_str);
			str += len_str;
		}
	}
	va_end(ap);
	return (len_str_written);
}
//
// MAIN
int main(void)
{
	int strlen;

	strlen = ft_printf("%s\n", "une ch[i]aine de vit");
	ft_printf("Nb args : %d\n", strlen);
}
