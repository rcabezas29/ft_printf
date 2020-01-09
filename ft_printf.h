/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 17:39:54 by rcabezas          #+#    #+#             */
/*   Updated: 2020/01/09 12:49:33 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_struct
{
	char		flags[5];
	size_t		width;
	int			precision;
	int			dot;
	char		modifier;
	char		conversion;
	size_t		ret;
	size_t		i;
}				t_struct;

int				ft_printf(const char *format, ...);

int				ft_init(t_struct *ps);
int				ft_reinit(t_struct *ps);

void		ft_compute(t_struct *ps, va_list ap);

int			ft_parse(t_struct *ps, char *format);

#endif
