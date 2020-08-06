/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <taehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 00:11:04 by taehkim           #+#    #+#             */
/*   Updated: 2020/03/18 02:15:07 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strndup(char *src, int size)
{
	int		i;
	char	*output;

	i = 0;
	output = (char *)malloc(sizeof(char) * (size + 1));
	while (i < size)
	{
		output[i] = src[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

void	ft_src_set(char **src, int temp)
{
	int		srcsize;
	int		i;
	char	*ctemp;

	srcsize = 0;
	while ((*src)[srcsize])
		srcsize++;
	ctemp = (char *)malloc(sizeof(char) * (srcsize - temp + 1));
	i = 0;
	while (i < srcsize - temp)
	{
		ctemp[i] = (*src)[i + temp];
		i++;
	}
	ctemp[i] = '\0';
	free(*src);
	*src = ctemp;
}

int		ft_has_new_line(char *src)
{
	if (!src)
		return (0);
	while (*src)
	{
		if (*src == '\n')
			return (1);
		src++;
	}
	return (0);
}

int		ft_get_next_size(char *src)
{
	int		count;

	count = 0;
	while (src[count] != '\n')
		count++;
	return (count);
}

void	ft_strcat(char **src, char *buf, int bufsize, int srcsize)
{
	int		i;
	char	*ctemp;

	if (*src)
	{
		while ((*src)[srcsize])
			srcsize++;
	}
	ctemp = (char *)malloc(sizeof(char) * (srcsize + bufsize + 1));
	ctemp[srcsize + bufsize] = '\0';
	i = 0;
	while (i < srcsize)
	{
		ctemp[i] = (*src)[i];
		i++;
	}
	i = 0;
	while (i < bufsize)
	{
		ctemp[i + srcsize] = buf[i];
		i++;
	}
	free(*src);
	*src = ctemp;
}
