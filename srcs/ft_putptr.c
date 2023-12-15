/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoehn-h <skoehn-h@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:19:36 by skoehn-h          #+#    #+#             */
/*   Updated: 2023/12/13 16:19:36 by skoehn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putptr_hex(unsigned long long n, int len)
{
	if (n < 16)
	{
		if (n <= 9)
		{
			ft_putchar(n + '0');
			len++;
			return (len);
		}
		else if (n > 9)
		{
			ft_putchar(n - 10 + 'a');
			len++;
			return (len);
		}
	}
	else
	{
		len = putptr_hex(n / 16, len);
		len = putptr_hex(n % 16, len);
	}
}

int	ft_putptr(void *ptr, int len)
{
	unsigned long long	n;

	n = (unsigned long long) ptr;
	len = ft_putstr("0x", len);
	len = putptr_hex(n, len);
	return (len);
}
