/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstopfer <dstopfer@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:39:21 by dstopfer          #+#    #+#             */
/*   Updated: 2022/04/09 18:51:01 by dstopfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	con_c(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	ft_putchar_fd(c, 1);
	return (1);
}

int	con_s(va_list args)
{
	int		len;
	char	*str;

	str = va_arg(args, char *);
	len = 0;
	if (str == NULL)
	{
		write(1, "NULL", 4);
		return (4);
	}
	while (str[len] != '\0')
	{
		write (1, &str[len], 1);
		len++;
	}
	return (len);
}

int	con_i(va_list args)
{
	int	i;
	int	len;

	i = va_arg(args, int);
	len = nbr_len(i);
	ft_putnbr(i);
	return (len);
}

int	con_u(va_list args)
{
	unsigned int	i;
	int				len;

	i = va_arg(args, unsigned int);
	len = nbr_len(i);
	put_unsigned(i);
	return (len);
}
