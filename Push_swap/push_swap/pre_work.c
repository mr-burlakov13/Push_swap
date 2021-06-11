/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_work.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:57:04 by lhayward          #+#    #+#             */
/*   Updated: 2021/04/06 12:04:08 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_for_five(t_all *all)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 2)
	{
		j = 0;
		all->flagi.tmp = 0;
		while (++j < all->stack.len_a)
			if (all->stack.st_a[all->flagi.tmp] >= all->stack.st_a[j])
				all->flagi.tmp = j;
		while (--all->flagi.tmp >= 0)
			left_shift_a(&all->stack.st_a, all->stack.len_a, 0);
		p_b(&all->stack.st_b, &all->stack.st_a, \
				&all->stack.len_b, &all->stack.len_a);
	}
	for_trex(&all->stack.st_a, all->stack.len_a);
	p_a(&all->stack.st_a, &all->stack.st_b, \
			&all->stack.len_a, &all->stack.len_b);
	p_a(&all->stack.st_a, &all->stack.st_b, \
			&all->stack.len_a, &all->stack.len_b);
}

void	perebros(t_all *all)
{
	int	len;
	int	i;
	int	j;

	len = all->stack.len_a - 5;
	i = -1;
	j = -1;
	if (all->flagi.flag == 1)
	{
		while (++i < all->flagi.count)
			p_b(&all->stack.st_b, &all->stack.st_a, \
					&all->stack.len_b, &all->stack.len_a);
		while (++j < 5)
			left_shift_a(&all->stack.st_a, all->stack.len_a, 0);
		while (len-- - i)
			p_b(&all->stack.st_b, &all->stack.st_a, \
					&all->stack.len_b, &all->stack.len_a);
	}
	else
	{
		while (len--)
			p_b(&all->stack.st_b, &all->stack.st_a, \
					&all->stack.len_b, &all->stack.len_a);
	}
}

void	poryadok(t_all *all)
{
	int	i;

	i = 0;
	while (++i < all->stack.len_a)
	{
		if (all->stack.st_a[i] > all->stack.st_a[i - 1])
			all->flagi.count++;
		else
			all->flagi.count = 0;
		if (all->flagi.count == 4)
		{
			all->flagi.count = i - 4;
			all->flagi.flag = 1;
			break ;
		}
	}
}
