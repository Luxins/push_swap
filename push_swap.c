/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljahn <ljahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:13:36 by ljahn             #+#    #+#             */
/*   Updated: 2022/06/29 08:58:12 by ljahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "costume.h"

void	sw(t_link **s)
{
	t_link	*first;
	t_link	*second;
	t_link	*temp;

	ft_putstr_fd("sa\n", 1);
	if (*s && (*s)->next)
	{
		first = *s;
		second = first->next;
		temp = first;
		*s = second;
		first->next = second->next;
		second->next = temp;
	}
}

void	sb(t_link **s)
{
	t_link	*first;
	t_link	*second;
	t_link	*temp;

	ft_putstr_fd("sb\n", 1);
	if (*s && (*s)->next)
	{
		first = *s;
		second = first->next;
		temp = first;
		*s = second;
		first->next = second->next;
		second->next = temp;
	}
}

void	pa(t_link **a, t_link **b)
{
	t_link	*ahead;

	ft_putstr_fd("pa\n", 1);
	if (a && *b)
	{
		ahead = (*b)->next;
		(*b)->next = *a;
		*a = *b;
		*b = ahead;
	}
}

void	pb(t_link **a, t_link **b)
{
	t_link	*ahead;

	ft_putstr_fd("pb\n", 1);
	if (b && *a)
	{
		ahead = (*a)->next;
		(*a)->next = *b;
		*b = *a;
		*a = ahead;
	}
}

void	ru(t_link **head)
{
	t_link	*first;

	ft_putstr_fd("ra\n", 1);
	if (*head && (*head)->next)
	{
		first = *head;
		*head = first->next;
		first->next = NULL;
		ft_linkadd_back(head, first);
	}
}
