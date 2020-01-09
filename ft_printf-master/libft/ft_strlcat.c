/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchivert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:16:38 by tchivert          #+#    #+#             */
/*   Updated: 2019/09/04 05:13:33 by tchivert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = 0;
	j = 0;
	res = 0;
	while (dest[i])
		i++;
	while (src[res])
		res++;
	if (len <= i)
		res += len;
	else
		res += i;
	while (src[j] && (i + 1) < len)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (res);
}
