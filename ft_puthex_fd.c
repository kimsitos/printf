/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stcozaci <stcozaci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:12:50 by stcozaci          #+#    #+#             */
/*   Updated: 2025/10/23 14:33:47 by stcozaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_fd(int nb, int fd, char *strhex)
{
	int	nhex;

	nhex = 0;
	if (nb == -2147483648)
	{
		write (fd, "-80000000", 9);
		return ;
	}
	if (nb < 0)
	{
		nb *= -1;
		write (fd, "-", 1);
	}
	if (nb >= 16)
	{
		ft_puthex_fd(nb / 16, fd, strhex);
		ft_puthex_fd(nb % 16, fd, strhex);
	}
	else
		write (fd, &strhex[nb], 1);
}

// #include <stdio.h>

// int main(void)
// {
// 	ft_puthex_fd(-2147483648, 1, "0123456789abcdef");
// 	return 0;
// }