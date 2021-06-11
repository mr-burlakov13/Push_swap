/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:53:23 by lhayward          #+#    #+#             */
/*   Updated: 2021/04/06 15:57:56 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	fivi(t_list *list, char *line)
{
	if (line[0] == 'p' && line[1] == 'b' && line[2] == '\0')
		p_b(&list->st_b, &list->st_a, &list->len_b, &list->len_a);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b')
		shift_to_the_right_b(&list->st_b, list->len_b, 0);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\0')
		left_shift_b(&list->st_b, list->len_b, 0);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\0')
		r_r(list->st_a, list->len_a, list->st_b, list->len_b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r')
		r_r_r(list->st_a, list->len_a, list->st_b, list->len_b);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\0')
		p_a(&list->st_a, &list->st_b, &list->len_a, &list->len_b);
	else if (line[0] == 's' && line[1] == 'a' && line[2] == '\0')
		s_a(&list->st_a, list->len_a);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a')
		shift_to_the_right_a(&list->st_a, list->len_a, 0);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\0')
		left_shift_a(&list->st_a, list->len_a, 0);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\0')
		s_s(list->st_a, list->st_b, list->len_a, list->len_b);
	else
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	slam(t_list *list)
{
	char	*line;
	int		i;

	while (get_next_line(0, &line))
	{
		if (line[0] == 's' && line[1] == 'b' && line[2] == '\0')
			s_b(&list->st_b, list->len_b);
		else
			fivi(list, line);
		free(line);
	}
	i = -1;
	while (++i < list->len_a - 1)
	{
		if (list->st_a[i] > list->st_a[i + 1])
		{
			write(1, "\033[1;31mKO\n", strlen("\033[1;31mKO\n"));
			exit(1);
		}
	}
	write(1, "\033[1;32mOK\n", strlen("\033[1;31mKO\n"));
}

int	main(int argc, char **argv)
{
	int		len;
	int		i;
	t_list	list;

	len = argc - 1;
	list.len_a = argc - 1;
	list.len_b = 0;
	list.st_b = NULL;
	list.st_a = (int *)malloc(sizeof(int) * len);
	i = -1;
	while (++i < len)
	{
		valid_1(argv[i + 1]);
		list.st_a[i] = ft_atoi_1(argv[i + 1]);
	}
	slam(&list);
	i = -1;
	return (0);
}
