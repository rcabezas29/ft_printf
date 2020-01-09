/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchivert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:58:58 by tchivert          #+#    #+#             */
/*   Updated: 2019/09/04 05:13:27 by tchivert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_nblen(unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

char				*ft_itoa(int n)
{
	char			*dest;
	unsigned int	len;
	unsigned int	nb;
	unsigned int	i;

	nb = (n < 0 ? -n : n);
	len = ft_nblen(nb);
	i = 0;
	if (!(dest = (char *)malloc(sizeof(char) * len + 1 + (n < 0 ? 1 : 0))))
		return (NULL);
	if (n < 0)
	{
		dest[i] = '-';
		len++;
	}
	i = len - 1;
	while (nb >= 10)
	{
		dest[i] = nb % 10 + 48;
		nb /= 10;
		i--;
	}
	dest[i] = nb % 10 + 48;
	dest[len] = '\0';
	return (dest);
}
