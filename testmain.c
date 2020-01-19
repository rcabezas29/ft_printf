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
	
	char			c;
	char			s[6] = "aloha";
	int				i;
	unsigned int	ui;
	unsigned int	hx;
	long int		li;
    char			*p;

	c = 71;
	i = 2015;
	ui = -7;
	li = 21447483647;
	p = &c;
	hx = 0xEFu; 


// FORMAT SPECIFICATIONS 
// A conversion specification consists of optional and required fields in this form:
// %[flags][width][.precision][size]type

	ft_printf("%c\n", c);  // print a single char
	ft_printf("%s\n", s);  // print a string of chars
	ft_printf("%d\n", i);  // print a int base 10
	ft_printf("%i\n", i);  // print a int base 10
	ft_printf("%p\n", p);  // print a pointer
	ft_printf("%x\n", ui); // print an unsigned decimal
	ft_printf("%ld\n",li); // print a long int
	
	
	
	ft_printf("%5d", i);	// WIDTH OPTION 	The width specification never causes a value to be truncated. 
	ft_printf("\n");		//					If the number of characters in the output value is greater than the specified width, 
	ft_printf("%3d", i);  	// WIDTH OPTION		or if width isn't given, all characters of the value are output, subject to the precision specification.	
	ft_printf("\n");
	ft_printf("%07d",i);   // FILLING EXTRA 0
	ft_printf("\n");
	ft_printf("%-5d",i);	// LEFT JUSTIFY
	ft_printf("\n");
	ft_printf("%+5d",i);	// SIGNED +
	ft_printf("\n");
	ft_printf("%+5d",0);	// SIGNED +( O IS +)
	ft_printf("\n");
	ft_printf("%+-5d",0);	// SIGNED +( O IS +)
	ft_printf("\n");
	ft_printf("%+-5d",i); 	// VISIBLE SIGN
	ft_printf("\n");
	ft_printf("% -5d",i); 	// UNVISIBLE SIGN
	ft_printf("\n");
	ft_printf("% 05d",i); // SPACE , PLUS, ZERO
	ft_printf("\n");
	
// PRECISION SPECIFICATION  It consists of a period (.) followed by a non-negative decimal integer that, depending on the conversion type, 
//							specifies the number of string characters, the number of decimal places, or the number of significant digits to be output.
		 					
//	ft_printf("%.2s\n", s);				// Type S -> The precision specifies the maximum number of characters to be printed. 	
	ft_printf("%-.*s\n", 5,"que pasa");	// Characters in excess of precision aren't printed
	ft_printf("%-.*s\n", 10,"que pasa");
	ft_printf("%.*s\n",0, s); 				// No characters output 
	ft_printf("%*s\n",0, s); 				// Without period (.) ->  no truncation
 	ft_printf("%-.*d\n", 5,3636363);		// Type D , I , X -> The precision specifies the minimum number of digits to be printed. If the number of digits in the argument is less than precision,
	ft_printf("%-.*x\n", 5,hx);			// the output value is padded on the left with zeros. The value is not truncated when the number of digits exceeds precision. 
	ft_printf("%-.*x\n", 2,hx);			// 0xEFU = 239 = ef
	ft_printf("%-.*x\n", 1,hx);
//	printf("%-.*c", 5,c);				// Type C -> The precision has no effect.		

}
	
