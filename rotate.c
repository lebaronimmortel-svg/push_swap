/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 05:46:17 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/19 16:35:31 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	go_next(t_list **lst)
{
	(*lst)->data = (*lst)->next->data;
	*lst = (*lst)->next;
}

static void	rotate(t_list **a)
{
	int		data;
	t_list	*tmp;
	t_list	*tmp2;

	data = (*a)->data;
	tmp = *a;
	tmp2 = *a;
	if (is_link(a))
	{
		tmp->data = tmp->next->data;
		tmp = tmp->next;
		while (tmp != tmp2->prev)
			go_next(&tmp);
	}
	else
	{
		while (tmp->next)
			go_next(&tmp);
	}
	tmp->data = data;
}

void	ra(t_list **a)
{
	rotate(a);
	apply_index(a);
	write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	rotate(b);
	apply_index(b);
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	apply_index(a);
	apply_index(b);
	write(1, "rr\n", 3);
}
