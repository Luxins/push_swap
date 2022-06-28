/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljahn <ljahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 08:58:48 by ljahn             #+#    #+#             */
/*   Updated: 2022/06/28 10:15:54 by ljahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "costume.h"

static int	strstrlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

static void	free_all(char **splitters)
{
	int	i;

	i = 0;
	while (splitters[i])
	{
		free(splitters[i]);
		i++;
	}
	free(splitters);
}

t_link	**assign_splitters(char *av, int *split_num)
{
	t_link	**head;
	char	**splitters;
	int		i;
	int		iteri;

	i = 0;
	splitters = ft_split(av, ' ');
	iteri = strstrlen(splitters);
	arg_validation(iteri, splitters);
	head = malloc(sizeof(t_link *));
	while (i < iteri)
	{
		if (i == 0)
			*head = new_link(atoi(splitters[i]));
		else
			ft_linkadd_back(head, new_link(atoi(splitters[i])));
		i++;
	}
	free_all(splitters);
	*split_num = iteri;
	return (head);
}

int	contains(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_linkclear(t_link	**lst)
{
	t_link	*element;
	t_link	*element2;

	element = *lst;
	while (element)
	{
		element2 = element->next;
		free(element);
		element = element2;
	}
	*lst = NULL;
}
