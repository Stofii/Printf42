/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstopfer <dstopfer@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:17:09 by dstopfer          #+#    #+#             */
/*   Updated: 2022/04/09 18:30:34 by dstopfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cases(va_list list, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += con_c(list);
	else if (c == 's')
		len += con_s(list);
	else if (c == 'p')
		len += con_p(list);
	else if (c == 'd' || c == 'i')
		len += con_i(list);
	else if (c == 'u')
		len += con_u(list);
	else if (c == 'x')
		len += con_x(list);
	else if (c == 'X')
		len += con_ux(list);
	else if (c == '%')
		len += write(1, "%", 1);
	else
		len += write(1, &c, 1);
	return (len);
}
