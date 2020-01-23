/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsesizes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:05:33 by rcabezas          #+#    #+#             */
/*   Updated: 2020/01/23 18:31:52 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_parseprecision(t_struct *ps, const char *format, va_list ap)
{
	ps->dot = 1;
	ps->i++;
	if (!ft_isdigit(format[ps->i]) && !(format[ps->i] == '*'))
	{
		ps->precision = -1;
		return ;
	}
	else if (format[ps->i] == '*' && format[ps->i - 1] == '.')
	{	
		ft_precisionast(ps, ap);
		return ;
	}
	else
	{
		ps->precision = ft_atoi(format + ps->i);
		ps->i += ft_nbrlen(ps->precision);
	}
}

void	ft_parsewidth(t_struct *ps, const char *format, va_list ap)
{
	if (format[ps->i] == '*' && format[ps->i - 1] != '.')
		ft_widthast(ps, ap);
	else
	{
		ps->width = ft_atoi(format + ps->i);
		ps->i += ft_nbrlen(ps->width);
	}
}