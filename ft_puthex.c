/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stcozaci <stcozaci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:12:50 by stcozaci          #+#    #+#             */
/*   Updated: 2025/10/27 12:09:50 by stcozaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putp(void *addr)
{
	int					len;
	unsigned long long	nb;

	len = 0;
	nb = (unsigned long long) addr;
	len += write(1, "0x", 2);
	len += ft_puthex(nb, "0123456789abcdef");
	return (len);
}

int	ft_puthex(unsigned long long nb, char *strhex)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += ft_puthex(nb / 16, strhex);
		len += ft_puthex(nb % 16, strhex);
	}
	else
		len += write (1, &strhex[nb], 1);
	return (len);
}
