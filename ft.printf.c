/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstopfer <dstopfer@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:44:11 by dstopfer          #+#    #+#             */
/*   Updated: 2022/04/09 18:33:08 by dstopfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	va;
	int		len;
	int		i;

	va_start(va, str);
	len = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			i++;
			len += cases(str[i], va);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			len++;
		}
		i++;
	}
	va_end(va);
	return (len);
}
