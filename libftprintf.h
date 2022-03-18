/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:03:19 by supersko          #+#    #+#             */
/*   Updated: 2022/03/18 19:42:47 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# include <stdio.h>
# include <string.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
size_t	ft_strlen_char(char const *s, char c);
size_t	ft_print_arg(va_list *ap, char *str);
size_t	ft_print_str(char *str);
size_t	ft_print_char(char c);
size_t	ft_print_int(int num);
size_t	ft_print_unsigned(unsigned int num);
size_t	ft_print_hexa(long long unsigned int num, char CASE);
size_t	ft_print_addr(void *num);

#endif
