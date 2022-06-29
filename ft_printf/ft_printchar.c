/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljahn <ljahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:41:22 by ljahn             #+#    #+#             */
/*   Updated: 2022/05/09 11:41:23 by ljahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(va_list arg)
{
	char	c;
	int		count;

	c = (char)va_arg(arg, int);
	count = write(1, &c, 1);
	return (count);
}
