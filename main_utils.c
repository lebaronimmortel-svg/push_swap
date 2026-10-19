/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 08:08:56 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/19 16:34:50 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	next_arg(int *i, int *j)
{
	(*i)++;
	(*j) = 0;
}

static int	check_mult(char **argv, int *i, int *j)
{
	int				c;
	long long int	d;

	if (!((argv[*i][*j] >= '0' && argv[*i][*j] <= '9')))
	{
		if (!(argv[*i][*j] == '-' || argv[*i][*j] == '+'))
			return (0);
		else
		{
			if (!((argv[*i][*j + 1] >= '0' && argv[*i][*j + 1] <= '9')))
				return (0);
		}
	}
	d = my_atol(&argv[*i][*j], j);
	c = d;
	if (c != d)
		return (0);
	return (1);
}

static int	is_valid_mult(char **argv, int argc)
{
	int	i;
	int	j;
	int	result;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			while (argv[i][j] == ' ')
				j++;
			result = check_mult(argv, &i, &j);
			if (result == 0)
				return (0);
			while (argv[i][j] == ' ')
				j++;
			if (argv[i][j] == '\0' && i < argc - 1)
				next_arg(&i, &j);
		}
		i++;
	}
	return (2);
}

static int	is_valid_single(char **argv)
{
	int				i;
	int				c;
	long long int	d;

	i = 0;
	while (argv[1][i])
	{
		while (argv[1][i] == ' ')
			i++;
		if (argv[1][i] == '\0')
			break ;
		if (!((argv[1][i] >= '0' && argv[1][i] <= '9')))
		{
			if (!(argv[1][i] == '-' || argv[1][i] == '+'))
				return (0);
		}
		d = my_atol(&argv[1][i], &i);
		c = d;
		if (c != d)
			return (0);
		if (argv[1][i] != ' ' && argv[1][i] != '\0')
			return (0);
	}
	return (1);
}

int	is_valid_input(int argc, char **argv)
{
	int	x;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		x = is_valid_single(argv);
		return (x);
	}
	else
	{
		x = is_valid_mult(argv, argc);
		return (x);
	}
}
