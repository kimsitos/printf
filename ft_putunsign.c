/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stcozaci <stcozaci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:43:34 by stcozaci          #+#    #+#             */
/*   Updated: 2025/10/24 16:59:11 by stcozaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsign(unsigned int n)
{
	char	x;
	int		len;

	len = 0;
	if (n > 9)
	{
		len += ft_putunsign(n / 10);
		len += ft_putunsign(n % 10);
	}
	else
	{
		x = n + '0';
		len += write(1, &x, 1);
	}
	return (len);
}
