/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <taehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 07:20:21 by taehkim           #+#    #+#             */
/*   Updated: 2020/04/06 15:02:22 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*mover;

	mover = *lst;
	while (*lst)
	{
		del((*lst)->content);
		mover = *lst;
		*lst = (*lst)->next;
		free(mover);
	}
}
