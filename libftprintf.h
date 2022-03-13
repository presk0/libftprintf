/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:03:19 by supersko          #+#    #+#             */
/*   Updated: 2022/03/13 19:02:13 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINT_H
# define LIBFTPRINT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# include <stdio.h>
# include <string.h>

int				ft_printf(const char *, ...);
unsigned int	ft_strlen_char(char const *s, char c);
int				ft_percents_counter(char *str);
size_t			ft_print_str(char *);
int				ft_percent_counter(char *);
char			*ft_get_type_tab(char *);
char			**ft_arg_to_str_tab(va_list, char *);
char			*ft_itoa(int n);
size_t			ft_strlcpy(char *dst, const char *src, size_t maxlen);
void			*ft_memcpy(void *dst, const void *src, unsigned int len);
size_t			ft_strlen(const char *str);

#endif
