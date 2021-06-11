/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_4_xp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 09:28:34 by lhayward          #+#    #+#             */
/*   Updated: 2021/04/06 10:44:33 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	d2_4(t_all *all, int j)
{
	while (all->flagi.work_elem > 0)
	{
		left_shift_b(&all->stack.st_b, all->stack.len_b, 0);
		all->flagi.work_elem--;
	}
	while (all->stack.len_a - j > 0)
	{
		shift_to_the_right_a(&all->stack.st_a, all->stack.len_a, 0);
		j++;
	}
}

void	d1_4(t_all *all, int j)
{
	while (all->flagi.work_elem > 0 && j > 0)
	{
		r_r(all->stack.st_a, all->stack.len_a, \
			   	all->stack.st_b, all->stack.len_b);
		all->flagi.work_elem--;
		j--;
		all->flagi.vlevo++;
	}
	while (all->flagi.work_elem > 0)
	{
		left_shift_b(&all->stack.st_b, all->stack.len_b, 0);
		all->flagi.work_elem--;
	}
	while (j > 0)
	{
		left_shift_a(&all->stack.st_a, all->stack.len_a, 0);
		j--;
		all->flagi.vlevo++;
	}
}

void	d3_4(t_all *all, int j)
{
	while (all->flagi.work_elem < all->stack.len_b)
	{
		shift_to_the_right_b(&all->stack.st_b, all->stack.len_b, 0);
		all->flagi.work_elem++;
	}
	while (j > 0)
	{
		left_shift_a(&all->stack.st_a, all->stack.len_a, 0);
		all->flagi.vlevo++;
		j--;
	}
}

void	d4_4(t_all *all, int j)
{
	while (all->flagi.work_elem < all->stack.len_b && all->stack.len_a - j > 0)
	{
		r_r_r(all->stack.st_a, all->stack.len_a, \
			   	all->stack.st_b, all->stack.len_b);
		all->flagi.work_elem++;
		j++;
	}
	while (all->stack.len_a - j > 0)
	{
		shift_to_the_right_a(&all->stack.st_a, all->stack.len_a, 0);
		j++;
	}
	while (all->flagi.work_elem < all->stack.len_b)
	{
		shift_to_the_right_b(&all->stack.st_b, all->stack.len_b, 0);
		all->flagi.work_elem++;
	}
}
