/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchivert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 04:59:55 by tchivert          #+#    #+#             */
/*   Updated: 2019/09/10 03:02:56 by tchivert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putsharp(t_env *env)
{
	if (env->conv == 'x' || env->conv == 'X' || env->conv == 'p')
	{
		ft_putstr(env->conv == 'X' ? "0X" : "0x");
		env->ret += 2;
	}
	else if (env->conv == 'o')
	{
		ft_putchar('0');
		env->ret++;
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
