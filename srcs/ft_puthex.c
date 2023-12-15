/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoehn-h <skoehn-h@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:13:37 by skoehn-h          #+#    #+#             */
/*   Updated: 2023/12/13 17:13:37 by skoehn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int hex, int is_cap, int len)
{
	if (hex < 16)
	{
		if (hex <= 9)
		{
			ft_putchar(hex + '0');
			len++;
		}
		else if (hex > 9 && !(is_cap))
		{
			ft_putchar(hex - 10 + 'a');
			len ++;
		}
		else if (hex > 9 && is_cap)
		{
			ft_putchar(hex - 10 + 'A');
			len ++;
		}
		return (len);
	}
	else
	{
		len = ft_puthex(hex / 16, is_cap, len);
		len = ft_puthex(hex % 16, is_cap, len);
	}
	return (len);
}
