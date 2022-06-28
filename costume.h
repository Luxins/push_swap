/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costume.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljahn <ljahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 08:52:37 by ljahn             #+#    #+#             */
/*   Updated: 2022/06/28 21:07:49 by ljahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COSTUME_H
# define COSTUME_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_link
{
	int		x;
	void	*next;
	int		rank;
}	t_link;

typedef struct s_min
{
	int		min;
	t_link	holder;
}	t_min;

typedef struct s_args
{
	int		shell;
	int		split_num;
	t_link	*a;
	t_link	*b;
}	t_args;

//			validation.c
void	validation(int ac, char **av);
void	arg_validation(int ac, char **av);

//			checkers.c
void	check_for_duplicates(char **av);
void	check_out_of_range(char **av, int i);
void	check_not_numeric(char **av, int i, int j);

//			freeing.c
t_link	**assign_splitters(char *av, int *split_num);
int		contains(char *str, char c);
void	ft_linkclear(t_link	**lst);

//			sort.c
void	binary_sort(t_link **a, t_link **b, int argc);

//			init_link.c
t_link	*init_link(int ac, char **av);
void	ft_linkadd_back(t_link **head, t_link *new);
void	ft_linkadd_front(t_link **link, t_link *new);
t_link	*new_link(int data);

//			utils_main.c
void	print_both(t_link **a, t_link **b);
void	print_both_raw(t_link **a, t_link **b);
void	initalization(t_args *r, int ac, char **av);
void	index_link(t_link **head);

//			push_swap.c
void	sw(t_link **s);
void	ss(t_link **a, t_link **b);
void	pb(t_link **a, t_link **b);
void	pa(t_link **a, t_link **b);
void	rd(t_link **head);
void	ru(t_link **head);
void	rbd(t_link **a, t_link **b);
void	rbu(t_link **a, t_link **b);

#endif