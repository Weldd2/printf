/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:37:48 by antoinemura       #+#    #+#             */
/*   Updated: 2023/12/09 18:36:40 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstring(char *s)
{
	int	count;

	count = 0;
	if (s == NULL)
		return (count);
	while (*s)
	{
		write(1, s, 1);
		count++;
		s++;
	}
	return (count);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int i)
{
	int	temp;
	int	count;

	temp = 0;
	count = 0;
	while (i >= 10)
	{
		count++;
		temp = (i % 10) + '0';
		write(1, &temp, 1);
		i /= 10;
	}
	temp = i + '0';
	count++;
	write(1, &temp, 1);
	return (count);
}

int	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;
	int	count;

	base_len = 0;
	count = 0;
	while (base[base_len])
		base_len++;
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= base_len)
	{
		count += ft_putnbr_base(nbr / base_len, base);
		count += ft_putnbr_base(nbr % base_len, base);
	}
	else
		count += ft_putchar(base[nbr]);
	return (count);
}

int	ft_printaddr(void *addr)
{
	ft_putchar('0');
	ft_putchar('x');
	return (2 + ft_putnbr_base((unsigned long)addr, "0123456789abcdef"));
}
