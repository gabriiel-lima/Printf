/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garodri2 <garodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 12:02:25 by garodri2          #+#    #+#             */
/*   Updated: 2026/05/20 12:17:49 by garodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	int	count;

	count = 0;
	if (nbr == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	if (nbr < 0)
	{
		count += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr > 9)
		count += ft_putnbr(nbr / 10);
	count += ft_putchar((nbr % 10) + '0');
	return (count);
}

int	ft_putnbr_unsgnd(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr > 9)
		count += ft_putnbr(nbr / 10);
	count += ft_putchar((nbr % 10) + '0');
	return (count);
}

int	ft_puthex(unsigned int nbr, const char c)
{
	int	count;

	count = 0;
	if (nbr > 15)
		count += ft_puthex(nbr / 16, c);
	if (c == 'x')
		count += ft_putchar("0123456789abcdef"[nbr % 16]);
	else
		count += ft_putchar("0123456789ABCDEF"[nbr % 16]);
	return (count);
}
