/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljahn <ljahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:41:07 by ljahn             #+#    #+#             */
/*   Updated: 2022/05/09 11:41:08 by ljahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned long x, int uppercase)
{
	int	count;
	int	digit;

	count = 0;
	digit = 0;
	if (x >= 16)
		count += ft_printhex(x / 16, uppercase);
	digit = x % 16;
	if (uppercase)
		return (count += write(1, &"0123456789ABCDEF"[digit], 1));
	return (count += write(1, &"0123456789abcdef"[digit], 1));
}

int	ft_printptr(void *ptr)
{
	if (!ptr)
	{
		write(1, "0x0", 3);
		return (3);
	}
	else
		write(1, "0x", 2);
	return (ft_printhex((unsigned long) ptr, 0) + 2);
}

// int main(void)
// {
// 	printhex(4294967295, 1);
// }