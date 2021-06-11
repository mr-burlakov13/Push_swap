/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:57:24 by lhayward          #+#    #+#             */
/*   Updated: 2021/04/06 14:02:46 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

void	r_r(int *mas1, int len1, int *mas2, int len2)
{
	left_shift_a(&mas1, len1, 1);
	left_shift_b(&mas2, len2, 1);
	write(1, "rr\n", 3);
}

void	r_r_r(int *mas1, int len1, int *mas2, int len2)
{
	shift_to_the_right_a(&mas1, len1, 1);
	shift_to_the_right_b(&mas2, len2, 1);
	write(1, "rrr\n", 4);
}

void	p_a2(int **mas2, int *len_2, int **tmp1)
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

void	p_a(int **mas1, int **mas2, int *len_1, int *len_2)
{
	int	i;
	int	*tmp1;
	int	*tmp2;

	if (*len_2 == 0)
		return ;
	(*len_2)--;
	(*len_1)++;
	p_a2(mas2, len_2, &tmp1);
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
	write(1, "pa\n", 3);
}

void	for_trex(int **stack_a, int len)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if ((*stack_a)[2] < (*stack_a)[1])
			shift_to_the_right_a(&(*stack_a), 3, 0);
		else if ((*stack_a)[0] > (*stack_a)[2] && (*stack_a)[0] > (*stack_a)[1])
			left_shift_a(&(*stack_a), 3, 0);
		else if ((*stack_a)[0] > (*stack_a)[1])
			s_a(&(*stack_a), len);
	}
}
