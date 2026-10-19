/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 05:44:22 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/19 16:35:10 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	remove_head(t_list **a, t_list *tmp)
{
	if (is_link(a))
	{
		*a = tmp->next;
		(*a)->prev = tmp->prev;
		tmp->prev->next = *a;
	}
	else
	{
		*a = tmp->next;
		if (*a)
			(*a)->prev = NULL;
	}
}

static void	add_head(t_list **b, t_list *new)
{
	t_list	*head;
	t_list	*last;

	if (is_link(b))
	{
		head = *b;
		last = head->prev;
		new->next = head;
		new->prev = last;
		head->prev = new;
		last->next = new;
		*b = new;
	}
	else
	{
		new->next = *b;
		new->prev = NULL;
		(*b)->prev = new;
		*b = new;
	}
}

static void	push(t_list **a, t_list **b)
{
	int		data;
	t_list	*tmp;
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	tmp = *a;
	data = tmp->data;
	remove_head(a, tmp);
	free(tmp);
	if (lst_length(a) >= 3 && !is_link(a))
		link_lst(a);
	new->data = data;
	if (!(*b))
	{
		new->prev = NULL;
		new->next = NULL;
		*b = new;
		return ;
	}
	add_head(b, new);
	if (lst_length(b) >= 3 && !is_link(b))
		link_lst(b);
}

void	pa(t_list **a, t_list **b)
{
	push(b, a);
	apply_index(a);
	apply_index(b);
	write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	push(a, b);
	apply_index(a);
	apply_index(b);
	write(1, "pb\n", 3);
}
