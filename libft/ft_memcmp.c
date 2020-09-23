/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <taehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 14:53:19 by taehkim           #+#    #+#             */
/*   Updated: 2020/04/06 13:58:50 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*s1mover;
	char	*s2mover;

	s1mover = (char *)s1;
	s2mover = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (*s1mover != *s2mover)
		{
			return ((unsigned char)*s1mover -
					(unsigned char)*s2mover);
		}
		s1mover++;
		s2mover++;
		i++;
	}
	return (0);
}
