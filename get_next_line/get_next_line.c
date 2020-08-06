/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <taehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 23:01:52 by taehkim           #+#    #+#             */
/*   Updated: 2020/08/06 14:14:32 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen_gnl(char *s)
{
	int				count;

	count = 0;
	if (!s)
		return (0);
	while (s[count])
		count++;
	return (count);
}

int		ft_reading(int fd, char **src)
{
	char			buf[1024 + 1];
	int				temp;

	while ((temp = read(fd, buf, 1024)) > 0)
	{
		buf[temp] = '\0';
		ft_strcat(src, buf, temp, 0);
		if (ft_has_new_line(buf))
			break ;
	}
	if (temp == -1)
		return (-1);
	if (temp == 0 && !*src)
		return (0);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char		*src;
	int				temp;
	int				retcode;

	retcode = 1;
	if (!src || (src && !ft_has_new_line(src)))
		retcode = ft_reading(fd, &src);
	if (retcode == -1 || line == NULL)
		return (-1);
	if (retcode == 0 || !ft_has_new_line(src))
	{
		temp = ft_strlen_gnl(src);
		*line = ft_strndup(src, temp);
		if (src)
			free(src);
		src = NULL;
		return (0);
	}
	temp = ft_get_next_size(src);
	*line = ft_strndup(src, temp);
	ft_src_set(&src, temp + 1);
	return (retcode);
}
