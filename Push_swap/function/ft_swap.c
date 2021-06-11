/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <lhayward@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 11:00:17 by lhayward          #+#    #+#             */
/*   Updated: 2021/04/06 13:45:47 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

void	ft_swap(int *a, int *b)
{
	int	p;

	p = *b;
	*b = *a;
	*a = p;
}

void	s_a(int **mas, int len)
{
	if (len < 2)
		return ;
	ft_swap(*mas, (*mas) + 1);
	write(1, "sa\n", 3);
}

void	s_s(int *mas1, int *mas2, int len1, int len2)
{
	s_a(&mas1, len1);
	s_b(&mas2, len2);
	write(1, "ss\n", 3);
}

void	shift_to_the_right_a(int **mas, int len, int a)
{
	int	i;

	if (len <= 1)
		return ;
	i = len;
	while (--i > 0)
		ft_swap(*mas + i, *mas + i - 1);
	if (a == 0)
		write(1, "rra\n", 4);
}

void	left_shift_a(int **mas, int len, int a)
{
	int	i;

	if (len <= 1)
		return ;
	i = -1;
	while (++i < len - 1)
		ft_swap((*mas) + i, (*mas) + i + 1);
	if (a == 0)
		write(1, "ra\n", 3);
}
