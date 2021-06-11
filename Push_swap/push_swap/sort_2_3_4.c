/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_3_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 10:46:07 by lhayward          #+#    #+#             */
/*   Updated: 2021/04/06 10:49:44 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	for_2(int *mas)
{
	if (mas[0] > mas[1])
		left_shift_a(&mas, 2, 0);
	exit(1);
}

static void	for_3(int **stack_a, int len)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if ((*stack_a)[2] < (*stack_a)[1])
			shift_to_the_right_a(&(*stack_a), 3, 0);
		else if ((*stack_a)[0] > (*stack_a)[2] && \
				(*stack_a)[0] > (*stack_a)[1])
			left_shift_a(&(*stack_a), 3, 0);
		else if ((*stack_a)[0] > (*stack_a)[1])
			s_a(&(*stack_a), len);
	}
	exit(1);
}

static void	for_4(t_all *all)
{
	int	j;

	j = 0;
	all->flagi.tmp = 0;
	while (++j < all->stack.len_a)
		if (all->stack.st_a[all->flagi.tmp] >= all->stack.st_a[j])
			all->flagi.tmp = j;
	while (--all->flagi.tmp >= 0)
		left_shift_a(&all->stack.st_a, all->stack.len_a, 0);
	p_b(&all->stack.st_b, &all->stack.st_a, \
			&all->stack.len_b, &all->stack.len_a);
	for_trex(&all->stack.st_a, all->stack.len_a);
	p_a(&all->stack.st_a, &all->stack.st_b, \
		   	&all->stack.len_a, &all->stack.len_b);
	exit(1);
}

void	w234(t_all *all, int len)
{
	if (len == 1)
		exit(1);
	else if (len == 2)
		for_2(all->stack.st_a);
	else if (len == 3)
		for_3(&all->stack.st_a, 3);
	else if (len == 4)
		for_4(all);
}
