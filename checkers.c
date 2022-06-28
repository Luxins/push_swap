/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljahn <ljahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:30:33 by ljahn             #+#    #+#             */
/*   Updated: 2022/06/28 10:13:15 by ljahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "costume.h"

int	duplicates(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (!ft_strncmp(av[i], av[j], 11))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	out_of_range(char *num)
{
	if (ft_strlen(num) > 11)
		return (1);
	if (ft_strlen(num) == 11)
	{
		if (ft_strncmp(num, "-2147483648", 11) > 0)
			return (1);
	}
	if (ft_strlen(num) == 10)
	{
		if (ft_strncmp(num, "2147483647", 10) > 0)
			return (1);
	}
	return (0);
}

void	check_for_duplicates(char **av)
{
	if (duplicates(av))
	{
		ft_putstr_fd("Error: Duplicates\n", 1);
		exit(-1);
	}
}

void	check_out_of_range(char **av, int i)
{
	if (out_of_range(av[i]))
	{
		ft_putstr_fd("Error: Out of int range\n", 1);
		exit(-1);
	}
}

void	check_not_numeric(char **av, int i, int j)
{
	if (!ft_isdigit(av[i][j]))
	{
		ft_putstr_fd("Error: Not numeric\n", 1);
		exit(-1);
	}
}
