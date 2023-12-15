/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoehn-h <skoehn-h@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:23:39 by skoehn-h          #+#    #+#             */
/*   Updated: 2023/12/15 18:24:03 by skoehn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int len)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		len += 11;
		return (len);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		len++;
	}
	if (n > 9)
	{
		len = ft_putnbr(n / 10, len);
		len = ft_putnbr(n % 10, len);
	}
	else
	{
		n += '0';
		write(1, &n, 1);
		len++;
	}
	return (len);
}

int	ft_putunbr(unsigned int n, int len)
{
	if (n > 9)
	{
		len = ft_putnbr(n / 10, len);
		len = ft_putnbr(n % 10, len);
	}
	else
	{
		n += '0';
		write(1, &n, 1);
		len ++;
	}
	return (len);
}
