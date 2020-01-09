/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchivert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 01:34:41 by tchivert          #+#    #+#             */
/*   Updated: 2019/09/04 05:13:28 by tchivert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstend(t_list *head, void *content, size_t content_size)
{
	t_list	*current;

	if (head->content == NULL && head->content_size == 0)
	{
		current = head;
		current->content = content;
		current->content_size = content_size;
		current->next = NULL;
	}
	else
	{
		current = head;
		while (current->next != NULL)
			current = current->next;
		if (!(current->next = malloc(sizeof(t_list))))
			return (0);
		current = current->next;
		current->content = content;
		current->content_size = content_size;
		current->next = NULL;
	}
	return (1);
}
