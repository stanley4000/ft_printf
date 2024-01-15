/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoehn-h <skoehn-h@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:25:05 by skoehn-h          #+#    #+#             */
/*   Updated: 2023/12/15 17:54:10 by skoehn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numeric(const char *s, va_list args, int len)
{
	int	is_cap;

	if (*s == 'i' || *s == 'd')
		len = ft_putnbr(va_arg(args, int), len);
	else if (*s == 'u')
		len = ft_putunbr(va_arg(args, unsigned int), len);
	else if (*s == 'p')
		len = ft_putptr(va_arg(args, void *), len);
	else if (*s == 'x' || *s == 'X')
	{
		is_cap = 0;
		if (*s == 'X')
			is_cap = 1;
		len = ft_puthex(va_arg(args, int), is_cap, len);
	}
	return (len);
}

static int	specifier(const char *s, va_list args, int len)
{
	s++;
	if (*s == 's')
		len = ft_putstr(va_arg(args, char *), len);
	else if (*s == 'c')
	{
		ft_putchar(va_arg(args, int));
		len ++;
	}
	else if (*s == '%')
	{
		ft_putchar('%');
		len ++;
	}
	else if (*s == 'i' || *s == 'd' || *s == 'u'
		|| *s == 'p' || *s == 'x' || *s == 'X')
		len = numeric(s, args, len);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		len;

	va_start(args, s);
	len = 0;
	while (*s)
	{
		if (*s != '%')
		{
			ft_putchar(*s);
			len ++;
		}
		else
		{
			len = specifier(s, args, len);
			s++;
		}
		s++;
	}
	va_end(args);
	return (len);
}
