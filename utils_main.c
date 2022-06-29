/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljahn <ljahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:18:29 by ljahn             #+#    #+#             */
/*   Updated: 2022/06/28 21:50:27 by ljahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "costume.h"

void	initalization(t_args *r, int ac, char **av)
{
	r->a = init_link(ac, av);
}

void	print_both(t_link **a, t_link **b)
{
	t_link	*a_;
	t_link	*b_;

	a_ = *a;
	b_ = *b;
	while (a_ || b_)
	{
		if (a_)
		{
			ft_printf("%d", (a_)->rank);
			a_ = (a_)->next;
		}
		ft_putstr_fd("\t", 1);
		if (b_)
		{
			ft_printf("%d", (b_)->rank);
			b_ = (b_)->next;
		}
		ft_printf("\n");
	}
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("-----\n", 1);
}

// void	print_both_raw(t_link **a, t_link **b)
// {
// 	t_link	*a_;
// 	t_link	*b_;

// 	a_ = *a;
// 	b_ = *b;
// 	while (a_ || b_)
// 	{
// 		if (a_)
// 		{
// 			ft_printf("%d", (a_)->x);
// 			a_ = (a_)->next;
// 		}
// 		ft_putstr_fd("\t", 1);
// 		if (b_)
// 		{
// 			ft_printf("%d", (b_)->x);
// 			b_ = (b_)->next;
// 		}
// 		ft_printf("\n");
// 	}
// 	ft_putstr_fd("\n", 1);
// 	ft_putstr_fd("-----\n", 1);
// }

void	index_link(t_link **head)
{
	t_link	*first;
	t_link	*running;
	int		i;

	first = *head;
	i = 0;
	while (first)
	{
		first->rank = 0;
		running = *head;
		while (running)
		{
			if (running->x < first->x)
				first->rank++;
			running = running->next;
		}
		first = first->next;
	}
}
