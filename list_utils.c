/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:43:05 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/18 20:06:28 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_lst(t_list **lst)
{
	t_list	*head;
	t_list	*cur;
	t_list	*next;

	if (!lst || !*lst)
		return ;
	head = *lst;
	cur = head->next;
	if (is_link(lst))
	{
		head->prev->next = NULL;
		head->prev = NULL;
	}
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	free(head);
	*lst = NULL;
}

int	lst_length(t_list **lst)
{
	int		i;
	t_list	*tmp;

	if (!(*lst))
		return (0);
	tmp = *lst;
	if (tmp->prev)
	{
		tmp->prev->next = NULL;
		tmp->prev = NULL;
	}
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	if (i >= 3)
		link_lst(lst);
	return (i);
}

int	is_valid_list(t_list **a)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp2 = *a;
	while (tmp2)
	{
		tmp = *a;
		while (tmp)
		{
			if (tmp->data == tmp2->data && tmp != tmp2)
				return (-1);
			tmp = tmp->next;
		}
		tmp2 = tmp2->next;
	}
	return (1);
}

int	is_sort_lst(t_list *lst)
{
	t_list	*tmp;
	int		data;

	if (!lst)
		return (1);
	tmp = lst;
	data = tmp->data;
	while (tmp->next && tmp->next->data != data)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
