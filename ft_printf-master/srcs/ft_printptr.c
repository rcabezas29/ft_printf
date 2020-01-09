/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchivert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 05:07:17 by tchivert          #+#    #+#             */
/*   Updated: 2019/09/10 02:49:05 by tchivert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putwidth(t_env *env, int less, int arglen)
{
	int	i;
	int	widthlen;

	i = 0;
	widthlen = env->width - arglen;
	if (env->width && ((!less && env->flags[2]) ||
				(less && !env->flags[2])))
	{
		while (++i <= widthlen)
			ft_putchar(' ');
		env->ret += i - 1;
	}
}

static void	ft_putprec(t_env *env, int arglen)
{
	int	i;
	int	preclen;

	i = 0;
	preclen = env->prec > arglen ? env->prec - arglen : 0;
	if (env->prec)
	{
		while (++i <= preclen)
			ft_putchar('0');
		env->ret += i - 1;
	}
}

void		ft_printptr(t_env *env, uintptr_t arg)
{
	if (env->width)
		ft_putwidth(env, 1, ft_nbrlen_base(arg, "0123456789abcdef") + 2);
	ft_putstr("0x");
	env->ret += 2;
	if (env->prec)
		ft_putprec(env, ft_nbrlen_base(arg, "0123456789abcdef"));
	if (env->prec != -1)
	{
		env->ret += ft_nbrlen_base(arg, "0123456789abcdef");
		ft_putnbr_base(arg, "0123456789abcdef");
	}
	if (env->width && env->flags[2])
		ft_putwidth(env, 0, ft_nbrlen_base(arg, "0123456789abcdef") + 2);
}
