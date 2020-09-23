/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:31:33 by taehkim           #+#    #+#             */
/*   Updated: 2020/04/25 06:15:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*mover;

	if (*lst == 0)
	{
		*lst = new;
		(*lst)->next = 0;
	}
	else
	{
		mover = ft_lstlast(*lst);
		mover->next = new;
		mover->next->next = 0;
	}
}
