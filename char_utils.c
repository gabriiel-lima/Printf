/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garodri2 <garodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 12:01:57 by garodri2          #+#    #+#             */
/*   Updated: 2026/05/20 12:17:46 by garodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char str)
{
	write(1, &str, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i] != '\0')
	{
		count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}
