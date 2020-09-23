/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:11:26 by taehkim           #+#    #+#             */
/*   Updated: 2020/04/30 16:18:15 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*output;
	size_t	i;

	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	output = (char *)malloc(sizeof(char) * (len + 1));
	if (!output)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		output[i] = s[start + i];
		i++;
	}
	output[i] = 0;
	return (output);
}
