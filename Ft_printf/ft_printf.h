/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garodri2 <garodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 11:44:27 by garodri2          #+#    #+#             */
/*   Updated: 2026/05/20 11:56:30 by garodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

//prototipos
int		ft_putchar(char str);
int		ft_putstr(char *str);
int		ft_putnbr(int nbr);
int		ft_putpointer(void *ptr);
int		ft_putnbr_unsgnd(unsigned int nbr);
int		ft_puthex(unsigned int nbr, char c);
int		ft_printf(const char *format, ...);

#endif