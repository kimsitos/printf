/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stcozaci <stcozaci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:39:34 by stcozaci          #+#    #+#             */
/*   Updated: 2025/10/27 12:00:04 by stcozaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(char const *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putp(void *addr);
int	ft_putnbr(int n);
int	ft_putunsign(unsigned int nb);
int	ft_puthex(unsigned long long nb, char *strhex);
#endif
