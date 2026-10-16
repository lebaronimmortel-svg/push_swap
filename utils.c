/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:22:43 by alexfuen          #+#    #+#             */
/*   Updated: 2025/12/15 19:22:47 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	disconnect(t_list *tmp)
{
	tmp->prev->next = NULL;
	tmp->prev = NULL;
}

void	apply_index(t_list **lst)
{
	int		i;
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst || !(*lst))
		return ;
	tmp = *lst;
	if (tmp->prev)
		disconnect(tmp);
	while (tmp)
	{
		i = 0;
		tmp2 = *lst;
		while (tmp2)
		{
			if (tmp2->data < tmp->data)
				i++;
			tmp2 = tmp2->next;
		}
		tmp->index = i;
		tmp = tmp->next;
	}
	if (lst_length(lst) >= 3 && !(*lst)->prev)
		link_lst(lst);
}

void	sort_and_free(t_list **a, t_list **b)
{
	if (!(is_sort_lst(*a)))
	{
		link_lst(a);
		apply_index(a);
		sort(a, b);
	}
	free_lst(a);
	free_lst(b);
	free(a);
	free(b);
}

long long int	my_atol(char *nptr, int *index)
{
	int				sign;
	int				i;
	long long int	result;

	i = 0;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
		(*index)++;
	}
	result = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - 48;
		i++;
		(*index)++;
	}
	return (sign * result);
}
