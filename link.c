/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 05:56:16 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/19 16:34:20 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	is_link_next(t_list **lst)
{
	int		data;
	t_list	*tmp;

	if (!lst || !(*lst) || !((*lst)->next))
		return (0);
	tmp = *lst;
	data = (*lst)->data;
	tmp = tmp->next;
	while (tmp && tmp->data != data)
		tmp = tmp->next;
	if (tmp)
		return (1);
	else
		return (0);
}

static int	is_link_prev(t_list **lst)
{
	int		data;
	t_list	*tmp;

	if (!lst || !(*lst) || !((*lst)->prev))
		return (0);
	tmp = *lst;
	data = (*lst)->data;
	tmp = tmp->prev;
	while (tmp && tmp->data != data)
		tmp = tmp->prev;
	if (tmp)
		return (1);
	else
		return (0);
}

int	is_link(t_list **lst)
{
	if (is_link_prev(lst) && is_link_next(lst))
		return (1);
	else
		return (0);
}

void	link_lst(t_list **lst)
{
	t_list	*tail;
	t_list	*head;

	head = *lst;
	tail = head;
	while (tail->next)
		tail = tail->next;
	tail->next = head;
	head->prev = tail;
}
