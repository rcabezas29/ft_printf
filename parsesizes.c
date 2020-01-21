/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsesizes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:05:33 by rcabezas          #+#    #+#             */
/*   Updated: 2020/01/21 10:43:29 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parseprecision(t_struct *ps, const char *format, va_list ap)
{
	ps->dot = 1;
	ps->i++;
	if (format[ps->i] == '-' || !ft_isdigit(format[ps->i] || !(format[ps->i] == '*')))
	{
		ps->precision = -1;
		return ;
	}
	else if (format[ps->i] == '*')
		ft_precisionast(ps, ap);
	else
	{
		ps->precision = ft_atoi(format + ps->i);
		ps->i += ft_nbrlen(ps->precision);
	}
}

void	ft_parsewidth(t_struct *ps, const char *format)
{
	ps->width = ft_atoi(format + ps->i);
	ps->i += ft_nbrlen(ps->width);
}