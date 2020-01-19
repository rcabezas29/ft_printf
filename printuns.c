/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printuns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:05:30 by rcabezas          #+#    #+#             */
/*   Updated: 2020/01/10 18:05:32 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putwidth(t_struct *ps, int less, int arglen)
{
	int	i;
	int	widthlen;
	int	preclen;

	i = 0;
	widthlen = (ps->width - (ps->precision == -1 ? 0 : arglen)) -
		(ps->flags[0] && ps->conversion != 'u' ? 1 : 0);
	preclen = ps->precision > arglen ? ps->precision - arglen : 0;
	if (ps->flags[0])
		widthlen -= ps->conversion == 'x' || ps->conversion == 'X' ? 1 : 0;
	if (ps->width && ((!less && ps->flags[2]) ||
				(less && !ps->flags[2])))
	{
		while (++i <= widthlen - preclen)
			ft_putchar(ps->flags[1] && !ps->flags[2] ? '0' : ' ');
		ps->ret += i - 1;
	}
}

static void	ft_putprec(t_struct *ps, int arglen)
{
	int	i;
	int	preclen;

	i = 0;
	preclen = ps->precision > arglen ? ps->precision - arglen : 0;
	if (ps->precision)
	{
		while (++i <= preclen)
			ft_putchar('0');
		ps->ret += i - 1;
	}
}

static void	ft_printhex(t_struct *ps, unsigned long long arg)
{
	if (ps->flags[0] && arg && ps->flags[1])
		ft_putsharp(ps);
	if (ps->width)
		ft_putwidth(ps, 1, ft_nbrlen_base(arg, "0123456789abcdef"));
	if (ps->flags[0] && arg && !ps->flags[1] && ps->precision)
		ft_putsharp(ps);
	if (ps->precision)
		ft_putprec(ps, ft_nbrlen_base(arg, "0123456789abcdef"));
	if (ps->flags[0] && arg && !ps->flags[1] && !ps->precision)
		ft_putsharp(ps);
	if (ps->precision != -1)
		ps->ret += ft_nbrlen_base(arg, "0123456789abcdef");
	if (ps->conversion == 'x' && ps->precision != -1)
		ft_putnbr_base(arg, "0123456789abcdef");
	else if (ps->conversion == 'X' && ps->precision != -1)
		ft_putnbr_base(arg, "0123456789ABCDEF");
	if (ps->flags[2])
		ft_putwidth(ps, 0, ft_nbrlen_base(arg, "0123456789abcdef"));
}

void		ft_printuns(t_struct *ps, unsigned long long arg)
{
	if (ps->conversion == 'x' || ps->conversion == 'X')
		ft_printhex(ps, arg);
	if (ps->conversion == 'u')
	{
		if (ps->width)
			ft_putwidth(ps, 1, ft_nbrlen(arg));
		if (ps->precision)
			ft_putprec(ps, ft_nbrlen(arg));
		if (!(ps->precision == -1 && arg == 0))
		{
			if (arg == 4294967295 || (long long)arg < 0)
				ps->ret += 20;
			else
				ps->ret += ft_nbrlen(arg);
			ft_putulnbr(arg);
		}
		if (ps->flags[2])
			ft_putwidth(ps, 0, ft_nbrlen(arg));
	}
}

