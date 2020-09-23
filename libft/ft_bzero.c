/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <taehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:38:13 by taehkim           #+#    #+#             */
/*   Updated: 2020/03/05 12:58:17 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*mover;
	size_t	i;

	mover = (char *)s;
	i = 0;
	while (i < n)
	{
		*mover = 0;
		i++;
		mover++;
	}
}
