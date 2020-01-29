/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 09:00:52 by gde-la-t          #+#    #+#             */
/*   Updated: 2020/01/29 20:33:40 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  " Is better to print the right answer and look ugly than to print the wrong answer and look pretty."

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
/*
	char			c;
	char			s[6] = "aloha";
*/	int				i;
	int				j;
/*	unsigned int	ui;
	unsigned int	hx;
	long int		li;
	char			*p;

	c = 71;
	i = 2015;
	ui = -7;
	li = 21447483647;
	p = &c;
	hx = 0xEFu; 
*/
	i = ft_printf("%5.p", NULL);
	ft_printf("%i\n", i);
	j = printf("%5.p", NULL);
	printf("%i\n", j);
	printf("-------\n");
}
	
