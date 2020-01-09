/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchivert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 05:03:29 by tchivert          #+#    #+#             */
/*   Updated: 2019/09/10 05:55:25 by tchivert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putwidth(t_env *env, int less, int arglen)
{
	int	i;
	int	widthlen;
	int	preclen;

	i = 0;
	widthlen = (env->width - (env->prec == -1 ? 0 : arglen)) -
		(env->flags[0] && env->conv != 'u' ? 1 : 0);
	preclen = env->prec > arglen ? env->prec - arglen : 0;
	if (env->flags[0])
		widthlen -= env->conv == 'x' || env->conv == 'X' ? 1 : 0;
	if (env->width && ((!less && env->flags[2]) ||
				(less && !env->flags[2])))
	{
		while (++i <= widthlen - preclen)
			ft_putchar(env->flags[1] && !env->flags[2] ? '0' : ' ');
		env->ret += i - 1;
	}
}

static void	ft_putprec(t_env *env, int arglen)
{
	int	i;
	int	preclen;

	i = 0;
	preclen = env->prec > arglen ? env->prec - arglen : 0;
	if (env->flags[0] && env->conv == 'o')
		preclen--;
	if (env->prec)
	{
		while (++i <= preclen)
			ft_putchar('0');
		env->ret += i - 1;
	}
}

static void	ft_printhex(t_env *env, unsigned long long arg)
{
	if (env->flags[0] && arg && env->flags[1])
		ft_putsharp(env);
	if (env->width)
		ft_putwidth(env, 1, ft_nbrlen_base(arg, "0123456789abcdef"));
	if (env->flags[0] && arg && !env->flags[1] && env->prec)
		ft_putsharp(env);
	if (env->prec)
		ft_putprec(env, ft_nbrlen_base(arg, "0123456789abcdef"));
	if (env->flags[0] && arg && !env->flags[1] && !env->prec)
		ft_putsharp(env);
	if (env->prec != -1)
		env->ret += ft_nbrlen_base(arg, "0123456789abcdef");
	if (env->conv == 'x' && env->prec != -1)
		ft_putnbr_base(arg, "0123456789abcdef");
	else if (env->conv == 'X' && env->prec != -1)
		ft_putnbr_base(arg, "0123456789ABCDEF");
	if (env->flags[2])
		ft_putwidth(env, 0, ft_nbrlen_base(arg, "0123456789abcdef"));
}

static void	ft_printoct(t_env *env, unsigned long long arg)
{
	if (env->width)
		ft_putwidth(env, 1, ft_nbrlen_base(arg, "01234567"));
	if (env->prec > 0)
		ft_putprec(env, ft_nbrlen_base(arg, "01234567"));
	if (env->flags[0])
		ft_putsharp(env);
	if ((arg > 0 || env->prec > -1) && !(arg == 0 && env->flags[0]))
	{
		env->ret += ft_nbrlen_base(arg, "01234567");
		ft_putnbr_base(arg, "01234567");
	}
	if (env->flags[2])
		ft_putwidth(env, 0, ft_nbrlen_base(arg, "01234567"));
}

void		ft_printuns(t_env *env, unsigned long long arg)
{
	if (env->conv == 'x' || env->conv == 'X')
		ft_printhex(env, arg);
	if (env->conv == 'o')
		ft_printoct(env, arg);
	if (env->conv == 'b')
		ft_printbin(env, arg);
	if (env->conv == 'u')
	{
		if (env->width)
			ft_putwidth(env, 1, ft_nbrlen(arg));
		if (env->prec)
			ft_putprec(env, ft_nbrlen(arg));
		if (!(env->prec == -1 && arg == 0))
		{
			if (arg == ULONG_MAX || (long long)arg < 0)
				env->ret += 20;
			else
				env->ret += ft_nbrlen(arg);
			ft_putulnbr(arg);
		}
		if (env->flags[2])
			ft_putwidth(env, 0, ft_nbrlen(arg));
	}
}
