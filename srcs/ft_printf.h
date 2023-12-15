/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoehn-h <skoehn-h@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:18:44 by skoehn-h          #+#    #+#             */
/*   Updated: 2023/12/15 19:19:59 by skoehn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int			ft_putptr(void *p, int len);
int			ft_printf(const char *s, ...);
void		ft_putchar(char c);
int			ft_putnbr(int n, int len);
int			ft_putstr(char *s, int len);
int			ft_puthex(unsigned int hex, int is_cap, int len);
int			ft_putptr(void *p, int len);
int			ft_putunbr(unsigned int n, int len);

#endif
