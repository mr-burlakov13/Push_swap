/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:10:28 by lhayward          #+#    #+#             */
/*   Updated: 2021/04/06 14:46:04 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "checker.h"

static char	*save_ost(char *ost)
{
	char	*arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!ost)
		return (0);
	while (ost[i] != '\0' && ost[i] != '\n')
		i++;
	if (ost[i] == '\0')
	{
		free(ost);
		return (0);
	}
	arr = (char *)malloc(sizeof(char) * (ft_strlen(ost) - i + 1));
	if (arr == NULL)
		return (NULL);
	i++;
	while (ost[i])
		arr[j++] = ost[i++];
	arr[j] = '\0';
	free(ost);
	return (arr);
}

int	get_next_line(int fd, char **line)
{
	static char	*ost[100000];
	char		*buf;
	int			nb;

	nb = 42;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || !line || buf == NULL)
		return (-1);
	while (nb != 0 && ft_strchr(ost[fd], '\n') == 0)
	{
		nb = read(fd, buf, BUFFER_SIZE);
		if (nb < 0)
		{
			free(buf);
			return (-1);
		}
		buf[nb] = '\0';
		ost[fd] = ft_strjoin(ost[fd], buf);
	}
	free(buf);
	*line = ft_strdup_mod(ost[fd]);
	ost[fd] = save_ost(ost[fd]);
	if (nb == 0)
		return (0);
	return (1);
}
