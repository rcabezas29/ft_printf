/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:15:58 by rcabezas          #+#    #+#             */
/*   Updated: 2020/02/08 13:46:11 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putsharp(t_struct *ps)
{
	if (ps->conversion == 'x' || ps->conversion == 'X' || ps->conversion == 'p')
	{
		ft_putstr_fd(ps->conversion == 'X' ? "0X" : "0x", 1);
		ps->ret += 2;
	}
	else if (ps->conversion == 'o')
	{
		ft_putchar_fd('0', 1);
		ps->ret++;
	}
}

int		ft_charchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}
