/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:59:03 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/19 16:35:53 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	swap(t_list **a)
{
	int	data;
	int	data2;

	data = (*a)->data;
	data2 = ((*a)->next)->data;
	(*a)->data = data2;
	((*a)->next)->data = data;
}

void	sa(t_list **a)
{
	swap(a);
	apply_index(a);
	write(1, "sa\n", 3);
}

void	sb(t_list **b)
{
	swap(b);
	apply_index(b);
	write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	apply_index(a);
	apply_index(b);
	write(1, "ss\n", 3);
}
