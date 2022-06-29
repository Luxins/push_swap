/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljahn <ljahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:41:18 by ljahn             #+#    #+#             */
/*   Updated: 2022/05/09 11:41:19 by ljahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	callcenter(va_list	arg, char c)
{
	if (c == 'c')
		return (ft_printchar(arg));
	if (c == '%')
		return (write(1, "%", 1));
	if (c == 's')
		return (ft_printstr(va_arg(arg, char *)));
	if (c == 'p')
		return (ft_printptr(va_arg(arg, void *)));
	if (c == 'i' || c == 'd')
		return (ft_printnumb(va_arg(arg, int)));
	if (c == 'u')
		return (ft_printunumb(va_arg(arg, unsigned int)));
	if (c == 'x')
		return (ft_printhex(va_arg(arg, unsigned int), 0));
	if (c == 'X')
		return (ft_printhex(va_arg(arg, unsigned int), 1));
	return (0);
}

int	ft_printf(const char *base, ...)
{
	va_list	list;
	int		count;

	count = 0;
	va_start(list, base);
	while (*base)
	{
		if (*base == '%')
		{
			count += callcenter(list, *(base + 1));
			base += 2;
			continue ;
		}
		write(1, base, 1);
		count++;
		base++;
	}
	va_end(list);
	return (count);
}
