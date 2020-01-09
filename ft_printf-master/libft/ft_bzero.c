/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchivert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:21:15 by tchivert          #+#    #+#             */
/*   Updated: 2019/09/04 05:13:26 by tchivert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t len)
{
	unsigned long		i;
	unsigned char		*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	if (len <= 0)
		return ;
	while (i < len)
	{
		ptr[i++] = '\0';
	}
}
