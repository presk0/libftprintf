/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:54:42 by supersko          #+#    #+#             */
/*   Updated: 2022/03/14 19:51:21 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t				ft_print_str(char *str)
{
	size_t	len_str;

	len_str = ft_strlen_char(str, '\0');
	write(1, str, len_str);
	return (len_str);
}

size_t ft_print_char(char c)
{
		return (write(1 , &c, 1));
}
