/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:39:18 by antoinemura       #+#    #+#             */
/*   Updated: 2023/12/02 16:44:20 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

void	ft_putchar(char c);
void	ft_putnbr(int i);
void	ft_putnbr_base(int nbr, char *base);
void	ft_printaddr(void *addr);
void	ft_putstring(char *s);
void	ft_handle_x(va_list *ap);
void	ft_handle_p(va_list *ap);
void	ft_handle_s(va_list *ap);
void	ft_handle_c(va_list *ap);
void	ft_handle_d_i(va_list *ap);
void	ft_handle_x_upper(va_list *ap);
void	ft_handle_percent(void);
void	ft_initialize_handlers(void (*handlers[256])(va_list *));
int		ft_printf(const char *fmt, ...);
