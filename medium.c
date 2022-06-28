/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljahn <ljahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:11:13 by ljahn             #+#    #+#             */
/*   Updated: 2022/06/28 21:06:03 by ljahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "costume.h"

void	allready_sorted(t_link **a)
{
	t_link	*elem;
	t_link	*ahead;

	elem = *a;
	if (elem)
	{
		while (elem->next)
		{
			ahead = elem->next;
			if (!(elem->x < ahead->x))
				return ;
			elem = ahead;
		}
	}
	ft_linkclear(a);
	exit (0);
}

void	shell_or_norm(int ac, char **av, t_args *r)
{
	t_link	**to_free;

	if (ac == 2 && contains(av[1], ' '))
	{
		to_free = assign_splitters(av[1], &r->split_num);
		r->a = *to_free;
		free(to_free);
		allready_sorted(&r->a);
		r->shell = 1;
	}
	else
	{
		validation(ac, av);
		initalization(r, ac, av);
		allready_sorted(&r->a);
		r->shell = 0;
	}
}

int	main(int ac, char **av)
{
	t_args	r;

	shell_or_norm(ac, av, &r);
	r.b = NULL;
	index_link(&r.a);
	if (!r.shell)
		binary_sort(&r.a, &r.b, ac - 1);
	else
		binary_sort(&r.a, &r.b, r.split_num);
	ft_linkclear(&r.a);
	ft_linkclear(&r.b);
	return (0);
}
