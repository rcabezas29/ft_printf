/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printsgn_neg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchivert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 23:56:41 by tchivert          #+#    #+#             */
/*   Updated: 2019/11/11 18:56:36 by tchivert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putlnbr(long long int n)
{
	if (n <= LONG_MIN)
	{
		ft_putstr("9223372036854775808");
		return ;
	}
	if (n < 0)
		n = -n;
	if (n > 9)
		ft_putlnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

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
	if (env->flags[4])
		widthlen -= 1;
	if (env->prec == -1)
		widthlen += arglen;
	preclen = env->prec > arglen ? env->prec - arglen + 1 : 0;
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
	preclen = env->prec > arglen ? env->prec - arglen + 1 : 0;
	if (env->prec)
	{
		while (++i <= preclen)
			ft_putchar('0');
		env->ret += i - 1;
	}
}

void		ft_printsgn_neg(t_env *env, long long int arg)
{
	size_t	arglen;

	arglen = ft_nbrlen(arg);
	if (arg <= LONG_MIN)
		env->ret += 18;
	if (env->flags[1])
		ft_putchar('-');
	if (env->width)
		ft_putwidth(env, 1, arglen);
	if (!env->flags[1] && env->prec > (int)arglen)
		ft_putchar('-');
	if (env->prec)
		ft_putprec(env, arglen);
	if (!env->flags[1] && env->prec <= (int)arglen)
		ft_putchar('-');
	if (env->prec != -1)
	{
		env->ret += arglen;
		ft_putlnbr(arg);
	}
	if (env->flags[2])
		ft_putwidth(env, 0, arglen);
}
