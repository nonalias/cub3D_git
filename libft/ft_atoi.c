/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <taehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:38:32 by taehkim           #+#    #+#             */
/*   Updated: 2020/04/07 21:42:21 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

int		ft_c_to_dec(char *str, int size, int is_minus)
{
	long long	ret;
	long long	digit;

	ret = 0;
	digit = 1;
	while (size > 0)
	{
		if (size > 20 || ret + (digit * (str[size - 1] - '0')) < 0)
		{
			if (is_minus % 2 != 1)
				return (-1);
			return (0);
		}
		ret += digit * (str[size - 1] - '0');
		digit = digit * 10;
		size--;
	}
	if (is_minus % 2 == 1)
		ret = -ret;
	return (int)(ret);
}

int		ft_atoi(const char *nptr)
{
	int	realsize;
	int	is_minus;

	while (ft_isspace(*nptr))
		nptr++;
	is_minus = 0;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			is_minus++;
		nptr++;
	}
	realsize = 0;
	while (ft_isdigit(*nptr))
	{
		realsize++;
		nptr++;
	}
	if (realsize == 0)
		return (0);
	return (ft_c_to_dec((char*)nptr - realsize, realsize, is_minus));
}
