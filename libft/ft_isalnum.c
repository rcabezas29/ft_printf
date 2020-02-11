/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:51:13 by rcabezas          #+#    #+#             */
/*   Updated: 2019/11/06 13:40:49 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalnum(int c)
{
	int x;

	x = 1;
	if ((c > 47 && c < 58) || (c > 64 && c < 91) || (c > 96 && c < 123))
		x = 1;
	else
		x = 0;
	return (x);
}
