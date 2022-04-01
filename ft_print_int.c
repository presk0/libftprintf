/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:23:22 by supersko          #+#    #+#             */
/*   Updated: 2022/04/01 14:10:19 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_recursive_print_int(int num, size_t *len)
{
	if (num < 0)
	{
		if (num == -2147483648)
		{
			*len = write(1, "-2147483648", 11);
			return (*len);
		}
		num *= -1;
		*len += write (1, "-", 1);
	}
	if (num < 10)
	{
		num += '0';
		*len += write(1, &num, 1);
	}
	else
	{
		ft_recursive_print_int(num / 10, len);
		ft_recursive_print_int(num % 10, len);
	}
	return (*len);
}

size_t	ft_print_int(int num)
{
	size_t	len;

	len = 0;
	ft_recursive_print_int(num, &len);
	return (len);
}

size_t	ft_recursive_print_unsigned(unsigned int num, size_t *len)
{
	if (num < 10)
	{
		num += '0';
		*len += write(1, &num, 1);
	}
	else
	{
		ft_recursive_print_unsigned(num / 10, len);
		ft_recursive_print_unsigned(num % 10, len);
	}
	return (*len);
}

size_t	ft_print_unsigned(unsigned int num)
{
	size_t	len;

	len = 0;
	ft_recursive_print_unsigned(num, &len);
	return (len);
}

void	ft_recursive_print_hexa(long long unsigned int num,
		size_t *len, char CASE)
{
	if (num < 10)
	{
		num += '0';
		*len += write(1, &num, 1);
	}
	else if (num < 16 && CASE == 'M')
	{
		num += 'A' - 10;
		*len += write(1, &num, 1);
	}
	else if (num < 16 && CASE == 'm')
	{
		num += 'a' - 10;
		*len += write(1, &num, 1);
	}
	else
	{
		ft_recursive_print_hexa(num / 16, len, CASE);
		ft_recursive_print_hexa(num % 16, len, CASE);
	}
}
