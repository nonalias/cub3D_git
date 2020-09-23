/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <taehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:47:43 by taehkim           #+#    #+#             */
/*   Updated: 2020/04/07 21:42:41 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	int		intn;
	char	*destmover;
	char	*srcmover;

	if (!dest && !src)
		return (NULL);
	intn = (int)n;
	destmover = (char *)dest;
	srcmover = (char *)src;
	i = 0;
	if (destmover < srcmover)
	{
		while (i < n)
		{
			*(destmover + i) = *(srcmover + i);
			i++;
		}
	}
	else
	{
		while (--intn >= 0)
			*(destmover + intn) = *(srcmover + intn);
	}
	return (dest);
}
