/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stcozaci <stcozaci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:44:29 by stcozaci          #+#    #+#             */
/*   Updated: 2025/10/24 16:07:51 by stcozaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static int	ft_put_nbr_nosign(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr < 0)
		nbr *= -1;
	len += ft_putnbr(nbr);
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
			if (str[i + 1] == '%')
				len += write(1, "%", 1);
			else if (str[i + 1] == 'c')
				len += ft_putchar((char)va_arg(arg, int));
			else if (str[i + 1] == 's')
				len += ft_putstr(va_arg(arg, char *));
			else if (str[i + 1] == 'p')
				len += ft_putstr((char *)va_arg(arg, void *));
			else if (str[i + 1] == 'd' || str[i + 1] == 'i')
				len += ft_putnbr(va_arg(arg, int));
			else if (str[i + 1] == 'u')
				len += ft_put_nbr_nosign(va_arg(arg, unsigned int));
			else if (str[i + 1] == 'x')
				len += ft_puthex(va_arg(arg, long long), "0123456789abcdef");
			else if (str[i + 1] == 'X')
				len += ft_puthex(va_arg(arg, long), "0123456789ABCDEF");
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
	printf("%lx", -2147483648);
	return 0;
}