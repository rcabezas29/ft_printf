/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchivert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:07:52 by tchivert          #+#    #+#             */
/*   Updated: 2019/09/04 05:13:28 by tchivert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;
	t_list	*nextptr;

	ptr = *alst;
	while (ptr)
	{
		nextptr = ptr;
		ft_lstdelone(&ptr, del);
		ptr = nextptr->next;
	}
	*alst = NULL;
}
