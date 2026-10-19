/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:18:59 by alexfuen          #+#    #+#             */
/*   Updated: 2025/12/15 18:19:01 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_chunk_size(int total_length)
{
	if (total_length <= 100)
		return (10);
	else if (total_length <= 200)
		return (20);
	else if (total_length <= 500)
		return (25);
	else
		return (40);
}

int	lst_max_index(t_list *lst)
{
	int		max;
	t_list	*start;

	if (!lst)
		return (-1);
	max = lst->index;
	start = lst;
	lst = lst->next;
	while (lst && lst != start)
	{
		if (lst->index > max)
			max = lst->index;
		lst = lst->next;
	}
	return (max);
}

int	lst_position_index(t_list *lst, int index)
{
	int		pos;
	t_list	*start;

	if (!lst)
		return (-1);
	pos = 0;
	start = lst;
	while (1)
	{
		if (lst->index == index)
			return (pos);
		lst = lst->next;
		pos++;
		if (lst == start)
			break ;
	}
	return (-1);
}

int	lst_has_chunk(t_list *lst, int chunk_min, int chunk_max)
{
	t_list	*start;

	if (!lst)
		return (0);
	start = lst;
	if (lst->index >= chunk_min && lst->index <= chunk_max)
		return (1);
	lst = lst->next;
	while (lst != start)
	{
		if (lst->index >= chunk_min && lst->index <= chunk_max)
			return (1);
		lst = lst->next;
	}
	return (0);
}
