/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:23:22 by supersko          #+#    #+#             */
/*   Updated: 2022/03/18 22:40:04 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
static char	*ft_rev_str(char *str[])
{
	int		max;
	int		ii;
	char	tmp;

	ii = 0;
	max = ft_strlen_char(*str, '\0');
	while (ii < max / 2)
	{
		tmp = *str[ii];
		*str[ii] = *str[(max - 1) - ii];
		*str[(max - 1) - ii++] = tmp;
	}
	return (*str);
}
*/

size_t	ft_print_str(char *str)
{
	size_t	len_str;

	if (!str)
		 return (write(1, "(null)", 6));
	len_str = ft_strlen_char(str, '\0');
	if (!len_str)
		return (0);
	write(1, str, len_str);
	return (len_str);
}

size_t	ft_print_char(char c)
{
	if (!c)
		return (write(1, "(null)", 6));
	return (write(1, &c, 1));
}
/*
size_t	ft_print_int(int num)
{
	char	rev_str[50] = { 0 };
	int		sign;
	int		ii;

	if (!num)
		 return (write(1, "(null)", 6));
	sign = 0;
	if (num < 0)
	{
		if (num == -2147483648)
			return (write(1, "-2147483648", 11));
		sign = -1;
		num *= -1;
	}
	ii = 0;
	while (num)
	{
		rev_str[ii++] = (char) (num % 10) + '0';
		num /= 10;
	}
	if (sign)
		rev_str[ii++] = '-';
	ft_rev_str(&rev_str);
	return (write(1, rev_str, ii - 1) + sign);
}
*/

size_t ft_recursive_print_int(int num, size_t *len)
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

size_t ft_recursive_print_unsigned(unsigned int num, size_t *len)
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

void	ft_recursive_print_hexa(long long unsigned int num, size_t *len, char CASE)
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

size_t	ft_print_hexa(long long unsigned int num, char CASE)
{
	size_t	len;

	len = 0;
	ft_recursive_print_hexa((long long unsigned int) num, &len, CASE);
	return (len);
}

void	ft_recursive_print_addr(long long unsigned int num, size_t *len)
{
	if (num < 10)
	{
		num += '0';
		*len += write(1, &num, 1);
	}
	else if (num < 16)
	{
		num += 'a' - 10;
		*len += write(1, &num, 1);
	}
	else
	{
		ft_recursive_print_addr(num / 16, len);
		ft_recursive_print_addr(num % 16, len);
	}
}

size_t	ft_print_addr(void *num)
{
	size_t	len;

	len = 0;
	len += write(1, "0x", 2);
	ft_recursive_print_addr((long long unsigned int) num, &len);
	return (len);
}
