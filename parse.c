/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:14:18 by rcabezas          #+#    #+#             */
/*   Updated: 2020/01/21 09:31:57 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_parseast(t_struct *ps, va_list ap)
{
	ps->ast++;
	if (ps->ast == 1)
	{
		ft_widthast(ps, ap);
	}
	else if (ps->ast == 2)
	{
		ft_widthast(ps, ap);
		ft_precisionast(ps, ap);
	}
}

static void	ft_parseflags(t_struct *ps, const char *format)
{
	if (format[ps->i] == '#')
	{
		ps->flags[0] = 1;
		ps->i++;
	}
	if (format[ps->i] == '0')
	{
		ps->flags[1] = 1;
		ps->i++;
	}
	if (format[ps->i] == '-')
	{
		ps->flags[2] = 1;
		ps->i++;
	}
	if (format[ps->i] == '+')
	{
		ps->flags[3] = 1;
		ps->i++;
	}
	if (format[ps->i] == ' ')
	{
		ps->flags[4] = 1;
		ps->i++;
	}
	if (format[ps->i] == '*')
	{
		ps->flags[5] = 1;
		ps->i++;
	}
}

static void	ft_parsemodifiers(t_struct *ps, const char *format)
{
	if (format[ps->i] == 'h' && format[ps->i + 1] == 'h')
		ps->modifier = 'H';
	else if (format[ps->i] == 'h')
		ps->modifier = 'h';
	else if (format[ps->i] == 'l' && format[ps->i + 1] == 'l')
		ps->modifier = 'L';
	else if (format[ps->i] == 'l')
		ps->modifier = 'l';
	if (ps->modifier)
		ft_isupper(ps->modifier) ? (ps->i += 2) : (ps->i++);
}

static void	ft_parsespecs(t_struct *ps, const char *format, va_list ap)
{
	if (format[ps->i] == '#' || format[ps->i] == '0' ||
			format[ps->i] == '-' || format[ps->i] == '+' ||
			format[ps->i] == ' ' || format[ps->i] == '*')
		ft_parseflags(ps, format);
	if ((ft_isdigit(format[ps->i]) && format[ps->i] != '0'))
		ft_parsewidth(ps, format);
	if (format[ps->i] == '.')
		ft_parseprecision(ps, format, ap);
	if (format[ps->i] == '*')
		ft_parseast(ps, ap);
	if (format[ps->i] == 'h' || format[ps->i] == 'l')
		ft_parsemodifiers(ps, format);
}

int			ft_parse(t_struct *ps, const char *format, va_list ap)
{
	while ((format[ps->i] == '#' || format[ps->i] == '0' ||
				format[ps->i] == '-' || format[ps->i] == '+' ||
				format[ps->i] == ' ' || format[ps->i] == '.' ||
				format[ps->i] == 'h' || format[ps->i] == 'l' ||
				ft_isdigit(format[ps->i]) || format[ps->i] == '*')
				&& format[ps->i])
		ft_parsespecs(ps, format, ap);
	if (ps->precision == 0 && ps->dot == 1)
		ps->precision = -1;
	if (ft_charchr("cspdiuxX%", format[ps->i]))
		ps->conversion = format[ps->i++];
	return (1);
}
