/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstopfer <dstopfer@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:09:49 by dstopfer          #+#    #+#             */
/*   Updated: 2022/04/09 18:51:06 by dstopfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
int		cases(va_list list, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr(int n);
void	put_unsigned(unsigned int n);
int		nbr_len(long n);
int		con_c(va_list args);
int		con_s(va_list args);
int		con_i(va_list args);
int		con_u(va_list args);
int		con_x(va_list args);
int		con_ux(va_list args);
int		conv_p(va_list args);
void	hexa_nbr(unsigned long n, char *str);
int		hexa_len(unsigned long nbr);

#endif