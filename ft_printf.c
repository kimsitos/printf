/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stcozaci <stcozaci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:44:29 by stcozaci          #+#    #+#             */
/*   Updated: 2025/10/24 16:55:51 by stcozaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			if (str[i + 1] == '%')
				len += write(1, "%", 1);
			else if (str[i + 1] == 'c')
				len += ft_putchar((char)va_arg(arg, int));
			else if (str[i + 1] == 's')
				len += ft_putstr(va_arg(arg, char *));
			// else if (str[i + 1] == 'p')
			// 	len += ft_putstr(va_arg(arg, void *));
			else if (str[i + 1] == 'd' || str[i + 1] == 'i')
				len += ft_putnbr(va_arg(arg, int));
			else if (str[i + 1] == 'u')
				len += ft_putunsign(va_arg(arg, unsigned int));
			else if (str[i + 1] == 'x')
				len += ft_puthex(va_arg(arg, unsigned int), "0123456789abcdef");
			else if (str[i + 1] == 'X')
				len += ft_puthex(va_arg(arg, unsigned int), "0123456789ABCDEF");
			i += 2;
		}
		else
		{
			len += write (1, &str[i], 1);
			i++;
		}
	}
	return (len);
}

#include <stdio.h>

int main(void)
{
	//ft_printf("%s", "hola");
	ft_printf("%u", -1);
	return 0;
}