/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percents_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:14:43 by supersko          #+#    #+#             */
/*   Updated: 2022/03/12 21:09:30 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_percent_counter(char *str)
{
	int count;

	if (!str)
		return (0);
	count = 0;
	while (*str++)
	{
		if (*str == '%')
			count++;
	}
	return (count);
}

/*
//
# include <stdio.h>
# include <string.h>
// MAIN
int main(void)
{
	char str[100];

	strcpy(str, "");
	printf("[%3d] => [%s]\n", ft_percents_count(str), str);

	strcpy(str, "% %");
	printf("[%3d] => [%s]\n", ft_percents_count(str), str);

	strcpy(str, " % ");
	printf("[%3d] => [%s]\n", ft_percents_count(str), str);

	strcpy(str, "\\% %d");
	printf("[%3d] => [%s]\n", ft_percents_count(str), str);
}
*/
