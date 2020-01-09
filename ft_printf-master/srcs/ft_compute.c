/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchivert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 05:09:25 by tchivert          #+#    #+#             */
/*   Updated: 2019/09/10 04:26:20 by tchivert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_castsgn(t_env *env, va_list ap)
{
	long long int	nb;

	nb = va_arg(ap, long long int);
	if (env->modif == 'H')
		nb = (signed char)nb;
	else if (env->modif == 'h')
		nb = (short int)nb;
	else if (env->modif == 'L')
		nb = (long long int)nb;
	else if (env->modif == 'l')
		nb = (long int)nb;
	else
		nb = (int)nb;
	if (nb < 0)
		ft_printsgn_neg(env, nb);
	else
		ft_printsgn(env, nb);
}

static void	ft_castuns(t_env *env, va_list ap)
{
	unsigned long long int	nb;

	nb = va_arg(ap, unsigned long long int);
	if (env->modif == 'H')
		nb = (unsigned char)nb;
	else if (env->modif == 'h')
		nb = (unsigned short int)nb;
	else if (env->modif == 'L')
		nb = (unsigned long long int)nb;
	else if (env->modif == 'l')
		nb = (unsigned long int)nb;
	else
		nb = (unsigned int)nb;
	ft_printuns(env, nb);
}

void		ft_compute(t_env *env, va_list ap)
{
	if (env->conv == 'd' || env->conv == 'i')
		ft_castsgn(env, ap);
	else if (env->conv == 'o' || env->conv == 'u' ||
			env->conv == 'x' || env->conv == 'X' || env->conv == 'b')
		ft_castuns(env, ap);
	else if (env->conv == 's')
		ft_printstr(env, va_arg(ap, char *));
	else if (env->conv == 'c')
		ft_printchar(env, va_arg(ap, int));
	else if (env->conv == 'p')
		ft_printptr(env, va_arg(ap, uintptr_t));
	else if (env->conv == 'f')
	{
		if (env->modif == 'f')
			ft_printfloat(env, va_arg(ap, long double));
		else if (env->modif == 'l')
			ft_printfloat(env, va_arg(ap, double));
		else
			ft_printfloat(env, va_arg(ap, double));
	}
	else if (env->conv == '%')
		ft_printpercent(env);
}
