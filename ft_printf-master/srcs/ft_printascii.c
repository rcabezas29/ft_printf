/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printascii.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchivert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 05:05:27 by tchivert          #+#    #+#             */
/*   Updated: 2019/11/11 18:59:52 by tchivert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putpads(t_env *env, int less, int arglen)
{
	int	i;
	int	widthlen;

	i = 0;
	if (env->prec > 0 && env->prec < arglen)
		widthlen = env->width - env->prec;
	else
		widthlen = env->width - arglen;
	if (env->prec == -1)
		widthlen += arglen;
	if (env->width && ((!less && env->flags[2]) ||
				(less && !env->flags[2])))
	{
		while (++i <= widthlen)
			ft_putchar(' ');
		env->ret += i - 1;
	}
}

void		ft_printchar(t_env *env, char arg)
{
	int	i;

	i = 0;
	if (env->width || env->prec)
		ft_putpads(env, 1, 1);
	ft_putchar((char)arg);
	if (env->width && env->flags[2])
		ft_putpads(env, 0, 1);
	env->ret += 1;
}

void		ft_printstr(t_env *env, char *arg)
{
	int	i;

	i = 0;
	if (!arg)
		arg = "(null)";
	if (env->width || env->prec)
		ft_putpads(env, 1, ft_strlen(arg));
	if (env->prec != 0 && env->prec != -1)
	{
		while (i < env->prec && arg[i])
			ft_putchar(arg[i++]);
		env->ret += i;
	}
	else if (env->prec != -1)
	{
		ft_putstr(arg);
		env->ret += ft_strlen(arg);
	}
	if (env->width && env->flags[2])
		ft_putpads(env, 0, ft_strlen(arg));
}
