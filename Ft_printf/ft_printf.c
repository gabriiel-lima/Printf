/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garodri2 <garodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 09:59:26 by garodri2          #+#    #+#             */
/*   Updated: 2026/05/20 12:16:29 by garodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_arg(const char caracter, va_list argument)
{
	int	count;

	count = 0;
	if (caracter == 'c')
		return (count += ft_putchar(va_arg(argument, int)));
	else if (caracter == 's')
		return (count += ft_putstr(va_arg(argument, char *)));
	else if (caracter == 'd' || caracter == 'i')
		return (count += ft_putnbr(va_arg(argument, int)));
	else if (caracter == 'u')
		return (count += ft_putnbr_unsgnd(va_arg(argument, unsigned int)));
	else if (caracter == 'x')
		return (count += ft_puthex(va_arg(argument, unsigned int), caracter));
	else if (caracter == 'X')
		return (count += ft_puthex(va_arg(argument, unsigned int), caracter));
	else if (caracter == 'p')
		return (count += ft_putpointer(va_arg(argument, void *)));
	else if (caracter == '%')
		return (count += ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	arg;

	count = 0;
	i = 0;
	va_start(arg, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			count += check_arg(format[i], arg);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (count);
}
