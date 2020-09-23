/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <taehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:15:03 by taehkim           #+#    #+#             */
/*   Updated: 2020/03/05 14:03:11 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*mover;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(s);
	mover = (char *)s;
	while (i <= size)
	{
		if (*mover == c)
			return (mover);
		mover++;
		i++;
	}
	return (0);
}
