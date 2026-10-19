/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 08:12:20 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/19 16:26:10 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	convert_mult(t_list **a, t_list **b, char **argv)
{
	int	i;
	int	j;
	int	c;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			while (argv[i][j] == ' ')
				j++;
			if (argv[i][j] == '\0')
				break ;
			c = my_atol(&argv[i][j], &j);
			new_tail(a, b, c);
		}
		i++;
		j = 0;
	}
}

static void	convert_single(t_list **a, t_list **b, char **argv)
{
	int	i;
	int	c;

	i = 0;
	while (argv[1][i])
	{
		while (argv[1][i] == ' ')
			i++;
		if (argv[1][i] == '\0')
			break ;
		c = my_atol(&argv[1][i], &i);
		new_tail(a, b, c);
	}
}

void	create_lst(int argc, char **argv, t_list **a, t_list **b)
{
	if (argc == 2)
		convert_single(a, b, argv);
	else
		convert_mult(a, b, argv);
}
