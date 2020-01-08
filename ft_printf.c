/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 17:23:28 by rcabezas          #+#    #+#             */
/*   Updated: 2020/01/08 18:29:24 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		formatparse(const char *format, t_struct *list, va_list ap, int pos)
{
	while (format[pos] != '\0')
	{
		if (format[pos] != '%' && format[pos])
			list->nprinted += write(1, &format[pos], 1);
		else if (format[pos] == '%')
		{
			if (!ft_strchr(ALLSYMBOLS, format[pos + 1]))
				break;
			while (ft_strchr(ALLSYMBOLS, format[pos + 1]))
			{
				pos = pos + 1;
				if (ft_strchr("cspdiouxXfyb%", format[pos]))
				{
					pos = parsel2(list, pos, format, ap) + 2;
					break;
				}
				else
					pos = parsel2(list, pos, format, ap);
			}
			continue;
		}
		pos++;
	}
	return(list->nprinted);
}

int		parsel2(t_struct *f, int position, const char *format, va_list ap)
{
	f->i = position;
	if (!ft_strchr("cspdiouxXfyb%", format[position]))
		modifiers(format, f, ap);
	else if (ft_strchr(("cspdiouxXfyb%"), format[position]))
	{
		conversions(format[position], ap, f);
		bezerostruct2(f);
	}
	return (f->i - 1);
}

void	conversions(char c, va_list ap, t_struct +f)
{
	if (c == 'c')
		ifchar(f, ap);
	else if (c == 's')
		ifstring(f. ap);
	else if (c == 'p')
		ifpointer(f, ap, 2);
	else if (c == 'd' || c == 'i')
		ifint(f, ap, 0, 0);
	else if (c == 'o')
		ifoctal(f, ap);
	else if (c == 'u')
		ifudecint(f, ap);
	else if (c == 'x'|| c == 'X')
		ifhex(f. ap, c);
	else if (c == 'f')
		iffloat(f, ap);
	else if (c == '%')
		ifpercent(f);
	else if (c == 'y')
		ifcat();
	else if (c == 'b')
		ifbinary(f, ap);
}

int 	ft_printf(const char *, ...) 
{
	va_list args;
	int cnt; //int to count %s
	int i; 
	int n;

	va_start(args, cnt);
	i = 0;
	while (i < cnt)
	{
		char *arg = va_arg(args, char *); 
		//char only if the type of argument is char
		i++;
	}
	va_end(args);
	return(cnt)
}
