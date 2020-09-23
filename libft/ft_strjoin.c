/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <taehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:30:56 by taehkim           #+#    #+#             */
/*   Updated: 2020/04/04 20:46:20 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*mover;
	char	*output;

	size = ft_strlen(s1) + ft_strlen(s2);
	output = (char *)malloc(sizeof(char) * (size + 1));
	if (!output)
		return (0);
	mover = (char *)s1;
	while (*mover)
	{
		*output = *mover;
		output++;
		mover++;
	}
	mover = (char *)s2;
	while (*mover)
	{
		*output = *mover;
		output++;
		mover++;
	}
	*output = '\0';
	return (output - size);
}
