/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <taehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:16:19 by taehkim           #+#    #+#             */
/*   Updated: 2020/03/05 13:00:48 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*mover;
	size_t	i;

	mover = (char *)s;
	i = 0;
	while (i < n)
	{
		if (*mover == c)
			return (mover);
		mover++;
		i++;
	}
	return (NULL);
}
