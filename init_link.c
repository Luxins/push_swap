/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljahn <ljahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 08:59:49 by ljahn             #+#    #+#             */
/*   Updated: 2022/06/28 08:59:50 by ljahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "costume.h"

t_link	*new_link(int data)
{
	t_link	*new_link;

	new_link = malloc(sizeof(t_link));
	new_link->next = NULL;
	new_link->x = data;
	return (new_link);
}

void	ft_linkadd_back(t_link **head, t_link *new)
{
	t_link	*moving_head;

	moving_head = *head;
	if (!*head)
		*head = new;
	else
	{
		while (moving_head->next != NULL)
			moving_head = moving_head->next;
		moving_head->next = new;
	}
}

void	ft_linkadd_front(t_link **link, t_link *new)
{
	if (link && new)
	{
		new->next = *link;
		*link = new;
	}
}

t_link	*init_link(int ac, char **av)
{
	int		i;
	t_link	*head;

	head = new_link(ft_atoi(av[1]));
	i = 2;
	while (i < ac)
	{
		ft_linkadd_back(&head, new_link(ft_atoi(av[i])));
		i++;
	}
	return (head);
}
