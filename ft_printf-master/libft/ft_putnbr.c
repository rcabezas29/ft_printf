/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchivert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:23:21 by tchivert          #+#    #+#             */
/*   Updated: 2019/09/04 05:13:31 by tchivert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	nb = (unsigned int)n;
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + 48);
}
