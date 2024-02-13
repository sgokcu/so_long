/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgokcu <sgokcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:18:56 by sgokcu            #+#    #+#             */
/*   Updated: 2024/02/12 14:25:40 by sgokcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		check;
	va_list	arg;

	check = 0;
	va_start(arg, s);
	ft_begin(s, arg, &check);
	va_end(arg);
	return (check);
}

void	ft_begin(const char *s, va_list arg, int *check)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '%')
		{
			ft_putchar(s[i]);
			(*check)++;
		}
		if (s[i] == '%')
		{
			i++;
			if (s[i] == ' ')
				(*check) += ft_putchar(' ');
			while (s[i] == ' ' && s[i])
				i++;
			(*check) += ft_check(s[i], arg);
		}
		i++;
	}
}

int	ft_check(char c, va_list arg)
{
	int	p;

	p = 0;
	if (c == 'c')
		p += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		p += ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		p += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		p += ft_putnbr(va_arg(arg, unsigned int));
	else if (c == 'x')
		p += ft_hexadecimal(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		p += ft_hexadecimal(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		p += ft_putchar('%');
	else if (c == 'p')
	{
		p += write(1, "0x", 2);
		p += ft_hexadecimal(va_arg(arg, unsigned long), "0123456789abcdef");
	}
	else
		return (ft_putchar(c));
	return (p);
}
