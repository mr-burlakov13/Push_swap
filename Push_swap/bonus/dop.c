/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:58:21 by lhayward          #+#    #+#             */
/*   Updated: 2021/04/06 19:13:55 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	cvet(t_list list, int nb)
{
	int	cv;

	(void)list;
	if (nb > 250)
		nb = 250;
	cv = 255;
	cv = (cv << 8) + 250;
	cv = (cv << 8) + 250 / nb;
	return (cv);
}

int	*puzirek1(t_list list)
{
	int	i;
	int	tmp;

	list.mas1 = (int *)malloc(sizeof(int) * list.len_a);
	i = -1;
	while (++i < list.len_a)
		list.mas1[i] = list.st_a[i];
	i = 0;
	while (++i < list.len_a)
	{
		if (list.mas1[i - 1] > list.mas1[i])
		{
			tmp = list.mas1[i];
			list.mas1[i] = list.mas1[i - 1];
			list.mas1[i - 1] = tmp;
			i = 0;
		}
	}
	return (list.mas1);
}

int	*puzirek2(t_list list)
{
	int	i;
	int	tmp;

	list.mas2 = (int *)malloc(sizeof(int) * list.len_b);
	i = -1;
	while (++i < list.len_b)
		list.mas2[i] = list.st_b[i];
	i = 0;
	while (++i < list.len_b)
	{
		if (list.mas2[i - 1] > list.mas2[i])
		{
			tmp = list.mas2[i];
			list.mas2[i] = list.mas2[i - 1];
			list.mas2[i - 1] = tmp;
			i = 0;
		}
	}
	return (list.mas2);
}

int	nomer(t_list list, int q, int ind)
{
	int	*sort_mas;
	int	i;

	i = 0;
	if (ind == 0)
	{
		sort_mas = list.mas1;
		while (i < list.len_a)
		{
			if (list.st_a[q] == sort_mas[i])
				break ;
			i++;
		}
	}
	else
	{
		sort_mas = list.mas2;
		while (i < list.len_b)
		{
			if (list.st_b[q] == sort_mas[i])
				break ;
			i++;
		}
	}
	return (i);
}

void	piche(t_list list, int len, int sdvig)
{
	if (sdvig == 700)
	{
		list.r1 = list.r2;
		list.l1 = list.l2;
	}
	list.mas1 = puzirek1(list);
	list.mas2 = puzirek2(list);
	draw(list, len, sdvig);
	free(list.mas1);
	free(list.mas2);
}
