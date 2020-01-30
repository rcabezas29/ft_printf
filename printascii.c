/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 16:41:23 by rcabezas          #+#    #+#             */
/*   Updated: 2020/01/30 17:17:01 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	ft_putpads(t_struct *ps, int less, int arglen)
{
	int	i;
	int	widthlen;

	i = 0;
	if (ps->width > 0 && ps->precision > 0)
	{
		if (ps->precision >= ps->width)
			widthlen = ps->width - arglen;			
		else
		{
			if (arglen >= ps->width)
				widthlen = ps->width - ps->precision;
			else if (ps->precision < arglen)
				widthlen = ps->width - ps->precision;
			else
				widthlen = ps->width - arglen;
		}
	}
	else if (ps->precision == 0 && ps->width != 0)
		widthlen = ps->width - arglen;
	else
		widthlen = 0;
	if (ps->precision == -1)
		widthlen += ps->width;
	if (ps->width != 0 && ((less == 0 && ps->flags[2] == 1) ||
				(less != 0 && ps->flags[2] != 1)))
	{
		while (++i <= widthlen)
			ft_putchar(' ');
		ps->ret += i - 1;
	}
}

void		ft_printchar(t_struct *ps, char arg)
{
	int	i;
	int j;

	j = 0;
	i = 0;
	if (ps->width != 0 || ps->precision != 0)
		ft_putpads(ps, 1, 1);
	ft_putchar((char)arg);
	if (ps->width != 0 && ps->flags[2] == 1)
		ft_putpads(ps, 0, 1);
	if (ps->width < 0)
	{
		while (--j > ps->width)
		{
			ft_putchar(' ');
			ps->ret++;
		}
	}
	ps->ret += 1;
}

void		ft_printstr(t_struct *ps, char *arg)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	if (!arg)
		arg = "(null)";
	if (ps->width > 0 || ps->precision > 0)
		ft_putpads(ps, 1, ft_strlen(arg));
	if (ps->precision != 0 && ps->precision != -1)
	{
		while (i < ps->precision && arg[i])
			ft_putchar(arg[i++]);
		while (j > ps->precision && arg[i])
			ft_putchar(arg[i++]);
		ps->ret += i;
	}
	else if (ps->precision != -1)
	{
		ft_putstr(arg);
		ps->ret += ft_strlen(arg);
	}
	if (ps->width < 0 && ps->precision < 0 && ps->width < ps->precision)
	{
		while (j++ < (-1*(ps->width) - (int)ft_strlen((const char *)arg)))
		{
			ft_putchar(' ');
			ps->ret++;
		}
	}
	if (ps->width != 0 && ps->flags[2] == 1)
		ft_putpads(ps, 0, ft_strlen(arg));
	if (ps->width < 0 && ps->precision == 0)
	{
		while(j-- > ps->width + (int)ft_strlen((const char *)arg))
		{
			ft_putchar(' ');
			ps->ret++;
		}
	}
}
