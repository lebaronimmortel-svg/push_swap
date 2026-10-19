/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_close.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:37:19 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/18 15:37:21 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	find_forward(t_list *tmp1, int chunk_min, int chunk_max, int *i)
{
	t_list	*tmp0;

	tmp0 = tmp1;
	while (tmp1->index < chunk_min || tmp1->index > chunk_max)
	{
		tmp1 = tmp1->next;
		i++;
		if (tmp1 == tmp0)
			return (0);
	}
	return (1);
}

int	find_next_close(t_list **a, int chunk_min, int chunk_max)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		i;
	int		j;

	tmp1 = *a;
	i = 0;
	if (!find_forward(tmp1, chunk_min, chunk_max, &i))
		return (-1);
	tmp2 = (*a)->prev;
	j = 1;
	while (tmp2->index < chunk_min || tmp2->index > chunk_max)
	{
		tmp2 = tmp2->prev;
		j++;
		if (tmp2 == (*a)->prev)
			return (-1);
	}
	if (i <= j)
		return (1);
	return (2);
}
