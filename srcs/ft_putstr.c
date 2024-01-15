/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoehn-h <skoehn-h@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:27:01 by skoehn-h          #+#    #+#             */
/*   Updated: 2024/01/08 15:58:14 by skoehn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *s, int len)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		ft_putstr("(null)", len);
		return (len + 6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	len += i;
	return (len);
}
