/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:03:19 by supersko          #+#    #+#             */
/*   Updated: 2022/03/15 17:40:20 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# include <stdio.h>
# include <string.h>

int		ft_printf(const char *str, ...);
size_t	ft_strlen_char(char const *s, char c);
size_t	ft_print_arg(va_list *ap, char *str);
size_t	ft_print_str(char *str);
size_t	ft_print_char(char c);
size_t	ft_print_int(long long int num, int base, char CASE);

#endif
