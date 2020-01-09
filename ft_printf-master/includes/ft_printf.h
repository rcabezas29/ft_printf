/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchivert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 05:16:59 by tchivert          #+#    #+#             */
/*   Updated: 2019/09/10 05:45:29 by tchivert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>

typedef struct	s_env
{
	char		flags[5];
	size_t		width;
	int			prec;
	int			dot;
	char		modif;
	char		conv;
	size_t		ret;
	size_t		i;
}				t_env;

int				ft_printf(char *format, ...);
int				ft_init(t_env *env);
int				ft_reinit(t_env *env);

int				ft_parse(t_env *env, char *format);
void			ft_parseprec(t_env *env, char *format);
void			ft_parsewidth(t_env *env, char *format);

void			ft_compute(t_env *env, va_list ap);

void			ft_printsgn(t_env *env, long long int arg);
void			ft_printsgn_neg(t_env *env, long long int arg);
void			ft_printstr(t_env *env, char *arg);
void			ft_printchar(t_env *env, char arg);
void			ft_printuns(t_env *env, unsigned long long int arg);
void			ft_printbin(t_env *env, unsigned long long int arg);
void			ft_printptr(t_env *env, uintptr_t arg);
void			ft_printfloat(t_env *env, double arg);
void			ft_printpercent(t_env *env);

void			ft_putulnbr(unsigned long long n);
void			ft_putnbr_base(long long int nb, char *base);
int				ft_nbrlen(long long int n);
int				ft_nbrlen_base(long long int n, char *base);
int				ft_charchr(const char *s, int c);
void			ft_putsharp(t_env *env);

#endif
