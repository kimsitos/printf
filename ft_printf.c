/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stcozaci <stcozaci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:44:29 by stcozaci          #+#    #+#             */
/*   Updated: 2025/10/22 22:33:18 by stcozaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(char const *str, ...)
{
	va_list	arg;
	int		i;

	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
				write(1, "%", 1);
			else if (str[i + 1] == 'c')
				ft_putchar_fd((char)va_arg(arg, int), 1);
			else if (str[i + 1] == 's')
				ft_putstr_fd(va_arg(arg, char *), 1);
			else if (str[i + 1] == ('d' || 'i'))
				ft_putnbr_fd(va_arg(arg, int), 1);
			//else if
			i += 2;
		}
		write (1, &str[i], 1);
		i++;
	}
	return (0);
}

/*#include <stdio.h>

int main(void)
{
	//printf("hello %");
    ft_printf("hello%hoy\n");
    return 0;
}*/
