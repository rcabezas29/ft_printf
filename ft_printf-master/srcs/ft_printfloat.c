/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfloat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchivert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 05:01:41 by tchivert          #+#    #+#             */
/*   Updated: 2019/11/12 16:59:20 by tchivert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putpads(t_env *env, int less, int arglen)
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

static int	ft_floatlen(t_env *env, double nb)
{
	unsigned long	integer;

	integer = (unsigned long)nb;
	return (ft_nbrlen(integer) + (env->prec ? env->prec : 6) + 1);
}

static void	ft_putfloat(t_env *env, double nb)
{
	int				i;
	long long int	integer;

	i = 0;
	integer = (long long int)nb;
	ft_putnbr(integer);
	if (env->prec == -1)
		return ;
	ft_putchar('.');
	nb -= integer;
	while ((env->prec && i < env->prec) || (!env->prec && i < 6))
	{
		if (nb)
		{
			nb *= 10;
			integer = (long long int)nb;
			ft_putnbr(integer);
			nb -= integer;
		}
		else
			ft_putchar('0');
		i++;
	}
}

void		ft_printfloat(t_env *env, double arg)
{
	if (arg < 0 && !env->width)
	{
		ft_putchar('-');
		arg *= -1;
		env->ret += 1;
	}
	if (env->width)
		ft_putpads(env, 1, ft_floatlen(env, arg));
	if (arg < 0 && env->width)
	{
		ft_putchar('-');
		arg *= -1;
		env->ret += 1;
	}
	env->ret += ft_floatlen(env, arg);
	ft_putfloat(env, arg);
	if (env->width && env->flags[2])
		ft_putpads(env, 0, ft_floatlen(env, arg));
}
