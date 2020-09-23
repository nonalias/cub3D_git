/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <taehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:32:15 by taehkim           #+#    #+#             */
/*   Updated: 2020/04/06 13:29:14 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_mystrdup(char *src, int count)
{
	char	*output;
	int		i;

	output = (char *)malloc(sizeof(char) * (count + 1));
	if (!output)
		return (NULL);
	i = 0;
	while (i < count)
	{
		output[i] = src[i];
		i++;
	}
	output[i] = 0;
	return (output);
}

static char	**ft_run(const char *src, char **output, int realsize, char c)
{
	char	*mover;
	int		count;
	int		i;

	i = 0;
	mover = (char *)src;
	while (i < realsize)
	{
		count = 0;
		while (*mover == c)
			mover++;
		while (*mover != c && *mover != '\0')
		{
			mover++;
			count++;
		}
		output[i] = ft_mystrdup(mover - count, count);
		i++;
	}
	output[i] = 0;
	return (output);
}

char		**ft_split(const char *src, char c)
{
	int		realsize;
	int		i;
	char	**output;

	realsize = 0;
	i = 0;
	while (src[i])
	{
		if (src[i] != c && (src[i + 1] == c || src[i + 1] == '\0'))
			realsize++;
		i++;
	}
	output = (char **)malloc(sizeof(char *) * (realsize + 1));
	if (!output)
		return (NULL);
	output = ft_run(src, output, realsize, c);
	return (output);
}
