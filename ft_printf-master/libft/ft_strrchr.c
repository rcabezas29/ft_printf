/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchivert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:06:54 by tchivert          #+#    #+#             */
/*   Updated: 2019/09/04 05:13:34 by tchivert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*pos;

	i = 0;
	pos = (0);
	while (s[i])
	{
		if (s[i] == c)
			pos = ((char *)s + i);
		i++;
	}
	if (pos)
		return (pos);
	if (c == '\0')
		return ((char *)s + i);
	return (NULL);
}
