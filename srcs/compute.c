/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:33:14 by rcabezas          #+#    #+#             */
/*   Updated: 2020/02/09 12:49:09 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_castsgn(t_struct *ps, va_list ap)
{
	long long int	nb;

	nb = va_arg(ap, long long int);
	if (ps->modifier == 'H')
		nb = (signed char)nb;
	else if (ps->modifier == 'h')
		nb = (short int)nb;
	else if (ps->modifier == 'L')
		nb = (long long int)nb;
	else if (ps->modifier == 'l')
		nb = (long int)nb;
	else
		nb = (int)nb;
	if (nb < 0)
		ft_printsgn_neg(ps, nb);
	else
		ft_printsgn(ps, nb);
}

static void	ft_castuns(t_struct *ps, va_list ap)
{
	unsigned long long int	nb;

	nb = va_arg(ap, unsigned long long int);
	if (ps->modifier == 'H')
		nb = (unsigned char)nb;
	else if (ps->modifier == 'h')
		nb = (unsigned short int)nb;
	else if (ps->modifier == 'L')
		nb = (unsigned long long int)nb;
	else if (ps->modifier == 'l')
		nb = (unsigned long int)nb;
	else
		nb = (unsigned int)nb;
	ft_printuns(ps, nb);
}

void		ft_compute(t_struct *ps, va_list ap)
{
	if (ps->conversion == 'd' || ps->conversion == 'i')
		ft_castsgn(ps, ap);
	else if (ps->conversion == 'u' || ps->conversion == 'x' ||
				ps->conversion == 'X')
		ft_castuns(ps, ap);
	else if (ps->conversion == 's')
		ft_printstr(ps, va_arg(ap, char *));
	else if (ps->conversion == 'c')
		ft_printchar(ps, va_arg(ap, int));
	else if (ps->conversion == 'p')
		ft_printptr(ps, va_arg(ap, intptr_t));
	else if (ps->conversion == '%')
		ft_printpercent(ps);
}
