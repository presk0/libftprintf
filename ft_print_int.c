/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:23:22 by supersko          #+#    #+#             */
/*   Updated: 2022/03/15 12:54:55 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_recursive_print_int(long long int num, size_t *len)
{
	if (num < 10)
	{
		num += (long long int) '0';
		write(1, &num, 1);
	}
	else
	{
		ft_recursive_print_int(num / 10, len);
		ft_recursive_print_int(num % 10, len);
	}
	(*len)++;
}
			
size_t	ft_print_int(long long int num)
{
	size_t	len;

	len = 0;
	if (num < 0)
	{
			num *= -1;
			write (1, "-", 1);
	}
	ft_recursive_print_int(num, &len);
	return (len);
}
