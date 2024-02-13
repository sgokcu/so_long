/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgokcu <sgokcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:34:54 by sgokcu            #+#    #+#             */
/*   Updated: 2024/02/12 16:49:53 by sgokcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *s, ...);
int		ft_check(char c, va_list arg);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(long d);
int		ft_hexadecimal(unsigned long a, char *s);
void	ft_begin(const char *s, va_list arg, int *check);

#endif
