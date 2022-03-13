/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:01:29 by supersko          #+#    #+#             */
/*   Updated: 2022/03/13 14:42:10 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_get_type_tab(char *str)
{
	size_t	size_tab;
	char	*tab_type;
	char	*addr_tab_type;

	if (str)
	{
		size_tab = ft_percent_counter(str);
		tab_type = (char *) malloc(++size_tab * sizeof(char));
		addr_tab_type = tab_type;
		while (*str)
		{
			if (*str++ == '%')
				*tab_type++ = *str;
		}
	}
	*tab_type = '\0';
	return (addr_tab_type);
}
/*
//
// MAIN
int	main(void)
{
	printf("%s\n", ft_get_type_tab("%c dfg %g\n"));
	printf("%s\n", ft_get_type_tab(""));
	printf("%s\n", ft_get_type_tab("%"));
}
*/
