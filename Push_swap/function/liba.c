/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liba.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:45:57 by lhayward          #+#    #+#             */
/*   Updated: 2021/04/06 13:46:50 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_chet(size_t i, size_t j, size_t k, const char *mas)
{
	int	q;

	q = 1;
	while (mas[i] == ' ' || (mas[i] >= 9 && mas[i] <= 13))
		i++;
	if (mas[i] == '+' || mas[i] == '-')
	{
		if (mas[i] == '-')
			q = -q;
		i++;
	}
	while (mas[i] >= '0' && mas[i] <= '9')
	{
		if (j == k && mas[i] > '7' && q == 1)
			return (-1);
		else if (j > k && mas[i] >= '0' && q == 1)
			return (-1);
		else if (j == k && mas[i] > '8' && q == -1)
			return (0);
		else if (j > k && mas[i] >= '0' && q == -1)
			return (0);
		j = j * 10 + mas[i++] - '0';
	}
	return ((int)(j * q));
}

int	ft_atoi_1(const char *mas)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 214748364;
	return (ft_chet(i, j, k, mas));
}
