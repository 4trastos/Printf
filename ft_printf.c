/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:15:28 by davgalle          #+#    #+#             */
/*   Updated: 2023/11/03 20:22:09 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_whattype(char c, va_list args, int *nb)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), nb);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), nb);
	else if (c == 'p')
	{
		ft_putstr("0x", nb);
		ft_hexa(va_arg(args, unsigned long long), "0123456789abcdef", nb);
	}
	else if (c == 'd')
		ft_putnbr(va_arg(args, int), nb);
	else if (c == 'i')
		ft_putnbr(va_arg(args, int), nb);
	else if (c == 'u')
		ft_putunsign(va_arg(args, unsigned int), nb);
	else if (c == 'x')
		ft_hexa(va_arg(args, unsigned int), "0123456789abcdef", nb);
	else if (c == 'X')
		ft_hexa(va_arg(args, unsigned int), "0123456789ABCDEF", nb);
	else if (c == '%')
		ft_putchar('%', nb);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			ft_whattype(format[i + 1], args, &count);
		}
		else
			ft_putchar(format[i], &count);
		i++;
	}
	va_end(args);
	return (count);
}
/*
int	main(void)
{
	char test_character = 'z';
	char test[] = "printea el test2";
	int	test_void = 123456789;
	int	test_dec = -123456789;
	int	test_int = 123456789;
	unsigned int test_u = -131313;
	int test_x = 435353435;
	int	test_X = 61;
	char	test_percent = '%';
		
	ft_printf("%");
	ft_printf(": %u\n", ft_printf("%c", test_character));
	ft_printf(": %u\n", ft_printf("%s", test));
	ft_printf(": %u\n", ft_printf("%p", test_void));
	ft_printf(": %u\n", ft_printf("%d", test_dec));
	ft_printf(": %u\n", ft_printf("%i", test_int));
	ft_printf(": %u\n", ft_printf("%u", test_u));
	ft_printf(": %u\n", ft_printf("%x", test_x));
	ft_printf(": %u\n", ft_printf("%X", test_X));
	ft_printf(": %u\n", ft_printf("%%", test_percent));
	ft_printf(": %u\n", ft_printf("printea la string sin arg"));

	return (0);
}*/
