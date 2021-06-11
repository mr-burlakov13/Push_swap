/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_part_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:26:00 by lhayward          #+#    #+#             */
/*   Updated: 2021/04/06 11:30:34 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	s_6(t_all *all)
{
	if (all->stack.st_b[all->flagi.work_elem] > \
			all->stack.st_a[all->flagi.j - 1])
	{
		if (all->flagi.j <= all->stack.len_a / 2)
		{
			d1_4(all, all->flagi.j);
			p_a(&all->stack.st_a, &all->stack.st_b, \
				   	&all->stack.len_a, &all->stack.len_b);
			return (1);
		}
		else
		{
			d2_4(all, all->flagi.j);
			p_a(&all->stack.st_a, &all->stack.st_b, \
					&all->stack.len_a, &all->stack.len_b);
			return (1);
		}
	}
	return (0);
}

void	sort1(t_all *all)
{
	all->flagi.j = 0;
	while (all->stack.len_b > 0)
	{
		if (all->stack.st_b[all->flagi.work_elem] < all->stack.st_a[all->flagi.j] \
				&& all->stack.st_b[all->flagi.work_elem] > all->flagi.min_a)
		{
			if (all->flagi.j == 0)
				s_5(all);
			else
				if (s_6(all) == 1)
					break ;
		}
		else if (all->stack.st_b[all->flagi.work_elem] > all->flagi.max_a)
		{
			s_2(all);
			break ;
		}
		else if (all->stack.st_b[all->flagi.work_elem] < all->flagi.min_a)
		{
			s_4(all);
			break ;
		}
		all->flagi.j++;
	}
}
