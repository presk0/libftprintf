/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:51:11 by supersko          #+#    #+#             */
/*   Updated: 2022/03/13 18:53:53 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memcpy(void *dst, const void *src, unsigned int len)
{
	unsigned int	ii;

	ii = 0;
	if (len == 0 || dst == src)
		return (dst);
	while (ii < len)
	{
		((char *) dst)[ii] = ((char *) src)[ii];
		ii++;
	}
	return (dst);
}

/*
//
#include <string.h>
#include <stdio.h>
// MAIN
int test_memcpy(char *to_cpy, int len)
{
	char	s1[1000];
	char	s2[1000];
	int		ii = 0;

	memcpy(s1, to_cpy, len);
	ft_memcpy(s2, to_cpy, len);
	while (ii < len)
	{
		if (s1[ii] != s2[ii])
		{
			printf("differents output for str=[%s]\nmemcpy(str) = [%s]\n\
			ft_memcpy(str) = [%s]\nlen = %d\n"\
			, to_cpy, s1, s2, len);
			printf("\n");
			printf("\n");
			return (1);
		}
		ii++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int ii = 0;

	while (ii < 5)
	{
		char str[ii];
		strcpy(str, "abc\n");
		test_memcpy(str, ii);
		ii++;
	}
	ii = 0;
	while (ii < 5)
	{
		char str[ii];
		strcpy(str, "");
		test_memcpy(str, ii);
		ii++;
	}
}
*/