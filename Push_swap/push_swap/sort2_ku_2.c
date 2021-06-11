/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2_ku_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 10:03:52 by lhayward          #+#    #+#             */
/*   Updated: 2021/04/06 10:14:25 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sor2_5(t_all *all)
{
	if (all->stack.st_b[all->flagi.work_elem] > \
			all->stack.st_a[all->stack.len_a - 1])
	{
		if (all->flagi.j <= all->stack.len_a / 2)
		{
			d3_4(all, all->flagi.j);
			p_a(&all->stack.st_a, &all->stack.st_b, \
					&all->stack.len_a, &all->stack.len_b);
			return (1);
		}
		else
		{
			d4_4(all, all->flagi.j);
			p_a(&all->stack.st_a, &all->stack.st_b, \
					&all->stack.len_a, &all->stack.len_b);
			return (1);
		}
	}
	return (0);
}

int	sor2_6(t_all *all)
{
	if (all->stack.st_b[all->flagi.work_elem] > \
			all->stack.st_a[all->flagi.j - 1])
	{
		if (all->flagi.j <= all->stack.len_a / 2)
		{
			d3_4(all, all->flagi.j);
			p_a(&all->stack.st_a, &all->stack.st_b, \
					&all->stack.len_a, &all->stack.len_b);
			return (1);
		}
		else
		{
			d4_4(all, all->flagi.j);
			p_a(&all->stack.st_a, &all->stack.st_b, \
					&all->stack.len_a, &all->stack.len_b);
			return (1);
		}
	}
	return (0);
}

void	sort2(t_all *all)
{
	all->flagi.j = -1;
	while (++all->flagi.j < all->stack.len_a)
	{
		if (all->stack.st_b[all->flagi.work_elem] < all->flagi.min_a)
		{
			sor2_2(all);
			break ;
		}
		else if (all->stack.st_b[all->flagi.work_elem] < \
				all->stack.st_a[all->flagi.j])
		{
			if (all->flagi.j == 0)
			{
				if (sor2_5(all) == 1)
					break ;
			}
			else if (sor2_6(all) == 1)
				break ;
		}
		else if (all->stack.st_b[all->flagi.work_elem] > all->flagi.max_a)
		{
			sor2_4(all);
			break ;
		}
	}
}
