/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchivert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 05:07:04 by tchivert          #+#    #+#             */
/*   Updated: 2019/09/10 04:30:19 by tchivert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_parseflag(t_env *env, char *format)
{
	if (format[env->i] == '#')
	{
		env->flags[0] = 1;
		env->i++;
	}
	if (format[env->i] == '0')
	{
		env->flags[1] = 1;
		env->i++;
	}
	if (format[env->i] == '-')
	{
		env->flags[2] = 1;
		env->i++;
	}
	if (format[env->i] == '+')
	{
		env->flags[3] = 1;
		env->i++;
	}
	if (format[env->i] == ' ')
	{
		env->flags[4] = 1;
		env->i++;
	}
}

static void	ft_parsemod(t_env *env, char *format)
{
	if (format[env->i] == 'h' && format[env->i + 1] == 'h')
		env->modif = 'H';
	else if (format[env->i] == 'h')
		env->modif = 'h';
	else if (format[env->i] == 'l' && format[env->i + 1] == 'l')
		env->modif = 'L';
	else if (format[env->i] == 'L')
		env->modif = 'f';
	else if (format[env->i] == 'l')
		env->modif = 'l';
	if (env->modif)
		ft_isupper(env->modif) ? (env->i += 2) : (env->i++);
}

static void	ft_parsespecs(t_env *env, char *format)
{
	if (format[env->i] == '#' || format[env->i] == '0' ||
			format[env->i] == '-' || format[env->i] == '+' ||
			format[env->i] == ' ')
		ft_parseflag(env, format);
	if (ft_isdigit(format[env->i]) && format[env->i] != '0')
		ft_parsewidth(env, format);
	if (format[env->i] == '.')
		ft_parseprec(env, format);
	if (format[env->i] == 'h' || format[env->i] == 'l' || format[env->i] == 'L')
		ft_parsemod(env, format);
}

int			ft_parse(t_env *env, char *format)
{
	while ((format[env->i] == '#' || format[env->i] == '0' ||
				format[env->i] == '-' || format[env->i] == '+' ||
				format[env->i] == ' ' || format[env->i] == '.' ||
				format[env->i] == 'h' || format[env->i] == 'l' ||
				format[env->i] == 'L' || ft_isdigit(format[env->i])) &&
				format[env->i])
		ft_parsespecs(env, format);
	if (env->prec == 0 && env->dot == 1)
		env->prec = -1;
	if (ft_charchr("diouxXscpbf%", format[env->i]))
		env->conv = format[env->i++];
	return (1);
}
