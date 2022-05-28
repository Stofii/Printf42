/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstopfer <dstopfer@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:26:12 by dstopfer          #+#    #+#             */
/*   Updated: 2022/04/09 18:48:57 by dstopfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr(int n)
{
	long	len;

	len = n;
	if (len < 0)
	{
		ft_putchar_fd('-', 1);
		len *= -1;
	}
	if (len <= 9)
		ft_putchar_fd(len + '0', 1);
	else
	{
		ft_putnbr(len / 10);
		ft_putnbr(len % 10);
	}
}

int	nbr_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

void	put_unsigned(unsigned int n)
{
	if (n >= 10)
	{
		put_unsigned(n / 10);
		put_unsigned(n % 10);
	}
	else
	{
		ft_putchar_fd(n + '0', 1);
	}
}
