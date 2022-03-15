/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:36:18 by supersko          #+#    #+#             */
/*   Updated: 2022/03/15 17:18:33 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_print_arg(va_list *ap, char *after_percent)
{
	if (*after_percent == 'c')
		return (ft_print_char((char) va_arg(*ap, int)));
	else if (*after_percent == 's')
		return (ft_print_str(va_arg(*ap, char *)));
	else if (*after_percent == 'd' || *after_percent == 'i')
		return (ft_print_int((long long int) va_arg(*ap, int), 10, 'm'));
	else if (*after_percent == 'u')
		return (ft_print_int((long long int) va_arg(*ap, unsigned int),
				10, 'm'));
	else if (*after_percent == 'p' || *after_percent == 'x')
		return (ft_print_int((long long int) va_arg(*ap, void *), 16, 'm'));
	else if (*after_percent == 'X')
		return (ft_print_int((long long int) va_arg(*ap, int), 16, 'M'));
	else if (*after_percent == '%')
		return (write(1, "%", 1));
	else
		return (0);
}
