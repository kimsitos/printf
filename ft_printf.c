/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stcozaci <stcozaci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:44:29 by stcozaci          #+#    #+#             */
/*   Updated: 2025/10/28 13:19:06 by stcozaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conversion(va_list arg, char funct)
{
	int	len;

	len = 0;
	if (funct == '%')
		len += write(1, "%", 1);
	else if (funct == 'c')
		len += ft_putchar((char)va_arg(arg, int));
	else if (funct == 's')
		len += ft_putstr(va_arg(arg, char *));
	else if (funct == 'p')
		len += ft_putp(va_arg(arg, void *));
	else if (funct == 'd' || funct == 'i')
		len += ft_putnbr(va_arg(arg, int));
	else if (funct == 'u')
		len += ft_putunsign(va_arg(arg, unsigned int));
	else if (funct == 'x')
		len += ft_puthex(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (funct == 'X')
		len += ft_puthex(va_arg(arg, unsigned int), "0123456789ABCDEF");
	return (len);
}

int	ft_printf(char const *str, ...)
{
	va_list	arg;
	int		i;
	int		len;

	va_start(arg, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			len += ft_conversion(arg, str[i + 1]);
			i += 2;
		}
		else
		{
			len += write (1, &str[i], 1);
			i++;
		}
	}
	va_end(arg);
	return (len);
}
