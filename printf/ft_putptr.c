/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-haba <ral-haba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:03:22 by ral-haba          #+#    #+#             */
/*   Updated: 2024/10/24 16:27:26 by ral-haba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
static int	len(unsigned long nb)
{
	int	count;

	count = 0;
	while (nb != 0)
	{
		count++;
		nb /= 16;
	}
	return (count);
}*/

int	ft_putptr(void *ptr)
{
	char			arr[16];
	char			*base;
	unsigned long	n;
	int				j;
	int				count;

	j = 0;
	n = (unsigned long) ptr;
	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	count = ft_putstr("0x");
	base = "0123456789abcdef";
	while (n != 0)
	{
		arr[j++] = base[n % 16];
		n /= 16;
		count ++;
	}
	while (--j >= 0)
		ft_putchar(arr[j]);
	return (count);
}
