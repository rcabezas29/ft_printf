/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchivert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:05:25 by tchivert          #+#    #+#             */
/*   Updated: 2019/09/04 05:13:32 by tchivert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dest;
	size_t	len;

	if (s1 && s2)
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
	else if (s1)
		len = ft_strlen(s1);
	else if (s2)
		len = ft_strlen(s2);
	else
		return (NULL);
	if (!(dest = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	if (s1)
		dest = ft_strcpy(dest, s1);
	else
		dest = ft_strcpy(dest, s2);
	if (s1 && s2)
		dest = ft_strcat(dest, s2);
	return (dest);
}
