/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 21:07:01 by taehkim           #+#    #+#             */
/*   Updated: 2020/09/17 21:07:02 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_splited(char ***splited)
{
	int		i;

	i = 0;
	while ((*splited)[i])
	{
		if ((*splited)[i])
			free((*splited)[i]);
		(*splited)[i] = NULL;
		i++;
	}
	if (*splited)
		free(*splited);
	*splited = NULL;
}

void	free_line(char **line)
{
	if (*line)
		free(*line);
	*line = NULL;
}
