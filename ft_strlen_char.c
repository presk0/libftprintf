/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:39:36 by supersko          #+#    #+#             */
/*   Updated: 2022/03/14 19:05:11 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlen_char(char const *s, char c)
{
	unsigned int	ii;

	ii = 0;
	while (s[ii] && s[ii] != c)
		ii++;
	return (ii);
}
