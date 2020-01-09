/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchivert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:02:44 by tchivert          #+#    #+#             */
/*   Updated: 2019/09/04 05:13:33 by tchivert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t len)
{
	unsigned int	i;
	int				j;

	i = 0;
	j = ft_strlen((const char *)s1);
	while (s2[i] && i < len)
	{
		s1[j] = s2[i];
		i++;
		j++;
	}
	s1[j] = '\0';
	return (s1);
}
