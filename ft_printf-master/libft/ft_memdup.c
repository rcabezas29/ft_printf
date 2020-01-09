/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchivert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:08:08 by tchivert          #+#    #+#             */
/*   Updated: 2019/09/04 05:13:29 by tchivert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(void const *src, size_t len)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	void			*dest;
	unsigned int	i;

	i = 0;
	if (!(dest = (void *)malloc(len)))
		return (NULL);
	ptr1 = (unsigned char *)src;
	ptr2 = (unsigned char *)dest;
	while (ptr1[i])
	{
		ptr2[i] = ptr1[i];
		i++;
	}
	return (dest);
}
