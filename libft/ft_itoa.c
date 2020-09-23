/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 20:43:49 by taehkim           #+#    #+#             */
/*   Updated: 2020/04/07 17:34:36 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*dec_to_a(long n, int size, int is_minus)
{
	char	*output;

	output = malloc(sizeof(char) * (size + is_minus + 1));
	if (!output)
		return (NULL);
	if (is_minus)
		output[0] = '-';
	output[size + is_minus] = '\0';
	while (--size + is_minus >= is_minus)
	{
		output[size + is_minus] = (n % 10) + '0';
		n = n / 10;
	}
	return (output);
}

char	*ft_itoa(int n)
{
	int		is_minus;
	int		size;
	long	temp;
	long	arg;

	temp = n;
	arg = n;
	is_minus = 0;
	if (temp < 0)
	{
		arg = -arg;
		temp = -temp;
		is_minus = 1;
	}
	size = 0;
	while (temp)
	{
		size++;
		temp = temp / 10;
	}
	if (!size)
		size++;
	return (dec_to_a(arg, size, is_minus));
}
