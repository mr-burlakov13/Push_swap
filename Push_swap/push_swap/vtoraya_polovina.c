/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vtoraya_polovina.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:42:45 by lhayward          #+#    #+#             */
/*   Updated: 2021/04/06 11:57:00 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ertq(t_all *all)
{
	if (all->flagi.j <= all->stack.len_a / 2)
		all->flagi.tmp = all->flagi.j + all->stack.len_b - all->flagi.i;
	else
	{
		all->flagi.tmp = all->stack.len_a - all->flagi.j \
						 + all->stack.len_b - all->flagi.i;
		all->flagi.a = all->stack.len_a - all->flagi.j;
		all->flagi.b = all->stack.len_b - all->flagi.i;
		while (all->flagi.a-- > 0 && all->flagi.b-- > 0)
			all->flagi.tmp--;
	}
}

void	vtor_pol_1(t_all *all)
{
	if (all->flagi.j == 0)
	{
		if (all->stack.st_b[all->flagi.i] > \
				all->stack.st_a[all->stack.len_a - 1])
		{
			if (all->flagi.j <= all->stack.len_a / 2)
				all->flagi.tmp = all->flagi.j + \
								 all->stack.len_b - all->flagi.i;
			else
				all->flagi.tmp = all->stack.len_a - all->flagi.j \
								 - all->flagi.i + all->stack.len_b;
		}
	}
	else
	{
		if (all->stack.st_b[all->flagi.i] > all->stack.st_a[all->flagi.j - 1])
		{
			ertq(all);
		}
	}
}

void	vtor_pol_2(t_all *all)
{
	int	q;

	q = -1;
	while (++q < all->stack.len_a)
	{
		if (all->stack.st_a[q] == all->flagi.max_a)
			break ;
	}
	if (q > all->stack.len_a / 2)
	{
		all->flagi.tmp = all->stack.len_b - all->flagi.i + all->stack.len_a - q;
		all->flagi.a = all->stack.len_b - all->flagi.i;
		all->flagi.b = all->stack.len_a - q - 1;
		while (all->flagi.a-- > 0 && all->flagi.b-- > 0)
			all->flagi.tmp--;
	}
	else
		all->flagi.tmp = all->stack.len_b - all->flagi.i + q;
}

void	vtor_pol_3(t_all *all)
{
	int	h ;

	h = -1;
	while (++h < all->stack.len_a)
	{
		if (all->stack.st_a[h] == all->flagi.min_a)
			break ;
	}
	if (h > all->stack.len_a / 2)
	{
		all->flagi.tmp = all->stack.len_b - all->flagi.i + all->stack.len_a - h;
		all->flagi.a = all->stack.len_b - all->flagi.i;
		all->flagi.b = all->stack.len_a - h;
		while (all->flagi.a-- > 0 && all->flagi.b-- > 0)
			all->flagi.tmp--;
	}
	else
	{
		all->flagi.tmp = all->stack.len_b - all->flagi.i + h;
	}
}

void	vtoraya_polovina(t_all *all)
{
	all->flagi.j = -1;
	while (++all->flagi.j < all->stack.len_a)
	{
		if (all->stack.st_b[all->flagi.i] < all->stack.st_a[all->flagi.j] \
				&& all->stack.st_b[all->flagi.i] > all->flagi.min_a)
			vtor_pol_1(all);
		else if (all->stack.st_b[all->flagi.i] > all->flagi.max_a)
			vtor_pol_2(all);
		else if (all->stack.st_b[all->flagi.i] < all->flagi.min_a)
			vtor_pol_3(all);
	}
}
