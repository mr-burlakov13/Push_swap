/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:30:58 by lhayward          #+#    #+#             */
/*   Updated: 2021/04/06 11:42:19 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	normal(int *mas, int len)
{
	int	i;
	int	j;

	j = 0;
	i = -1;
	while (++i < len - 1)
	{
		if (mas[i] < mas[i + 1])
			continue ;
		else
			j = 1;
	}
	if (j == 0)
		exit(1);
}

void	finish(t_all *all)
{
	int	i;

	i = 0;
	all->flagi.min_a = all->stack.st_a[0];
	while (++i < all->stack.len_a)
	{
		if (all->flagi.min_a > all->stack.st_a[i])
			all->flagi.min_a = all->stack.st_a[i];
	}
	i = -1;
	while (++i < all->stack.len_a)
		if (all->stack.st_a[i] == all->flagi.min_a)
			break ;
	if (i > all->stack.len_a / 2)
	{
		while (all->stack.len_a - i)
		{
			shift_to_the_right_a(&all->stack.st_a, all->stack.len_a, 0);
			i++;
		}
	}
	else
		while (i-- > 0)
			left_shift_a(&all->stack.st_a, all->stack.len_a, 0);
	i = -1;
}

void	sortirovka(t_all *all)
{
	while (all->stack.len_b)
	{
		find_elem(all);
		if (all->flagi.work_elem <= all->stack.len_b / 2)
			sort1(all);
		else
			sort2(all);
	}
}

void	init(t_all *all)
{
	all->mlx.ptr = NULL;
	all->flagi.flag = 0;
	all->flagi.count = 0;
	all->flagi.vlevo = 0;
	all->flagi.vpravo = 0;
	all->flagi.work_elem = 1000;
	all->flagi.flag_p = 0;
	all->flagi.flag_l = 0;
	poryadok(all);
	perebros(all);
	if (all->flagi.flag == 0)
		sort_for_five(all);
	all->flagi.flag = 0;
	sortirovka(all);
	finish(all);
}

int	main(int argc, char **argv)
{
	t_all	all;
	int		len;
	int		i;

	len = argc - 1;
	all.stack.len_a = argc - 1;
	all.stack.len_b = 0;
	all.stack.st_b = NULL;
	all.stack.st_a = (int *)malloc(sizeof(int) * len);
	i = -1;
	while (++i < len)
	{
		valid_1(argv[i + 1]);
		all.stack.st_a[i] = ft_atoi_1(argv[i + 1]);
	}
	valid_2(all.stack.st_a, all.stack.len_a);
	normal(all.stack.st_a, all.stack.len_a);
	w234(&all, len);
	init(&all);
	return (0);
}
