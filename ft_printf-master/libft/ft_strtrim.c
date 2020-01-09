/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchivert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:41:49 by tchivert          #+#    #+#             */
/*   Updated: 2019/09/04 05:13:34 by tchivert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_scpy(char *dest, char *src, int i, size_t len)
{
	int		j;

	j = 0;
	j += i;
	i = 0;
	while (i < (int)len)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*dest;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
		len--;
	i = -1;
	while (s[++i] == ' ' || s[i] == '\t' || s[i] == '\n')
		len--;
	if (len <= 0)
		len = 0;
	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (dest == NULL)
		return (NULL);
	ft_scpy(dest, (char *)s, i, len);
	return (dest);
}
