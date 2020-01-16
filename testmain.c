/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-t <gde-la-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 09:00:52 by gde-la-t          #+#    #+#             */
/*   Updated: 2019/12/18 17:11:45 by gde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  " Is better to print the right answer and look ugly than to print the wrong answer and look pretty."

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	
//	char			c;
//	char			s[6] = "aloha";
//	int				i;
//	unsigned int	ui;
	unsigned int	hx;
//	long int		li;
//	float			f;
//	char			*p;

//	c = 71;
//	i = 2015;
//	ui = -7;
//	li = 21447483647;
//	f = 3.14159265;
//	p = &c;
	hx = 0xEFu; 


	ft_printf("%X\n", hx);  // print a single char
	printf("%X\n", hx);

}
	
