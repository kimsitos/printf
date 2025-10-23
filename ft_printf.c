/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stcozaci <stcozaci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:44:29 by stcozaci          #+#    #+#             */
/*   Updated: 2025/10/23 14:40:31 by stcozaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*temsrc;
	char		*temdest;

	temsrc = (char *)src;
	temdest = (char *)dest;
	i = 0;
	if (!src && !dest)
		return (NULL);
	while (i < n)
	{
		temdest[i] = temsrc[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*temdest;
	unsigned const char	*temsrc;

	temdest = (unsigned char *)dest;
	temsrc = (unsigned char *)src;
	if (!src && !dest)
		return (NULL);
	if (temdest >= temsrc)
	{
		while (n--)
			temdest[n] = temsrc[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

static void	ft_put_nbr_nosign_fd(int nbr, int fd)
{
	if (nbr == -2147483648)
	{
		write (fd, "2147483648", 10);
		return ;
	}
	else if (nbr < 0)
		nbr *= -1;
	ft_putnbr_fd(nbr, fd);
}

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
			else if (str[i + 1] == 'p')
				ft_putstr_fd((char *)va_arg(arg, void *), 1);
			else if (str[i + 1] == 'd' || str[i + 1] == 'i')
				ft_putnbr_fd(va_arg(arg, int), 1);
			else if (str[i + 1] == 'u')
				ft_put_nbr_nosign_fd(va_arg(arg, int), 1);
			else if (str[i + 1] == 'x')
				ft_puthex_fd(va_arg(arg, int), 1, "0123456789abcdef");
			else if (str[i + 1] == 'X')
				ft_puthex_fd(va_arg(arg, int), 1, "0123456789ABCDEF");
			i += 2;
		}
		write (1, &str[i], 1);
		i++;
	}
	return (0);
}

int main(void)
{
    ft_printf("%p", ft_memmove("hello", "world", 5));
    return 0;
}
