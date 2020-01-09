/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchivert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 05:10:41 by tchivert          #+#    #+#             */
/*   Updated: 2019/09/10 05:45:47 by tchivert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_reinit(t_env *env)
{
	ft_bzero(env->flags, 5);
	env->width = 0;
	env->prec = 0;
	env->dot = 0;
	env->modif = '\0';
	env->conv = '\0';
	return (1);
}

int	ft_init(t_env *env)
{
	ft_bzero(env->flags, 5);
	env->width = 0;
	env->prec = 0;
	env->dot = 0;
	env->modif = '\0';
	env->conv = '\0';
	env->ret = 0;
	env->i = 0;
	return (1);
}
