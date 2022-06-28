/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljahn <ljahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:30:10 by ljahn             #+#    #+#             */
/*   Updated: 2022/06/28 10:19:38 by ljahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "costume.h"

void	validation(int ac, char **av)
{
	int	i;
	int	j;

	if (ac == 1)
		exit(0);
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (j == 0 && av[i][j] == '-' && ft_isdigit(av[i][j + 1]))
			{
				j++;
				continue ;
			}
			check_not_numeric(av, i, j);
			j++;
		}
		check_out_of_range(av, i);
		i++;
	}
	check_for_duplicates(av + 1);
}

void	arg_validation(int ac, char **av)
{
	int	i;
	int	j;

	if (ac == 1)
		exit(0);
	i = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (j == 0 && av[i][j] == '-' && ft_isdigit(av[i][j + 1]))
			{
				j++;
				continue ;
			}
			check_not_numeric(av, i, j);
			j++;
		}
		check_out_of_range(av, i);
		i++;
	}
	check_for_duplicates(av);
}
