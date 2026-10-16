/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 05:46:28 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/19 16:35:22 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	shift_down_link(t_list *tmp, t_list *start, int data)
{
	if (!tmp->prev)
		return ;
	tmp->data = tmp->prev->data;
	tmp = tmp->prev;
	while (tmp != start->next)
	{
		if (!tmp->prev)
			return ;
		tmp->data = tmp->prev->data;
		tmp = tmp->prev;
	}
	tmp->data = data;
}

static void	reverse_rotate(t_list **a)
{
	int		data;
	t_list	*tmp;
	t_list	*prev;

	data = (*a)->data;
	tmp = *a;
	if (is_link(a))
		shift_down_link(tmp, *a, data);
	else
	{
		prev = NULL;
		while (tmp->next)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		prev->next = NULL;
		tmp->next = *a;
		(*a)->prev = tmp;
		*a = tmp;
	}
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	apply_index(a);
	apply_index(b);
	write(1, "rrr\n", 4);
}

void	rra(t_list **a)
{
	reverse_rotate(a);
	apply_index(a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	reverse_rotate(b);
	apply_index(b);
	write(1, "rrb\n", 4);
}
