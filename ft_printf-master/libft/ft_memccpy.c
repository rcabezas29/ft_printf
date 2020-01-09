/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchivert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:02:00 by tchivert          #+#    #+#             */
/*   Updated: 2019/09/04 05:13:29 by tchivert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	i = 0;
	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	while (i < len)
	{
		ptr_dest[i] = ptr_src[i];
		if (ptr_src[i] == (unsigned char)c)
		{
			return ((void *)dest + i + 1);
		}
		i++;
	}
	return (NULL);
}
