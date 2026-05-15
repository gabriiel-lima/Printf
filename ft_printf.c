/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garodri2 <garodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 09:59:26 by garodri2          #+#    #+#             */
/*   Updated: 2026/05/15 16:39:02 by garodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void	ft_putchar(char str)
{
	write(1, &str, 1);
}

void	ft_printf(const char *format, ...)
{
	int	i;

	i = 0;
	va_list arg;
	va_start(arg, format);

	while(format[i] != '\0')
	{
		if(format[i] == '%')
		{
			i ++;
			if(format[i] == 'c')
			{
				char x = va_arg(arg, int);
				ft_putchar(x); 
				i ++;
			}
		}
		ft_putchar(format[i]);
		i ++;
	}
	
	va_end(arg);
}

int main(void)
{
	// char *c = "bao?";
	// ft_putstr("VAI CORINTHIANS");
	// printf("\nTudo %s Aoba\n", c);
	ft_printf("%c ola", 'm');
	return (0);
}