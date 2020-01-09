/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchivert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 03:20:33 by tchivert          #+#    #+#             */
/*   Updated: 2019/09/10 05:00:08 by tchivert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putwidth(t_env *env, int less, int arglen)
{
	int	i;
	int	widthlen;
	int	preclen;

	i = 0;
	if (env->prec > 0 && env->prec < arglen && env->prec > (int)env->width)
		widthlen = env->width - env->prec;
	else
		widthlen = env->width - arglen;
	if (env->flags[3] || env->flags[4])
		widthlen -= env->flags[3] + env->flags[4];
	if (env->prec == -1)
		widthlen += arglen;
	preclen = env->prec > arglen ? env->prec - arglen : 0;
	if (env->width && ((!less && env->flags[2]) ||
				(less && !env->flags[2])))
	{
		while (++i <= widthlen - preclen)
			ft_putchar(env->flags[1] && !env->flags[2] && !preclen ? '0' : ' ');
		env->ret += i - 1;
	}
}

static void	ft_putprec(t_env *env, int arglen)
{
	int	i;
	int	preclen;

	i = 0;
	preclen = (env->prec > arglen ? env->prec - arglen : 0);
	if (env->prec)
	{
		while (++i <= preclen)
			ft_putchar('0');
		env->ret += i - 1;
	}
}

void		ft_printbin(t_env *env, unsigned long long arg)
{
	if (env->width)
		ft_putwidth(env, 1, ft_nbrlen_base(arg, "01"));
	if (env->prec)
		ft_putprec(env, ft_nbrlen_base(arg, "01"));
	if (env->prec != -1)
	{
		env->ret += ft_nbrlen_base(arg, "01");
		ft_putnbr_base(arg, "01");
	}
	if (env->flags[2])
		ft_putwidth(env, 0, ft_nbrlen_base(arg, "01"));
}
