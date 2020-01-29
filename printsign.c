/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printsign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:31:33 by rcabezas          #+#    #+#             */
/*   Updated: 2020/01/29 20:28:39 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	ft_putlnbr(long long int n, t_struct *ps)
{
	if (n > 9)
		ft_putlnbr(n / 10, ps);
	ft_putchar(n % 10 + '0');
}

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
	if (ps->flags[3] == 1 || ps->flags[4] == 1)
		widthlen -= 1;
	if (ps->precision == -1)
		widthlen += arglen;
	preclen = ps->precision > arglen ? ps->precision - arglen : 0;
	if (ps->width && ((!less && ps->flags[2] == 1) ||
				(less && ps->flags[2] != 1)))
	{
		while (++i <= widthlen - preclen)
		{
			if (ps->precision == 0)
				ft_putchar(ps->flags[1] == 1 && ps->flags[2] != 1 ? '0' : ' ');
			else
				ft_putchar(' ');		}
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

void		ft_printsgn(t_struct *ps, long long int arg)
{
	size_t	arglen;
	int i;
	
	i = 0;
	arglen = ft_nbrlen(arg);
	if (ps->flags[3] == 1 && ps->flags[1] == 1)
		ft_putchar('+');
	else if (ps->flags[4] == 1 && ps->flags[3] != 1)
	{
		ft_putchar(' ');
		ps->ret++;
	}
	if (ps->width > 0)
		ft_putwidth(ps, 1, arglen);
	if (ps->flags[3] == 1 && ps->flags[1] != 1)
		ft_putchar('+');
	if (ps->precision > 0)
		ft_putprec(ps, arglen);
	if (!(ps->precision == -1 && arg == 0))
	{
		ft_putlnbr(arg, ps);
		ps->ret += arglen;
	}
	if (ps->width > 0)
		ft_putwidth(ps, 0, arglen);
	if (ps->width < 0)
	{
		while(i++ < (-1 * ps->width) - ft_nbrlen(arg))
		{
			ft_putchar(' ');
			ps->ret++;
		}
	}
}

