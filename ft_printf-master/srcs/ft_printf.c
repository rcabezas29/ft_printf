/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchivert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 05:08:38 by tchivert          #+#    #+#             */
/*   Updated: 2019/09/10 05:45:11 by tchivert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_read(t_env *env, char *format, va_list ap)
{
	while (format[env->i])
	{
		if (format[env->i] == '%')
		{
			env->i++;
			if (ft_parse(env, format))
				ft_compute(env, ap);
			ft_reinit(env);
		}
		else
		{
			ft_putchar(format[env->i]);
			env->i++;
			env->ret++;
		}
	}
}

int			ft_printf(char *format, ...)
{
	t_env	*env;
	size_t	ret;
	va_list	ap;

	if (!format)
		return (-1);
	if (!(env = malloc(sizeof(t_env))) || !(ft_init(env)))
		return (-1);
	va_start(ap, format);
	ft_read(env, format, ap);
	ret = env->ret;
	free(env);
	return (ret);
}
