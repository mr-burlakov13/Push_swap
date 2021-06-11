/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_dop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:46:59 by lhayward          #+#    #+#             */
/*   Updated: 2021/04/06 13:57:17 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

void	s_b(int **mas, int len)
{
	if (len < 2)
		return ;
	ft_swap(*mas, (*mas) + 1);
	write(1, "sb\n", 3);
}

void	p_b2(int **mas2, int *len_2, int **tmp1)
{
	int	i;

	if (*len_2 != 0)
	{
		*tmp1 = malloc(sizeof(int) * (*len_2));
		if (*tmp1 == NULL)
		{
			exit(0);
			write(2, "Error\n", 6);
		}
		i = 0;
		while (++i < (*len_2 + 1))
			(*tmp1)[i - 1] = (*mas2)[i];
	}
	else
		*tmp1 = 0;
}

void	p_b(int **mas1, int **mas2, int *len_1, int *len_2)
{
	int	i;
	int	*tmp1;
	int	*tmp2;

	if (*len_2 == 0)
		return ;
	(*len_2)--;
	(*len_1)++;
	p_b2(mas2, len_2, &tmp1);
	tmp2 = malloc(sizeof(int) * (*len_1));
	if (tmp2 == NULL)
	{
		exit(0);
		write(2, "Error\n", 6);
	}
	i = 0;
	tmp2[0] = (*mas2)[0];
	while (++i < (*len_1))
		tmp2[i] = (*mas1)[i - 1];
	free(*mas1);
	free(*mas2);
	*mas1 = tmp2;
	*mas2 = tmp1;
	write(1, "pb\n", 3);
}

void	shift_to_the_right_b(int **mas, int len, int a)
{
	int	i;

	if (len <= 1)
		return ;
	i = len;
	while (--i > 0)
		ft_swap(*mas + i, *mas + i - 1);
	if (a == 0)
		write(1, "rrb\n", 4);
}

void	left_shift_b(int **mas, int len, int a)
{
	int	i;

	if (len <= 1)
		return ;
	i = -1;
	while (++i < len - 1)
		ft_swap((*mas) + i, (*mas) + i + 1);
	if (a == 0)
		write(1, "rb\n", 3);
}
