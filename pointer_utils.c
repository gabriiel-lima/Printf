/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garodri2 <garodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 12:02:31 by garodri2          #+#    #+#             */
/*   Updated: 2026/05/20 12:17:39 by garodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_ptr(unsigned long nbr)
{
	int	count;

	count = 0;
	if (nbr > 15)
		count += ft_puthex_ptr(nbr / 16);
	count += ft_putchar("0123456789abcdef"[nbr % 16]);
	return (count);
}

int	ft_putpointer(void *ptr)
{
	int				count;
	unsigned long	nbr;

	count = 0;
	nbr = (unsigned long)ptr;
	if (!ptr)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_puthex_ptr(nbr);
	return (count);
}
