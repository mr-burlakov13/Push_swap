/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2_ku_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 09:56:56 by lhayward          #+#    #+#             */
/*   Updated: 2021/04/06 10:03:32 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sor2_1(t_all *all)
{
	if (all->flagi.q > all->stack.len_a / 2)
	{
		while (all->stack.len_b - all->flagi.work_elem > 0 \
				&& all->flagi.q < all->stack.len_a)
		{
			r_r_r(all->stack.st_a, all->stack.len_a, \
					all->stack.st_b, all->stack.len_b);
			all->flagi.work_elem++;
			all->flagi.q++;
		}
		while (all->flagi.q < all->stack.len_a)
		{
			shift_to_the_right_a(&all->stack.st_a, all->stack.len_a, 0);
			all->flagi.q++;
		}
	}
	else
	{
		while (all->flagi.q > 0)
		{
			left_shift_a(&all->stack.st_a, all->stack.len_a, 0);
			all->flagi.q--;
		}
	}
}

void	sor2_2(t_all *all)
{
	all->flagi.q = -1;
	while (++all->flagi.q < all->stack.len_a)
	{
		if (all->stack.st_a[all->flagi.q] == all->flagi.min_a)
			break ;
	}
	sor2_1(all);
	while (all->stack.len_b - all->flagi.work_elem > 0)
	{
		shift_to_the_right_b(&all->stack.st_b, all->stack.len_b, 0);
		all->flagi.work_elem++;
	}
	p_a(&all->stack.st_a, &all->stack.st_b, \
			&all->stack.len_a, &all->stack.len_b);
}

void	sor2_3(t_all *all)
{
	if (all->flagi.q > all->stack.len_a / 2)
	{
		while (all->stack.len_a - all->flagi.q - 1 > 0 \
				&& all->flagi.work_elem < all->stack.len_b)
		{
			r_r_r(all->stack.st_a, all->stack.len_a, \
					all->stack.st_b, all->stack.len_b);
			all->flagi.work_elem++;
			all->flagi.q--;
		}
		while (all->flagi.q > 0 && all->flagi.max_a != \
				all->stack.st_a[all->stack.len_a - 1])
		{
			shift_to_the_right_a(&all->stack.st_a, all->stack.len_a, 0);
			all->flagi.q--;
		}
	}
	else
	{
		while (all->flagi.q >= 0)
		{
			left_shift_a(&all->stack.st_a, all->stack.len_a, 0);
			all->flagi.q--;
		}
	}
}

void	sor2_4(t_all *all)
{
	all->flagi.q = -1;
	while (++all->flagi.q < all->stack.len_a)
	{
		if (all->stack.st_a[all->flagi.q] == all->flagi.max_a)
			break ;
	}
	sor2_3(all);
	while (all->flagi.work_elem < all->stack.len_b)
	{
		shift_to_the_right_b(&all->stack.st_b, all->stack.len_b, 0);
		all->flagi.work_elem++;
	}
	p_a(&all->stack.st_a, &all->stack.st_b, \
			&all->stack.len_a, &all->stack.len_b);
}
