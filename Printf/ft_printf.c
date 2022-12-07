/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:44:16 by tpicoule          #+#    #+#             */
/*   Updated: 2022/12/07 16:03:44 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_check(char str, va_list arg)
{
	int	i;

	i = 0;
	if (str == 'd' || str == 'i')
		i += ft_putnbr(va_arg(arg, int));
	if (str == 'c')
		i += ft_putchar(va_arg(arg, int));
	if (str == 's')
		i += ft_putstr(va_arg(arg, char *));
	if (str == 'p')
	{
		write (1, "0x", 2);
		i += 2;
		i += ft_putnbrexap(va_arg(arg, unsigned long long));
	}
	if (str == 'u')
		i += ft_putnbru(va_arg(arg, unsigned int));
	if (str == 'x')
		i += ft_putnbrexa(va_arg(arg, unsigned int));
	if (str == 'X')
		i += ft_putnbrexa2(va_arg(arg, unsigned int));
	if (str == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		j;

	j = 0;
	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			j += ft_check(str[i + 1], arg);
			i = i + 2;
		}
		else
		{
			j += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(arg);
	return (j);
}
/*
int	main ()
{
	//printf("count %d\n", printf("%p\n", ""));
	ft_printf("count %d\n", ft_printf("%p\n", ""));
}*/