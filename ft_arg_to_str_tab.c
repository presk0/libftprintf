/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_to_str_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:36:18 by supersko          #+#    #+#             */
/*   Updated: 2022/03/13 15:20:27 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
//https://fr.wikiversity.org/wiki/C_pointeurs/Tableau_de_pointeurs_de_fonctions

static char	*ft_arg_to_str(va_list ap, char type)
{
	if (type == 'c')
		return (ft_char_to_str(va_arg(ap, char));
}

char		*ft_char_to_str(char c)
{
	char	*str;

	str = malloc(2);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

char		**ft_arg_to_str_tab(va_list ap, char *tab_type)
{
	int		nb_args;
	int 	ii;
	char	**ret;

	nb_args = ft_strlen_char(tab_type, '\0');
	ret = (char **) malloc((nb_args + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	while (*tab_type)
	{
		ret[ii++] = ft_arg_to_str(ap, *tab_type++);
	}
	return (ret);
}
