/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-haba <ral-haba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:16:37 by ral-haba          #+#    #+#             */
/*   Updated: 2024/10/24 13:39:44 by ral-haba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hexa(unsigned int n, char c)
{
	int		j;
	int		count;
	char	arr[16];
	char	*base;

	j = 0;
	count = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n == 0)
		return (ft_putchar('0'));
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
