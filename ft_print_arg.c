/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:36:18 by supersko          #+#    #+#             */
/*   Updated: 2022/03/15 12:51:16 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t ft_print_arg(va_list *ap, char *after_percent)
{
	if (*after_percent == 'c')
		return (ft_print_char((char) va_arg(*ap, int)));
	if (*after_percent == 's')
		return (ft_print_str(va_arg(*ap, char *)));
	if (*after_percent == 'd' || after_percent == 'i')
		return (ft_print_int((int) va_arg(*ap, int)));
//	if (*after_percent == 'p' || after_percent == 'x')
//		return (ft_print_hex((long unsigned) va_arg(*ap, long unsigned), 0));
//	if (*after_percent == 'X')
//		return (ft_hex_to_str((long unsigned) va_arg(*ap, long unsigned), 1));
	else
		return (0);
}
