/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnegsign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:21:13 by rcabezas          #+#    #+#             */
/*   Updated: 2020/01/10 17:21:26 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putlnbr(long long int n)
{
	if (n <= LONG_MIN)
	{
		ft_putstr("9223372036854775808");
		return ;
	}
	if (n < 0)
		n = -n;
	if (n > 9)
		ft_putlnbr(n / 10);
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
	if (ps->flags[4])
		widthlen -= 1;
	if (ps->precision == -1)
		widthlen += arglen;
	preclen = ps->precision > arglen ? ps->precision - arglen + 1 : 0;
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
	preclen = ps->precision > arglen ? ps->precision - arglen + 1 : 0;
	if (ps->precision)
	{
		while (++i <= preclen)
			ft_putchar('0');
		ps->ret += i - 1;
	}
}

void		ft_printsgn_neg(t_struct *ps, long long int arg)
{
	size_t	arglen;

	arglen = ft_nbrlen(arg);
	if (arg <= LONG_MIN)
		ps->ret += 18;
	if (ps->flags[1])
		ft_putchar('-');
	if (ps->width)
		ft_putwidth(ps, 1, arglen);
	if (!ps->flags[1] && ps->precision > (int)arglen)
		ft_putchar('-');
	if (ps->precision)
		ft_putprec(ps, arglen);
	if (!ps->flags[1] && ps->precision <= (int)arglen)
		ft_putchar('-');
	if (ps->precision != -1)
	{
		ps->ret += arglen;
		ft_putlnbr(arg);
	}
	if (ps->flags[2])
		ft_putwidth(ps, 0, arglen);
}

