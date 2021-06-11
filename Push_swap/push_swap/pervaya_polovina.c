/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pervaya_polovina.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 09:41:24 by lhayward          #+#    #+#             */
/*   Updated: 2021/04/06 09:55:48 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	wer(t_all *all)
{
	if (all->flagi.j <= all->stack.len_a / 2)
	{
		all->flagi.tmp = all->flagi.j + all->flagi.i;
		all->flagi.a = all->flagi.j;
		all->flagi.b = all->flagi.i;
		while (all->flagi.a-- > 0 && all->flagi.b-- > 0)
			all->flagi.tmp--;
	}
	else
		all->flagi.tmp = all->stack.len_a - all->flagi.j + all->flagi.i;
}

void	per_pol_1(t_all *all)
{
	if (all->flagi.j == 0)
	{
		if (all->stack.st_b[all->flagi.i] > \
				all->stack.st_a[all->stack.len_a - 1])
		{
			if (all->flagi.j <= all->stack.len_a / 2)
				all->flagi.tmp = all->flagi.j + all->flagi.i;
			else
				all->flagi.tmp = all->stack.len_a - all->flagi.j + all->flagi.i;
		}
	}
	else
	{
		if (all->stack.st_b[all->flagi.i] > all->stack.st_a[all->flagi.j - 1])
		{
			wer(all);
		}
	}
}

void	per_pol_2(t_all *all)
{
	int	q;

	q = -1;
	while (++q < all->stack.len_a)
	{
		if (all->stack.st_a[q] == all->flagi.max_a)
			break ;
	}
	if (q > all->stack.len_a / 2)
		all->flagi.tmp = all->flagi.i + all->stack.len_a - q;
	else
	{
		all->flagi.tmp = all->flagi.i + q + 1;
		all->flagi.a = all->flagi.i;
		all->flagi.b = q + 1;
		while (all->flagi.a-- > 0 && all->flagi.b-- > 0)
			all->flagi.tmp--;
	}
}

void	per_pol_3(t_all *all)
{
	int	h;

	h = -1;
	while (++h < all->stack.len_a)
	{
		if (all->stack.st_a[h] == all->flagi.min_a)
			break ;
	}
	if (h > all->stack.len_a / 2)
		all->flagi.tmp = all->flagi.i + all->stack.len_a - h;
	else
	{
		all->flagi.tmp = all->flagi.i + h;
		all->flagi.a = all->flagi.i;
		all->flagi.b = h;
		while (all->flagi.a-- > 0 && all->flagi.b-- > 0)
			all->flagi.tmp--;
	}
}

void	pervaya_polovina(t_all *all)
{
	all->flagi.j = -1;
	while (++all->flagi.j < all->stack.len_a)
	{
		if (all->stack.st_b[all->flagi.i] < all->stack.st_a[all->flagi.j] && \
				all->stack.st_b[all->flagi.i] > all->flagi.min_a)
			per_pol_1(all);
		else if (all->stack.st_b[all->flagi.i] > all->flagi.max_a)
			per_pol_2(all);
		else if (all->stack.st_b[all->flagi.i] < all->flagi.min_a)
			per_pol_3(all);
	}
}
