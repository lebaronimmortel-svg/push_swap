/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 22:36:09 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/15 22:36:11 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	sort_three(t_list **a)
{
	if (is_sort_lst(*a))
		return ;
	if ((*a)->index > (*a)->next->index && (*a)->index > (*a)->prev->index)
	{
		if ((*a)->next->index > (*a)->prev->index)
		{
			sa(a);
			rra(a);
		}
		else
			ra(a);
	}
	else if ((*a)->index < (*a)->next->index && (*a)->index < (*a)->prev->index)
	{
		rra(a);
		sa(a);
	}
	else if ((*a)->index > (*a)->next->index && (*a)->index < (*a)->prev->index)
		sa(a);
	else if ((*a)->index < (*a)->next->index && (*a)->index > (*a)->prev->index)
		rra(a);
	return ;
}

static int	is_first_low(t_list *lst)
{
	t_list	*tmp;

	tmp = lst->next;
	while (tmp->index != lst->index)
	{
		if (tmp->index < lst->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int	low_pos(t_list **a)
{
	t_list	*tmp;
	int		cnt;

	tmp = (*a);
	cnt = 0;
	while (!is_first_low(tmp))
	{
		tmp = tmp->next;
		cnt++;
	}
	return (cnt);
}

static void	put_low(t_list **a, t_list **b, int ind)
{
	if (low_pos(a) < lst_length(a) / 2)
	{
		while (!is_first_low(*a))
			ra(a);
	}
	else
	{
		while (!is_first_low(*a))
			rra(a);
	}
	if (ind == 0)
		pb(a, b);
	else
		pa(a, b);
}

void	sort_small(t_list **a, t_list **b)
{
	while (lst_length(a) > 3)
		put_low(a, b, 0);
	sort_three(a);
	while (lst_length(b) > 0)
		put_low(a, b, 1);
	return ;
}
