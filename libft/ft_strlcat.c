/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <taehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:48:09 by taehkim           #+#    #+#             */
/*   Updated: 2020/03/06 19:58:03 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dest, const char *src, int n)
{
	int	destsize;
	int	srcsize;
	int	i;

	destsize = (int)ft_strlen(dest);
	srcsize = (int)ft_strlen(src);
	if (destsize > n)
		return (n + srcsize);
	if (srcsize == 0)
		return (destsize);
	i = 0;
	while (i < n - destsize - 1 && src[i])
	{
		dest[destsize + i] = src[i];
		i++;
	}
	dest[destsize + i] = '\0';
	return (destsize + srcsize);
}
