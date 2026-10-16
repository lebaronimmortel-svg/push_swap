/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tail.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:24:00 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/19 16:35:01 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	new_first(t_list **lst, t_list **b, int data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
	{
		free_lst(lst);
		free(lst);
		free(b);
		write(2, "Error\n", 6);
		exit(0);
	}
	new->next = NULL;
	new->data = data;
	new->prev = NULL;
	*lst = new;
}

static void	new_single(t_list **tmp, t_list **b, int data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
	{
		free_lst(tmp);
		free(tmp);
		free(b);
		write(2, "Error\n", 6);
		exit(0);
	}
	new->next = NULL;
	new->data = data;
	new->prev = (*tmp)->next;
	(*tmp)->next->next = new;
}

static void	new_end(t_list **tmp, t_list **b, int data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
	{
		free_lst(tmp);
		free(tmp);
		free(b);
		write(2, "Error\n", 6);
		exit(0);
	}
	new->next = NULL;
	new->data = data;
	new->prev = *tmp;
	(*tmp)->next = new;
}

void	new_tail(t_list **a, t_list **b, int data)
{
	t_list	*new;
	t_list	*tmp;

	new = NULL;
	if (!(*a))
	{
		new_first(a, b, data);
		return ;
	}
	tmp = *a;
	while (tmp->next && tmp->next->next)
		tmp = tmp->next;
	if (tmp->next && !(tmp->next->next))
		new_single(&tmp, b, data);
	else
		new_end(&tmp, b, data);
}
