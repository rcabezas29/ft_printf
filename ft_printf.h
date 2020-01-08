/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 17:39:54 by rcabezas          #+#    #+#             */
/*   Updated: 2020/01/08 17:49:26 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdarg.h>

typedef struct	s_struct
{
	char		*format;

	int			nprinted;

	int 		i;
	int			len;

	int			minus;
	int			plus;
	int			space;
	int			zero;
	int			hash;

	int			width;
	int			precisiontf;
	int			precision;
	int			length;
}				t_struct;
#endif
