/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printbinary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:04:37 by rcabezas          #+#    #+#             */
/*   Updated: 2020/01/10 17:04:40 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putwidth(t_struct *ps, int less, int arglen)
{
	int	i;
	int	widthlen;
	int	preclen;

	i = 0;
	if (ps->precision > 0 && ps->precision < arglen && ps->precision > (int)ps->width)
		widthlen = ps->width - ps->precision;
	else
		widthlen = ps->width - arglen;
	if (ps->flags[3] || ps->flags[4])
		widthlen -= ps->flags[3] + ps->flags[4];
	if (ps->precision == -1)
		widthlen += arglen;
	preclen = ps->precision > arglen ? ps->precision - arglen : 0;
	if (ps->width && ((!less && ps->flags[2]) ||
				(less && !ps->flags[2])))
	{
		while (++i <= widthlen - preclen)
			ft_putchar(ps->flags[1] && !ps->flags[2] && !preclen ? '0' : ' ');
	    ps->ret += i - 1;
	}
}

static void	ft_putprec(t_struct *ps, int arglen)
{
	int	i;
	int	preclen;

	i = 0;
	preclen = (ps->precision > arglen ? ps->precision - arglen : 0);
	if (ps->precision)
	{
		while (++i <= preclen)
			ft_putchar('0');
		ps->ret += i - 1;
	}
}

void		ft_printbin(t_struct *ps, unsigned long long arg)
{
	if (ps->width)
		ft_putwidth(ps, 1, ft_nbrlen_base(arg, "01"));
	if (ps->precision)
		ft_putprec(ps, ft_nbrlen_base(arg, "01"));
	if (ps->precision != -1)
	{
		ps->ret += ft_nbrlen_base(arg, "01");
		ft_putnbr_base(arg, "01");
	}
	if (ps->flags[2])
		ft_putwidth(ps, 0, ft_nbrlen_base(arg, "01"));
}
