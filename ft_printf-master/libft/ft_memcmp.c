/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchivert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:08:17 by tchivert          #+#    #+#             */
/*   Updated: 2019/09/04 05:13:29 by tchivert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	unsigned int	i;
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;

	i = 0;
	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	if (len == 0)
		return (0);
	while ((i < len - 1) && ptr_s1[i] == ptr_s2[i])
		i++;
	return ((int)(ptr_s1[i] - ptr_s2[i]));
}
