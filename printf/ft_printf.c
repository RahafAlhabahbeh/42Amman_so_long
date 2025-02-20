/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-haba <ral-haba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:46:34 by ral-haba          #+#    #+#             */
/*   Updated: 2024/10/24 13:05:29 by ral-haba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(char f, va_list args)
{
	if (f == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (f == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (f == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (f == 'd' || f == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (f == 'u')
		return (ft_putnbr(va_arg(args, unsigned int)));
	else if (f == 'x' || f == 'X')
		return (ft_putnbr_hexa(va_arg(args, unsigned long), f));
	else if (f == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	va;
	int		count;
	int		i;

	if (!format)
		return (0);
	count = 0;
	i = 0;
	va_start(va, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_format(format[i + 1], va);
			i++;
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(va);
	return (count);
}

/*int main()
{
	int res = printf("name %s, first char %c\n", "rahaf", 'R');
	printf("%d", res);
	int lut = ft_printf("name %s, first char %c\n", "rahaf", 'R');
	ft_printf("%d", lut);

    int ret_ft, ret_std;

    // Test integers
    ret_ft = ft_printf("ft_printf: Testing integer: %d\n", 42);
    ret_std = printf("printf: Testing integer: %d\n", 42);
    ft_printf("ft_printf return value: %d\n", ret_ft);
    printf("printf return value: %d\n\n", ret_std);

    // Test unsigned integers
    ret_ft = ft_printf("ft_printf: Testing unsigned integer: %u\n", UINT_MAX);
    ret_std = printf("printf: Testing unsigned integer: %u\n", UINT_MAX);
    ft_printf("ft_printf return value: %d\n", ret_ft);
    printf("printf return value: %d\n\n", ret_std);

    // Test hexadecimal (lowercase)
    ret_ft = ft_printf("ft_printf: Testing hexadecimal (lowercase): %x\n", 255);
    ret_std = printf("printf: Testing hexadecimal (lowercase): %x\n", 255);
    ft_printf("ft_printf return value: %d\n", ret_ft);
    printf("printf return value: %d\n\n", ret_std);

    // Test hexadecimal (uppercase)
    ret_ft = ft_printf("ft_printf: Testing hexadecimal (uppercase): %X\n", 255);
    ret_std = printf("printf: Testing hexadecimal (uppercase): %X\n", 255);
    ft_printf("ft_printf return value: %d\n", ret_ft);
    printf("printf return value: %d\n\n", ret_std);

    // Test character
    ret_ft = ft_printf("ft_printf: Testing character: %c\n", 'A');
    ret_std = printf("printf: Testing character: %c\n", 'A');
    ft_printf("ft_printf return value: %d\n", ret_ft);
    printf("printf return value: %d\n\n", ret_std);

    // Test string
    ret_ft = ft_printf("ft_printf: Testing string: %s\n", "Hello, World!");
    ret_std = printf("printf: Testing string: %s\n", "Hello, World!");
    ft_printf("ft_printf return value: %d\n", ret_ft);
    printf("printf return value: %d\n\n", ret_std);

    // Test pointer
    int num = 123;
    ret_ft = ft_printf("ft_printf: Testing pointer: %p\n", &num);
    ret_std = printf("printf: Testing pointer: %p\n", &num);
    ft_printf("ft_printf return value: %d\n", ret_ft);
    printf("printf return value: %d\n\n", ret_std);

    // Test percentage
    ret_ft = ft_printf("ft_printf: Testing percentage: %%\n");
    ret_std = printf("printf: Testing percentage: %%\n");
    ft_printf("ft_printf return value: %d\n", ret_ft);
    printf("printf return value: %d\n\n", ret_std);

    // Test negative numbers
    ret_ft = ft_printf("ft_printf: Testing negative integer: %d\n", -42);
    ret_std = printf("printf: Testing negative integer: %d\n", -42);
    ft_printf("ft_printf return value: %d\n", ret_ft);
    printf("printf return value: %d\n\n", ret_std);

    // Test zero
    ret_ft = ft_printf("ft_printf: Testing zero: %d\n", 0);
    ret_std = printf("printf: Testing zero: %d\n", 0);
    ft_printf("ft_printf return value: %d\n", ret_ft);
    printf("printf return value: %d\n\n", ret_std);

    return 0;
}
*/
