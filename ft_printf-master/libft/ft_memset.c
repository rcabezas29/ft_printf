/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchivert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:15:31 by tchivert          #+#    #+#             */
/*   Updated: 2019/09/04 05:13:30 by tchivert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char		*ptr;

	ptr = (unsigned char *)s;
	while (len-- > 0)
	{
		*ptr++ = (unsigned char)c;
	}
	return (s);
}
