/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 19:17:13 by lhayward          #+#    #+#             */
/*   Updated: 2021/04/10 11:09:27 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <pthread.h>
# include "mlx.h"

# define BUFFER_SIZE 32
# define SKALE 16
# define R = 255;
# define G = 255;
# define B = 255;

typedef struct s_list
{
	int					*st_a;
	int					*st_b;
	int					len_a;
	int					len_b;
	void				*img;
	void				*win;
	void				*adr;
	void				*ptr;
	int					bpp;
	int					ll;
	int					end;
	int					r1;
	int					l1;
	int					r2;
	int					l2;
	int					*mas1;
	int					*mas2;
	pthread_mutex_t		mutex;
}						t_list;

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
void					valid_1(char *str);
void					valid_2(int *mas, int len);
int						get_next_line(int fd, char **line);
char					*ft_strjoin(char *s1, const char *s2);
char					*ft_strdup_mod(char *s1);
char					*ft_strchr(const char *s, int c);
size_t					ft_strlen(const char *s);
int						ft_atoi_1(const char *mas);
int						cloze1(t_list *list);
int						cvet(t_list list, int nb);
int						*puzirek1(t_list list);
int						*puzirek2(t_list list);
int						nomer(t_list list, int q, int ind);
void					piche(t_list list, int len, int sdvig);
void					my_mlx_pixel_put(t_list *list, int x, int y, int color);
void					ini(t_list *list, int argc);
void					draw(t_list list, int len, int sdvig);
void					vihod(void);
void					valid_3(long long int j);
#endif
