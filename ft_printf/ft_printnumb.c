/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljahn <ljahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:40:49 by ljahn             #+#    #+#             */
/*   Updated: 2022/05/09 11:40:50 by ljahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnumb(int x)
{
	int		count;
	int		digit;

	count = 0;
	if (x < 0)
	{
		if (x == -2147483648)
			return (write(1, "-2147483648", 11));
		count += write(1, "-", 1);
		x *= -1;
	}
	digit = 0;
	if (x >= 10)
		count += ft_printnumb(x / 10);
	digit = x % 10;
	count += write(1, &"0123456789"[digit], 1);
	return (count);
}

int	ft_printunumb(unsigned int x)
{
	int		count;
	int		digit;

	count = 0;
	digit = 0;
	if (x >= 10)
		count += ft_printunumb(x / 10);
	digit = x % 10;
	count += write(1, &"0123456789"[digit], 1);
	return (count);
}
