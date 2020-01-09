/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchivert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 11:06:51 by tchivert          #+#    #+#             */
/*   Updated: 2019/09/04 05:13:34 by tchivert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int		number;
	int		i;

	i = 0;
	number = 0;
	while (*s)
	{
		if (i == 1 && *s == c)
			i = 0;
		if (i == 0 && *s != c)
		{
			i = 1;
			number++;
		}
		s++;
	}
	return (number);
}

char		**ft_strsplit(char const *s, char c)
{
	int		words;
	char	**tab;
	int		i;
	int		j;
	int		start;

	if (!s || !c)
		return (NULL);
	words = ft_count_words(s, c);
	if (!(tab = malloc((sizeof(char *) * (words + 1)))))
		return (NULL);
	i = 0;
	j = -1;
	while (++j < words)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		tab[j] = ft_strsub(s, start, i - start);
		i++;
	}
	tab[j] = NULL;
	return (tab);
}
