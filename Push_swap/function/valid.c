/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:02:55 by lhayward          #+#    #+#             */
/*   Updated: 2021/04/10 11:08:28 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

void	valid_3(long long int j)
{
	if (j > 2147483647 || j < -2147483648)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

void	valid_1(char *str)
{
	long long int	j;
	int				i;
	int				q;

	q = 1;
	i = -1;
	j = 0;
	if (str[0] == '-')
	{
		i++;
		q = -1;
	}
	while (str[++i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			j = j * 10 + str[i] - '0';
		else
		{
			write(1, "Error\n", 6);
			exit(1);
		}
	}
	valid_3(j * q);
}

void	valid_2(int *mas, int len)
{
	int	i;
	int	j;

	i = -1;
	while (++i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (mas[i] == mas[j])
			{
				write(1, "Error\n", 6);
				exit(1);
			}
			j++;
		}
	}
}
