/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-haba <ral-haba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:18:04 by ral-haba          #+#    #+#             */
/*   Updated: 2024/10/19 16:53:51 by ral-haba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str1)
{
	int	len;

	if (!str1)
	{
		if (write (1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	len = 0;
	while (*str1 != '\0')
	{
		if (write(1, str1, 1) == -1)
			return (-1);
		len++;
		str1++;
	}
	return (len);
}
