/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:03:19 by supersko          #+#    #+#             */
/*   Updated: 2022/03/15 12:55:18 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINT_H
# define LIBFTPRINT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# include <stdio.h>
# include <string.h>

int		ft_printf(const char *, ...);
size_t	ft_strlen_char(char const *s, char c);
size_t	ft_print_arg(va_list *, char *);
size_t	ft_print_str(char *);
size_t	ft_print_char(char);
size_t	ft_print_int(long long int);

#endif
