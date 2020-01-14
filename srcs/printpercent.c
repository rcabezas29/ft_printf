/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpercent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:12:19 by rcabezas          #+#    #+#             */
/*   Updated: 2020/01/10 17:12:23 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putpads(t_struct *ps, int less)
{
	int	i;
	int	widthlen;

	i = 0;
	widthlen = ps->width - 1;
	if (ps->width && ((less && ps->flags[2]) ||
				(!less && !ps->flags[2])))
	{
		while (++i <= widthlen)
			ft_putchar(ps->flags[1] ? '0' : ' ');
		ps->ret += i - 1;
	}
}

void		ft_printpercent(t_struct *ps)
{
	if (ps->width || ps->precision)
		ft_putpads(ps, 0);
	ps->ret++;
	ft_putchar('%');
	if (ps->flags[2])
		ft_putpads(ps, 1);
}
