/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 05:56:05 by alexfuen          #+#    #+#             */
/*   Updated: 2025/12/16 05:56:07 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	alloc_pointers(t_list ***a, t_list ***b)
{
	*a = malloc(sizeof(t_list *));
	*b = malloc(sizeof(t_list *));
}

static void	initialize(t_list **a, t_list **b)
{
	*a = NULL;
	*b = NULL;
}

static void	error_free(t_list **a, t_list **b)
{
	t_list	*tmp;

	while (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		free(tmp);
	}
	free(a);
	free(b);
	write(2, "Error\n", 6);
}

static void	free_pointers(t_list **a, t_list **b)
{
	free(a);
	free(b);
}

int	main(int argc, char **argv)
{
	t_list	**stack[2];

	if (argc == 1)
		return (-1);
	alloc_pointers(&stack[0], &stack[1]);
	if (!stack[0] || !stack[1] || is_valid_input(argc, argv) < 1)
	{
		free_pointers(stack[0], stack[1]);
		write(2, "Error\n", 6);
		return (-1);
	}
	initialize(stack[0], stack[1]);
	create_lst(argc, argv, stack[0], stack[1]);
	if (!(*stack[0]))
	{
		free_pointers(stack[0], stack[1]);
		return (-1);
	}
	if (is_valid_list(stack[0]) < 0)
	{
		error_free(stack[0], stack[1]);
		return (-1);
	}
	sort_and_free(stack[0], stack[1]);
	return (1);
}
