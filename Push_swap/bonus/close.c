/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:58:53 by lhayward          #+#    #+#             */
/*   Updated: 2021/04/06 18:58:12 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	cloze1(t_list *list)
{
	(void)list;
	exit(0);
	return (1);
}

void	draw(t_list list, int len, int sdvig)
{
	int	i;
	int	nb;
	int	j;
	int	q;

	q = 0;
	i = 0;
	j = 0;
	while (q < len)
	{
		nb = nomer(list, q, sdvig) + 1;
		i = 0;
		while (i < nb * list.l1)
		{
			j = 0;
			while (j < list.r1)
			{
				my_mlx_pixel_put(&list, i + sdvig, \
						q * list.r1 + j, cvet(list, nb));
				j++;
			}
			i++;
		}
		q++;
	}
}

void	ini(t_list *list, int argc)
{
	int	len;

	len = argc - 1;
	list->len_a = argc - 1;
	list->len_b = 0;
	list->st_b = NULL;
	list->st_a = (int *)malloc(sizeof(int) * len);
	if (list->st_a == NULL)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	list->r1 = 600 / list->len_a;
	list->l1 = 500 / list->len_a;
	list->r2 = 600 / list->len_a;
	list->l2 = 500 / list->len_a;
}

void	vihod(void)
{
	write(1, "\033[1;31mKO\n", strlen("\033[1;31mKO\n"));
	exit(1);
}
