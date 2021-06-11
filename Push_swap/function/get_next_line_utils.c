/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:15:51 by lhayward          #+#    #+#             */
/*   Updated: 2021/04/06 14:49:09 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_strjoin(char *s1, const char *s2)
{
	int		i;
	int		j;
	int		len_1;
	int		len_2;
	char	*arr;

	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	i = 0;
	j = 0;
	arr = (char *)malloc(sizeof(char) * (len_1 + len_2 + 1));
	if (arr == NULL)
		return (NULL);
	while (len_1--)
	{
		arr[i] = s1[i];
		i++;
	}
	while (len_2--)
		arr[i++] = s2[j++];
	arr[i] = '\0';
	free(s1);
	return (arr);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (0);
		s = &s[i + 1];
	}
	return ((char *)s);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup_mod(char *s1)
{
	int		i;
	char	*arr;

	i = 0;
	if (!s1)
		return (0);
	while (s1[i] != '\n' && s1[i] != '\0')
		i++;
	arr = (char *)malloc(sizeof(char) * (i + 1));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\n' && s1[i] != '\0')
	{
		arr[i] = s1[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
