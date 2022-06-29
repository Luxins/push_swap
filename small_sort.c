/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljahn <ljahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 08:16:08 by ljahn             #+#    #+#             */
/*   Updated: 2022/06/29 08:58:23 by ljahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "costume.h"

void	rd(t_link **head)
{
	t_link	*last;
	t_link	*drag;

	ft_putstr_fd("rra\n", 1);
	if (*head && (*head)->next)
	{
		last = *head;
		while (last->next)
		{
			drag = last;
			last = last->next;
		}
		drag->next = NULL;
		last->next = *head;
		*head = last;
	}
}

void	converter(t_link **a, int inv)
{
	int		i;
	t_link	*run;

	i = 0;
	run = *a;
	if (!inv)
	{
		while (i < 3)
		{
			run->rank -= 2;
			run = run->next;
			i++;
		}
	}
	else
	{
		while (i < 3)
		{
			run->rank += 2;
			run = run->next;
			i++;
		}
	}
}

void	fiver_sort(t_link **a, t_link **b)
{
	int		i;
	int		pushed;

	pushed = 0;
	i = 0;
	while (i < 5 && pushed <= 2)
	{
		if ((*a)->rank < 2)
		{
			pushed++;
			pb(a, b);
		}
		else
			ru(a);
		i++;
	}
	converter(a, 0);
	three_sort(a, b);
	converter(a, 1);
	if ((*b)->rank == 0)
		sb(b);
	while (*b)
		pa(a, b);
}

void	three_sort(t_link **a, t_link **b)
{
	t_link	*ahead;

	ahead = (*a)->next;
	if ((*a)->rank == 2)
	{
		ru(a);
		if ((*a)->rank == 1)
			sw(a);
	}
	else if ((*a)->rank == 1)
	{
		if (ahead->rank == 0)
			sw(a);
		else if (ahead->rank == 2)
			rd(a);
	}
	else if (ahead->rank == 2)
	{
		ru(a);
		sw(a);
		rd(a);
	}
}
