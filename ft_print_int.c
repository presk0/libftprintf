/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:23:22 by supersko          #+#    #+#             */
/*   Updated: 2022/03/17 11:54:05 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_recursive_print_int(long unsigned int num,
	size_t *len, int base, char CASE)
{
	if (num < (long unsigned int)base && base < 36)
	{
		if (num < 10)
		{
			num += (long unsigned int) '0';
			write(1, &num, 1);
		}
		else if (CASE == 'M')
		{
			num += (long unsigned int) 'A' - 10;
			write(1, &num, 1);
		}
		else
		{
			num += (long unsigned int) 'a' - 10;
			write(1, &num, 1);
		}
	}
	else
	{
		ft_recursive_print_int(num / base, len, base, CASE);
		ft_recursive_print_int(num % base, len, base, CASE);
	}
	(*len)++;
}

size_t	ft_print_int(long long int num, int base, char CASE, int is_addr)
{
	size_t	len;

	len = 0;
	if (is_addr)
		len += write(1, "0x", 2);
	if (num < 0)
	{
		num *= -1;
		write (1, "-", 1);
	}
	ft_recursive_print_int((long unsigned) num, &len, base, CASE);
	return (len);
}
