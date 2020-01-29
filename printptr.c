/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:16:23 by rcabezas          #+#    #+#             */
/*   Updated: 2020/01/29 20:49:22 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putwidth(t_struct *ps, int less, int arglen)
{
	int	i;
	int	widthlen;
//	printf("ARGLEN: %i\n", arglen);

	i = 0;
	widthlen = ps->width - arglen;
	if (ps->width != 0 && ((less == 0 && ps->flags[2] == 1) ||
				(less > 0 && ps->flags[2] != 1)))
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

void		ft_printptr(t_struct *ps, intptr_t arg)
{
	/*
	printf("PTR: %lu\n", arg);
	printf("PRECISION: %i\n", ps->precision);
	printf("WIDTH: %i\n", ps->width);
	*/
	if (ps->width != 0)
		ft_putwidth(ps, 1, ft_nbrlen_base(arg, "0123456789abcdef") + 2);
	ft_putstr("0x");
	ps->ret += 2;
	if (ps->precision != 0)
		ft_putprec(ps, ft_nbrlen_base(arg, "0123456789abcdef"));
	if (ps->precision != -1)
	{
		ps->ret += ft_nbrlen_base(arg, "0123456789abcdef");
		ft_putnbr_base(arg, "0123456789abcdef");
	}
	if (ps->width != 0 && ps->flags[2] == 1)
		ft_putwidth(ps, 0, ft_nbrlen_base(arg, "0123456789abcdef") + 2);
}

