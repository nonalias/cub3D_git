/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <taehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 15:35:21 by taehkim           #+#    #+#             */
/*   Updated: 2020/04/10 19:09:10 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	needlesize;

	if (needle[0] == '\0')
		return (char *)haystack;
	needlesize = ft_strlen(needle);
	i = 0;
	while (i < n && haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (i + j < n && haystack[i + j] && needle[j])
			{
				if (haystack[i + j] != needle[j])
					break ;
				j++;
			}
			if (j == needlesize)
				return (char *)haystack + i;
		}
		i++;
	}
	return (0);
}
