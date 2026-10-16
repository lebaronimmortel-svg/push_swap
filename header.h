/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 05:49:07 by alexfuen          #+#    #+#             */
/*   Updated: 2025/12/16 05:49:08 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;

}	t_list;

/////// PARSING ////////

int				is_valid_list(t_list **a);
long long int	my_atol(char *nptr, int *index);
int				is_valid_input(int argc, char **argv);

/////// OPERATIONS ////////

void			sa(t_list **a);
void			sb(t_list **b);
void			ra(t_list **a);
void			rb(t_list **b);
void			rra(t_list **a);
void			rrb(t_list **b);
void			ss(t_list **a, t_list **b);
void			pa(t_list **a, t_list **b);
void			pb(t_list **a, t_list **b);
void			rr(t_list **a, t_list **b);
void			rrr(t_list **a, t_list **b);

/////// LISTS TOOLS ////////

int				is_link(t_list **lst);
int				is_sort_lst(t_list *a);
void			free_lst(t_list **lst);
void			link_lst(t_list **lst);
int				lst_length(t_list **lst);
void			new_tail(t_list **a, t_list **b, int data);
void			create_lst(int argc, char **argv, t_list **a, t_list **b);

/////// SORT ////////

void			apply_index(t_list **lst);
int				lst_max_index(t_list *lst);
void			sort(t_list **a, t_list **b);
int				get_chunk_size(int total_length);
void			sort_small(t_list **a, t_list **b);
void			sort_and_free(t_list **a, t_list **b);
int				lst_position_index(t_list *lst, int index);
int				lst_has_chunk(t_list *lst, int chunk_min, int chunk_max);
int				find_next_close(t_list **a, int chunk_min, int chunk_max);

#endif
