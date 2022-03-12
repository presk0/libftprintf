/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:03:19 by supersko          #+#    #+#             */
/*   Updated: 2022/03/12 19:53:27 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINT_H
# define LIBFTPRINT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef union	u_byte {
   int		i;
   float	f;
   char 	*str;
}	t_byte;

int				ft_printf(const char *, ...);
unsigned int	ft_strlen_char(char const *s, char c);
int				ft_percents_count(char *str);
unsigned int	ft_strlen_char(char const *s, char c);
int				ft_print_arg(void *, char type);

#endif
