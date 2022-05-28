/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstopfer <dstopfer@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:51:09 by dstopfer          #+#    #+#             */
/*   Updated: 2022/05/24 23:11:05 by dstopfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_p(va_list args)
{
	void	*ptr;
	int		len;

	ptr = va_arg(args, void *);
	if (!ptr)
	{
		write(1, "0x0", 3);
		len = 3;
		return (len);
	}
	else
	len = hexa_len((unsigned long)ptr) + 2;
	write(1, "0x", 2);
	hexa_nbr((unsigned long)ptr, "0123456789abcdef");
	return (len);
}

int	con_x(va_list args)
{
	int				len;
	unsigned int	nbr;

	nbr = va_arg(args, int);
	len = hexa_len(nbr);
	hexa_nbr((unsigned long)nbr, "0123456789adcdef");
	return (len);
}

int	con_ux(va_list args)
{
	int				len;
	unsigned int	nbr;

	nbr = va_arg(args, int);
	len = hexa_len(nbr);
	hexa_nbr((unsigned long)nbr, "0123456789ABCDEF");
}

int	hexa_len(unsigned long nbr)
{
	int	len;

	len = 1;
	while (nbr / 16)
	{
		nbr = nbr / 16;
		len++;
	}
	return (len);
}

void	hexa_nbr(unsigned long n, char *str)
{
	int	base;
	int	i;

	base = 16;
	if (n / base != 0)
		hexa_nbr((n / base), str);
	i = n % base;
	write(1, &str[i], 1);
}
