/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <taehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 09:46:48 by taehkim           #+#    #+#             */
/*   Updated: 2020/04/04 20:51:55 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*copy;
	int		size;
	int		i;

	size = 0;
	while (s[size])
		size++;
	copy = (char *)malloc(sizeof(char) * (size + 1));
	if (!copy)
		return (0);
	copy[size] = 0;
	i = 0;
	while (i < size)
	{
		copy[i] = f(i, s[i]);
		i++;
	}
	return (copy);
}
