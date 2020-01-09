/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchivert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 01:15:04 by tchivert          #+#    #+#             */
/*   Updated: 2019/09/04 05:13:30 by tchivert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_print_args(const char *format, int i, va_list ap)
{
	if (format[i + 1] == 'd' || format[i + 1] == 'i')
		ft_putnbr(va_arg(ap, int));
	if (format[i + 1] == 'c')
		ft_putchar(va_arg(ap, int));
	if (format[i + 1] == 's')
		ft_putstr(va_arg(ap, char *));
	if (format[i + 1] == 'b')
		ft_print_bits(va_arg(ap, int));
	return (1);
}

static int		ft_parse_args(const char *format, va_list ap)
{
	int			i;
	int			len;

	i = 0;
	len = ft_strlen(format);
	while (i < len)
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			ft_print_args(format, i, ap);
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			ft_putchar('%');
			i += 2;
		}
		else
		{
			ft_putchar(format[i]);
			i++;
		}
	}
	return (1);
}

int				ft_printt(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	ft_parse_args(format, ap);
	va_end(ap);
	return (1);
}
