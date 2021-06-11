/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:34:26 by lhayward          #+#    #+#             */
/*   Updated: 2021/04/06 18:00:08 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	my_mlx_pixel_put(t_list *list, int x, int y, int color)
{
	char	*dst;

	dst = list->adr + (y * list->ll + x * (list->bpp / 8));
	*(unsigned int *)dst = color;
}

int	new(t_list *list)
{
	pthread_mutex_unlock(&list->mutex);
	list->img = mlx_new_image(list->ptr, 1200, 800);
	list->adr = mlx_get_data_addr(list->img, &list->bpp, &list->ll, &list->end);
	piche(*list, list->len_a, 0);
	piche(*list, list->len_b, 500);
	mlx_put_image_to_window(list->ptr, list->win, list->img, 0, 0);
	mlx_destroy_image(list->ptr, list->img);
	return (0);
}

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

void	*slam(void *t)
{
	char	*line;
	int		i;
	t_list	*list;

	list = (t_list *)t;
	while (get_next_line(0, &line))
	{
		pthread_mutex_lock(&list->mutex);
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
			vihod();
	}
	write(1, "\033[1;32mOK\n", strlen("\033[1;31mKO\n"));
	exit(1);
	return (0);
}

int	main(int argc, char **argv)
{
	int			len;
	int			i;
	t_list		list;
	pthread_t	thread;

	ini(&list, argc);
	len = argc - 1;
	i = -1;
	while (++i < len)
	{
		valid_1(argv[i + 1]);
		list.st_a[i] = ft_atoi_1(argv[i + 1]);
	}
	pthread_mutex_init(&list.mutex, 0);
	pthread_create(&thread, 0, slam, &list);
	pthread_detach(thread);
	list.ptr = mlx_init();
	list.win = mlx_new_window(list.ptr, 1200, 800, "SORTIROVKA");
	mlx_hook(list.win, 17, 0L, &cloze1, &list);
	mlx_loop_hook(list.ptr, &new, &list);
	mlx_loop(list.ptr);
	return (0);
}
