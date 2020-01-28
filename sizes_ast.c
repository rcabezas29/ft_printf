/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizes_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 08:50:21 by rcabezas          #+#    #+#             */
/*   Updated: 2020/01/23 18:34:39 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void    ft_precisionast(t_struct *ps, va_list ap)
{
    ps->precision = va_arg(ap, int);
    ps->i++;
}

void    ft_widthast(t_struct *ps, va_list ap)
{
    ps->width = va_arg(ap, int);
    ps->i++;
}