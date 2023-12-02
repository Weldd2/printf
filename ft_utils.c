/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:37:48 by antoinemura       #+#    #+#             */
/*   Updated: 2023/12/02 16:44:07 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstring(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int i)
{
	int	temp;

	temp = 0;
	while (i >= 10)
	{
		temp = (i % 10) + '0';
		write(1, &temp, 1);
		i /= 10;
	}
	temp = i + '0';
	write(1, &temp, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= base_len)
	{
		ft_putnbr_base(nbr / base_len, base);
		ft_putnbr_base(nbr % base_len, base);
	}
	else
		ft_putchar(base[nbr]);
}

void	ft_printaddr(void *addr)
{
	ft_putchar('0');
	ft_putchar('x');
	ft_putnbr_base((unsigned long)addr, "0123456789abcdef");
}
