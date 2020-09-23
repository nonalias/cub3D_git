/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <taehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:45:19 by taehkim           #+#    #+#             */
/*   Updated: 2020/04/06 10:40:55 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*destmover;
	char	*srcmover;
	size_t	i;

	destmover = (char *)dest;
	srcmover = (char *)src;
	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*destmover = *srcmover;
		i++;
		destmover++;
		srcmover++;
	}
	return (dest);
}
