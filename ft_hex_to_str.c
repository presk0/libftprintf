/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:09:21 by supersko          #+#    #+#             */
/*   Updated: 2022/03/14 14:27:44 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	ft_hex_to_minchar(long int n)
{
	if (n < 10 && n >= 0)
		return (n + (int) '0');
	else if (n < 16)
		return (n - 10 + (int) 'a');
	else
		return ('g');
}

char	ft_hex_to_majchar(long int n)
{
	if (n < 10 && n >= 0)
		return (n + (int) '0');
	else if (n < 16)
		return (n - 10 + (int) 'A');
	else
		return ('G');
}

void	ft_recursive_hex_to_str(long int addr, char *hex, int counter)
{
	if (counter--)
	{
		ft_recursive_hex_to_str((long int)addr / 16, hex, counter);
		hex[2 + counter] = ft_hex_to_minchar((long int) addr % 16);
	}
}

char	*ft_hex_to_str(void *i)
{
	char	*hex;

	hex = malloc(sizeof(char) * 15);
	hex[0] = '0';
	hex[1] = 'x';
	hex[14] = '\0';
	ft_recursive_hex_to_str((long int)i, hex, 12);
	return (hex);
}

/*
// MAIN
int	main(void)
{
	int *i;

	i = malloc(1);
	printf("%s\n", ft_hex_to_str(0));
	printf("%p\n", 0);
}
*/
