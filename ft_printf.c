/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garodri2 <garodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 09:59:26 by garodri2          #+#    #+#             */
/*   Updated: 2026/05/19 16:42:18 by garodri2         ###   ########.fr       */
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

void	ft_putstr(char *str)
{
	int 	i;

	i = 0;
	while(str[i] != '\0')
	{
		ft_putchar(str[i]);
		i ++;		
	}	
}

void	ft_putnbr(int nbr)
{
	if(nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if(nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if(nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar((nbr % 10) + '0');
}

void	ft_putnbr_unsgnd(int nbr)
{
	if(nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar((nbr % 10) + '0');
}

void	ft_puthex(unsigned int nbr, const char c)
{
	if(nbr >= 15)
		ft_puthex(nbr / 16, c);
	if(c == 'x')
		ft_putchar("0123456789abcdef"[nbr % 16]);
	else
		ft_putchar("0123456789ABCDEF"[nbr % 16]);
}

void ft_puthex_ptr(unsigned long nbr)
{
	if(nbr > 15)
		ft_puthex_ptr(nbr / 16);	
	ft_putchar("0123456789abcdef"[nbr % 16]);
}
void	ft_putpointer(void *ptr)
{
	unsigned long nbr;
	
	nbr = (unsigned long)ptr;  
	if(!ptr)
		return ft_putstr("(nil)");
	ft_putstr("0x");
	ft_puthex_ptr(nbr);
}

void	check_arg(const char caracter, va_list argument)
{
	
	if(caracter == 'c')
		ft_putchar(va_arg(argument, int));
	else if(caracter == 's')
		ft_putstr(va_arg(argument, char*));
	else if(caracter == 'd' || caracter == 'i')
		ft_putnbr(va_arg(argument, int));
	else if(caracter == 'u')
		ft_putnbr_unsgnd(va_arg(argument, unsigned int));
	else if(caracter == 'x')
		ft_puthex(va_arg(argument, unsigned int), caracter);
	else if(caracter == 'X')
		ft_puthex(va_arg(argument, unsigned int), caracter);
	else if(caracter == 'p')
		ft_putpointer(va_arg(argument, void *));
	else if(caracter == '%')
	{
		ft_putchar('%');
	}
}

int	ft_printf(const char *format, ...)
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
			// if(format[i] == 'c')
			// {
			// 	char x = va_arg(arg, int);
			// 	ft_putchar(x); 
			// 	i ++;
			// }
			check_arg(format[i], arg);
			i ++;
		}
		ft_putchar(format[i]);
		i ++;
	}
	va_end(arg);
	return i;
}

int main(void)
{
	// char *c = "bao?";
	// ft_putstr("VAI CORINTHIANS");
	// printf("\nTudo %s Aoba\n", c);
	// printf("%d", printf("%s", c));
	int t = ft_printf("ola");
	ft_printf("%d", t);
	// printf("%p", c);
	
	return (0);
}