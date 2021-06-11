/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 19:32:48 by lhayward          #+#    #+#             */
/*   Updated: 2021/04/10 11:10:11 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

typedef struct s_mlx
{
	void				*ptr;
	int					f;
}						t_mlx;

typedef struct s_win
{
	void				*ptr;
	int					x;
	int					y;
}						t_win;

typedef struct s_flagi
{
	int					flag;
	int					count;
	int					tmp;
	int					i;
	int					j;
	int					a;
	int					b;
	int					q;
	int					max_a;
	int					min_a;
	int					work_elem;
	int					vlevo;
	int					vpravo;
	int					flag_p;
	int					flag_l;
	int					flag_pech;
}						t_flagi;

typedef struct s_stack
{
	int					*st_a;
	int					*st_b;
	int					len_a;
	int					len_b;
}						t_stack;

typedef struct s_all
{
	t_flagi				flagi;
	t_mlx				mlx;
	t_win				win;
	t_stack				stack;
}						t_all;

void					ft_swap(int *a, int *b);
void					s_a(int **mas, int len);
void					s_b(int **mas, int len);
void					s_s(int *mas1, int *mas2, int len1, int len2);
void					shift_to_the_right_a(int **mas, int len, int a);
void					left_shift_a(int **mas, int len, int a);
void					shift_to_the_right_b(int **mas, int len, int a);
void					left_shift_b(int **mas, int len, int a);
void					r_r(int *mas1, int len1, int *mas2, int len2);
void					r_r_r(int *mas1, int len1, int *mas2, int len2);
void					p_a2(int **mas2, int *len_2, int **tmp1);
void					p_b2(int **mas2, int *len_2, int **tmp1);
void					p_a(int **mas1, int **mas2, int *len_1, int *len_2);
void					p_b(int **mas1, int **mas2, int *len_1, int *len_2);
void					for_trex(int **stack_a, int len);
void					poryadok(t_all *all);
void					perebros(t_all *all);
void					sort_for_five(t_all *all);
void					sort_for_five(t_all *all);
void					perebros(t_all *all);
void					poryadok(t_all *all);
void					get_work_elem(t_all *all, int *mas_index);
void					pervaya_polovina(t_all *all);
void					per_pol_1(t_all *all);
void					per_pol_2(t_all *all);
void					per_pol_3(t_all *all);
void					vtoraya_polovina(t_all *all);
void					vtor_pol_1(t_all *all);
void					vtor_pol_2(t_all *all);
void					vtor_pol_3(t_all *all);
void					find_elem(t_all *all);
void					d1_4(t_all *all, int j);
void					d2_4(t_all *all, int j);
void					d3_4(t_all *all, int j);
void					d4_4(t_all *all, int j);
void					sort1(t_all *all);
int						s_6(t_all *all);
void					s_1(t_all *all);
void					s_2(t_all *all);
void					s_3(t_all *all);
void					s_4(t_all *all);
void					s_5(t_all *all);
void					sort2(t_all *all);
int						sor2_6(t_all *all);
int						sor2_5(t_all *all);
void					sor2_1(t_all *all);
void					sor2_2(t_all *all);
void					sor2_3(t_all *all);
void					sor2_4(t_all *all);
void					vivod(int *mas, int len);
int						ft_atoi_1(const char *mas);
void					valid_1(char *str);
void					valid_2(int *mas, int len);
void					w234(t_all *all, int len);
void					finish(t_all *all);
int						get_next_line(int fd, char **line);
char					*ft_strjoin(char *s1, const char *s2);
char					*ft_strdup_mod(char *s1);
char					*ft_strchr(const char *s, int c);
size_t					ft_strlen(const char *s);
void					valid_3(long long int j);
#endif
