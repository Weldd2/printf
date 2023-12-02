/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:38:37 by antoinemura       #+#    #+#             */
/*   Updated: 2023/12/02 16:44:00 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_d_i(va_list *ap)
{
	int	d;

	d = va_arg(*ap, int);
	ft_putnbr(d);
}

void	ft_handle_c(va_list *ap)
{
	char	c;

	c = va_arg(*ap, int);
	ft_putchar(c);
}

void	ft_handle_s(va_list *ap)
{
	char	*s;

	s = va_arg(*ap, char *);
	ft_putstring(s);
}

void	ft_handle_p(va_list *ap)
{
	void	*p;

	p = va_arg(*ap, void *);
	ft_printaddr(p);
}

void	ft_handle_x(va_list *ap)
{
	int	s;

	s = va_arg(*ap, int);
	ft_putnbr_base(s, "0123456789abcdef");
}
