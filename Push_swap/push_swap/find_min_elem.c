/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_elem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 10:35:42 by lhayward          #+#    #+#             */
/*   Updated: 2021/04/06 12:37:26 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_work_elem(t_all *all, int *mas_index)
{
	int	i;

	all->flagi.work_elem = 1000;
	i = -1;
	while (++i < all->stack.len_b)
	{
		if (all->flagi.work_elem > mas_index[i])
		{
			all->flagi.work_elem = mas_index[i];
		}
	}
	i = -1;
	while (++i < all->stack.len_b)
	{
		if (all->flagi.work_elem == mas_index[i])
		{
			all->flagi.work_elem = i;
			break ;
		}
	}
	free(mas_index);
}

void	max_min_a(t_all *all)
{
	int	m_i;

	m_i = 0;
	all->flagi.i = -1;
	all->flagi.max_a = all->stack.st_a[0];
	while (++m_i < all->stack.len_a)
	{
		if (all->flagi.max_a < all->stack.st_a[m_i])
			all->flagi.max_a = all->stack.st_a[m_i];
	}
	m_i = 0;
	all->flagi.min_a = all->stack.st_a[0];
	while (++m_i < all->stack.len_a)
	{
		if (all->flagi.min_a > all->stack.st_a[m_i])
			all->flagi.min_a = all->stack.st_a[m_i];
	}
}

void	find_elem(t_all *all)
{
	int	*mas_index;

	mas_index = (int *)malloc(sizeof(int) * (all->stack.len_b));
	if (mas_index == NULL)
	{
		exit(1);
	}
	if (all->stack.len_b == 1)
	{
		all->flagi.work_elem = 0;
		return ;
	}
	max_min_a(all);
	while (++all->flagi.i < all->stack.len_b)
	{
		all->flagi.tmp = 0;
		if (all->flagi.i <= all->stack.len_b / 2)
			pervaya_polovina(all);
		else
			vtoraya_polovina(all);
		mas_index[all->flagi.i] = all->flagi.tmp;
	}
	get_work_elem(all, mas_index);
}
