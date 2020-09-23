/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 07:26:42 by taehkim           #+#    #+#             */
/*   Updated: 2020/04/25 05:14:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*output;
	t_list	*temp;
	t_list	*mover;

	output = 0;
	while (lst)
	{
		if (!(temp = malloc(sizeof(t_list))))
		{
			while (output)
			{
				mover = output->next;
				del(output->content);
				free(output);
				output = mover;
			}
			return (0);
		}
		temp->content = f(lst->content);
		temp->next = 0;
		ft_lstadd_back(&output, temp);
		lst = lst->next;
	}
	return (output);
}
