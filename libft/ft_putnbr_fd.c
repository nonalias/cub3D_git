/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <taehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:01:14 by taehkim           #+#    #+#             */
/*   Updated: 2020/03/06 20:11:20 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	long long	temp;

	temp = n;
	if (temp < 0)
	{
		write(fd, &"-"[0], 1);
		temp = -temp;
	}
	if (temp > 9)
		ft_putnbr_fd(temp / 10, fd);
	write(fd, &"0123456789"[temp % 10], 1);
}
