/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <taehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:28:09 by taehkim           #+#    #+#             */
/*   Updated: 2020/04/07 21:43:08 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*mover;

	mover = lst;
	if (!mover)
		return (NULL);
	while (1)
	{
		if (mover->next == NULL)
			break ;
		mover = mover->next;
	}
	return (mover);
}
