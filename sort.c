/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:27:45 by alexfuen          #+#    #+#             */
/*   Updated: 2025/12/15 19:27:47 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	push_rotate(t_list **a, t_list **b, int chunk_middle)
{
	pb(a, b);
	if ((*b)->index < chunk_middle)
		rb(b);
}

static void	shift(t_list **a, int chunk_min, int chunk_max)
{
	int	i;

	i = find_next_close(a, chunk_min, chunk_max);
	if (i == 1)
		ra(a);
	else if (i == 2)
		rra(a);
}

static void	incr(int *chunk_min, int *chunk_max, int chunk_size)
{
	*chunk_min += chunk_size;
	*chunk_max += chunk_size;
}

static void	chunk_sort(t_list **a, t_list **b)
{
	int	len;
	int	chunk_size;
	int	chunk_min;
	int	chunk_max;
	int	chunk_middle;

	len = lst_length(a);
	chunk_size = get_chunk_size(len);
	chunk_min = 0;
	chunk_max = chunk_size - 1;
	chunk_middle = (chunk_min + chunk_max) / 2;
	while (chunk_min < len)
	{
		while (lst_has_chunk(*a, chunk_min, chunk_max))
		{
			if ((*a)->index >= chunk_min && (*a)->index <= chunk_max)
				push_rotate(a, b, chunk_middle);
			else
				shift(a, chunk_min, chunk_max);
		}
		incr(&chunk_min, &chunk_max, chunk_size);
		if (chunk_max >= len)
			chunk_max = len - 1;
		chunk_middle = (chunk_min + chunk_max) / 2;
	}
}

void	sort(t_list **a, t_list **b)
{
	int	pos;
	int	max_idx;

	if (lst_length(a) == 2)
	{
		sa(a);
		return ;
	}
	if (lst_length(a) < 20)
	{
		sort_small(a, b);
		return ;
	}
	chunk_sort(a, b);
	while (lst_length(b) > 0)
	{
		max_idx = lst_max_index(*b);
		pos = lst_position_index(*b, max_idx);
		if ((*b)->index == max_idx)
			pa(a, b);
		else if (pos <= lst_length(b) / 2)
			rb(b);
		else
			rrb(b);
	}
}
