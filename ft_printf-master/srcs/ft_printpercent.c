/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchivert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 02:16:34 by tchivert          #+#    #+#             */
/*   Updated: 2019/09/06 05:29:31 by tchivert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putpads(t_env *env, int less)
{
	int	i;
	int	widthlen;

	i = 0;
	widthlen = env->width - 1;
	if (env->width && ((less && env->flags[2]) ||
				(!less && !env->flags[2])))
	{
		while (++i <= widthlen)
			ft_putchar(env->flags[1] ? '0' : ' ');
		env->ret += i - 1;
	}
}

void		ft_printpercent(t_env *env)
{
	if (env->width || env->prec)
		ft_putpads(env, 0);
	env->ret++;
	ft_putchar('%');
	if (env->flags[2])
		ft_putpads(env, 1);
}
