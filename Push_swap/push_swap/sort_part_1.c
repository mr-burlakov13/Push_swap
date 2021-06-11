/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_part_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 10:50:01 by lhayward          #+#    #+#             */
/*   Updated: 2021/04/06 11:25:48 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_1(t_all *all)
{
	if (all->flagi.q < all->stack.len_a / 2)
	{
		while (all->flagi.q >= 0 && all->flagi.work_elem > 0)
		{
			r_r(all->stack.st_a, all->stack.len_a, \
					all->stack.st_b, all->stack.len_b);
			all->flagi.q--;
			all->flagi.work_elem--;
		}
		while (all->flagi.q >= 0)
		{
			left_shift_a(&all->stack.st_a, all->stack.len_a, 0);
			all->flagi.q--;
		}
	}
	else
	{
		while (all->stack.len_a - all->flagi.q - 1)
		{
			shift_to_the_right_a(&all->stack.st_a, \
					all->stack.len_a, 0);
			all->flagi.q++;
		}
	}
}

void	s_2(t_all *all)
{
	all->flagi.q = -1;
	while (++all->flagi.q < all->stack.len_a)
	{
		if (all->stack.st_a[all->flagi.q] == all->flagi.max_a)
			break ;
	}
	s_1(all);
	while (all->flagi.work_elem > 0)
	{
		left_shift_b(&all->stack.st_b, all->stack.len_b, 0);
		all->flagi.work_elem--;
	}
	p_a(&all->stack.st_a, &all->stack.st_b, \
			&all->stack.len_a, &all->stack.len_b);
}

void	s_3(t_all *all)
{
	if (all->flagi.q > all->stack.len_a / 2)
	{
		while (all->stack.len_a - all->flagi.q > 0)
		{
			shift_to_the_right_a(&all->stack.st_a, all->stack.len_a, 0);
			all->flagi.q++;
		}
	}
	else
	{
		while (all->flagi.q > 0 && all->flagi.work_elem > 0)
		{
			r_r(all->stack.st_a, all->stack.len_a, \
					all->stack.st_b, all->stack.len_b);
			all->flagi.q--;
			all->flagi.work_elem--;
		}
	}
}

void	s_4(t_all *all)
{
	all->flagi.q = -1;
	while (++all->flagi.q < all->stack.len_a)
	{
		if (all->stack.st_a[all->flagi.q] == all->flagi.min_a)
			break ;
	}
	s_3(all);
	while (all->flagi.work_elem > 0)
	{
		left_shift_b(&all->stack.st_b, all->stack.len_b, 0);
		all->flagi.work_elem--;
	}
	while (all->flagi.q > 0)
	{
		if (all->stack.len_b > 1)
			left_shift_a(&all->stack.st_a, all->stack.len_a, 0);
		all->flagi.q--;
	}
	p_a(&all->stack.st_a, &all->stack.st_b, \
			&all->stack.len_a, &all->stack.len_b);
}

void	s_5(t_all *all)
{
	if (all->stack.st_b[all->flagi.work_elem] > \
			all->stack.st_a[all->stack.len_a - 1])
	{
		if (all->flagi.j <= all->stack.len_a / 2)
		{
			d1_4(all, all->flagi.j);
			p_a(&all->stack.st_a, &all->stack.st_b, \
					&all->stack.len_a, &all->stack.len_b);
		}
		else
		{
			d2_4(all, all->flagi.j);
			p_a(&all->stack.st_a, &all->stack.st_b, \
					&all->stack.len_a, &all->stack.len_b);
		}
	}
}
