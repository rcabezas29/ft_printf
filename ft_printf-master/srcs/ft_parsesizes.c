/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsesizes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchivert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 01:38:34 by tchivert          #+#    #+#             */
/*   Updated: 2019/09/06 04:00:35 by tchivert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parseprec(t_env *env, char *format)
{
	env->dot = 1;
	env->i++;
	if (format[env->i] == '-' || !ft_isdigit(format[env->i]))
	{
		env->prec = -1;
		return ;
	}
	env->prec = ft_atoi(format + env->i);
	env->i += ft_nbrlen(env->prec);
}

void	ft_parsewidth(t_env *env, char *format)
{
	env->width = ft_atoi(format + env->i);
	env->i += ft_nbrlen(env->width);
}
