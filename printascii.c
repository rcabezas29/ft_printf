/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 16:41:23 by rcabezas          #+#    #+#             */
/*   Updated: 2020/01/23 20:08:35 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	ft_putpads(t_struct *ps, int less, int arglen)
{
	int	i;
	int	widthlen;

	i = 0;
	if (ps->precision > 0 && ps->precision < arglen)
	{
		widthlen = ps->width - ps->precision;
	}
	else
		widthlen = ps->width - arglen;
	if (ps->precision == -1)
		widthlen += arglen;
	if (ps->width && ((!less && ps->flags[2] == 1) ||
				(less && ps->flags[2] != 1)))
	{
		while (++i <= widthlen)
			ft_putchar(' ');
		ps->ret += i - 1;
	}
}

void		ft_printchar(t_struct *ps, char arg)
{
	int	i;

	i = 0;
	if (ps->width || ps->precision)
		ft_putpads(ps, 1, 1);
	ft_putchar((char)arg);
	if (ps->width && ps->flags[2] == 1)
		ft_putpads(ps, 0, 1);
	ps->ret += 1;
}

void		ft_printstr(t_struct *ps, char *arg)
{
	int	i;

	i = 0;
	printf("Precision = %i\n", ps->precision);
	printf("Width = %i\n", ps->width);
	if (!arg)
		arg = "(null)";
	if (ps->width || ps->precision)
		ft_putpads(ps, 1, ft_strlen(arg));
	if (ps->precision != 0 && ps->precision != -1)
	{
		while (i < ps->precision && arg[i])
			ft_putchar(arg[i++]);
		ps->ret += i;
	}
	else if (ps->precision != -1)
	{
		ft_putstr(arg);
		ps->ret += ft_strlen(arg);
	}
	if (ps->width && ps->flags[2] == 1)
		ft_putpads(ps, 0, ft_strlen(arg));
}
