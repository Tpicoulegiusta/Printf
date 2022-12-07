/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function2nd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:18:37 by tpicoule          #+#    #+#             */
/*   Updated: 2022/12/07 16:01:09 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putnbrexa(unsigned int n)
{
	int		i;
	char	*base;

	base = "0123456789abcdef";
	i = 0;
	if (n >= 16)
	{
		i += ft_putnbrexa(n / 16);
		i += ft_putnbrexa(n % 16);
	}
	if (n < 16)
		i += ft_putchar(base[n]);
	return (i);
}

int	ft_putnbrexa2(unsigned int n)
{
	int		i;
	char	*base;

	base = "0123456789ABCDEF";
	i = 0;
	if (n >= 16)
	{
		i += ft_putnbrexa2(n / 16);
		i += ft_putnbrexa2(n % 16);
	}
	if (n < 16)
		i += ft_putchar(base[n]);
	return (i);
}

int	ft_putnbrexap(unsigned long long n)
{
	int		i;
	char	*base;

	/*if (n == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}*/
	base = "0123456789abcdef";
	i = 0;
	if (n > 16)
	{
		i += ft_putnbrexap(n / 16);
		i += ft_putnbrexap(n % 16);
	}
	if (n <= 16)
		i += ft_putchar(base[n]);
	return (i);
}
