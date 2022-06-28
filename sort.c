/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljahn <ljahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:16:58 by ljahn             #+#    #+#             */
/*   Updated: 2022/06/28 09:16:59 by ljahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "costume.h"

int	figurino(int num)
{
	int	res;

	if (num == 0)
		return (0);
	res = 0;
	while (num)
	{
		res++;
		num /= 2;
	}
	return (res);
}

void	binary_sort(t_link **a, t_link **b, int argc)
{
	int		figi;
	int		i;
	int		remain;

	figi = figurino(argc);
	i = 0;
	while (i < figi)
	{
		remain = argc;
		while (remain)
		{
			if (((*a)->rank >> i) & 1)
				ru(a);
			else
				pb(a, b);
			remain--;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
