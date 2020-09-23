/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <taehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:42:40 by taehkim           #+#    #+#             */
/*   Updated: 2020/04/06 11:33:30 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char	*s1mover;
	char	*s2mover;
	size_t	i;

	s1mover = (char *)s1;
	s2mover = (char *)s2;
	i = 0;
	while (i < n && (*s1mover || *s2mover))
	{
		if (*s1mover != *s2mover)
			return ((unsigned char)*s1mover - (unsigned char)*s2mover);
		s1mover++;
		s2mover++;
		i++;
	}
	return (0);
}
