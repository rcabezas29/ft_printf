/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:16:23 by rcabezas          #+#    #+#             */
/*   Updated: 2020/01/10 17:16:25 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putwidth(t_struct *ps, int less, int arglen)
{
	int	i;
	int	widthlen;

	i = 0;
	widthlen = ps->width - arglen;
	if (ps->width && ((!less && ps->flags[2]) ||
				(less && !ps->flags[2])))
	{
		while (++i <= widthlen)
			ft_putchar(' ');
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

void		ft_printptr(t_struct *ps, uintptr_t arg)
{
	if (ps->width)
		ft_putwidth(ps, 1, ft_nbrlen_base(arg, "0123456789abcdef") + 2);
	ft_putstr("0x");
	ps->ret += 2;
	if (ps->precision)
		ft_putprec(ps, ft_nbrlen_base(arg, "0123456789abcdef"));
	if (ps->precision != -1)
	{
		ps->ret += ft_nbrlen_base(arg, "0123456789abcdef");
		ft_putnbr_base(arg, "0123456789abcdef");
	}
	if (ps->width && ps->flags[2])
		ft_putwidth(ps, 0, ft_nbrlen_base(arg, "0123456789abcdef") + 2);
}

