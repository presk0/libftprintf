/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:54:04 by supersko          #+#    #+#             */
/*   Updated: 2022/03/13 17:44:47 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int ft_printf(const char *str0, ...)
{
	va_list			ap;
	char			*str;
	unsigned int	len_str;
	size_t			len_str_written;
	char			*types_tab;
	char			**args_tab;
	unsigned int	ii;

	str = (char *) str0;
	va_start(ap, str0);
	len_str_written = 0;
	types_tab = ft_get_type_tab(str);
	args_tab = ft_arg_to_str_tab(ap, types_tab);
	ii = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str += 2;
			len_str_written += ft_print_str(args_tab[ii++]);
		}
		else
		{
			len_str = ft_strlen_char(str, '%');
			write(1, str, len_str);
			str += len_str;
		}
		len_str_written += len_str;
	}
	while (--ii)
		free(args_tab[ii]);
	free(args_tab);
	va_end(ap);
	return (len_str_written);
}

//
// MAIN
int main(void)
{
	ft_printf("%c %c %c", 'a', 'b', 'c');
}
