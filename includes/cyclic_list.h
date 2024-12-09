/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyclic_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:58:55 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/09 19:35:51 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYCLIC_LIST_H
# define CYCLIC_LIST_H

# define ft_printf printf //あとで消す
# define ft_calloc calloc

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

# define SUCCESS 0
# define ALLOCATE_FAILURE 1
# define INVALID_INPUT 2

typedef struct s_list
{
	int	*data;
	int	head;
	int	size;
	int	capacity;

}		t_list;

/***** ***** ***** UTILS ****** ***** ****/
int		nextid(const t_list *list);
int		previd(const t_list *list);
int		lstalloc(t_list *list, int size, int capacity);
void    lstfree(t_list *list);
void	lstinsert(t_list *list, int element);
void	lstremove(t_list *list);

/***** ***** ***** OPERATIONS ****** ***** ****/
int	sa(t_list *list_a);
int	sb(t_list *list_b);
int	ss(t_list *list_a, t_list *list_b);
int    pa(t_list *list_a, t_list *list_b);
int    pb(t_list *list_a, t_list *list_b);
int    ra(t_list *list_a);
int    rb(t_list *list_b);
int    rr(t_list *list_a,t_list *list_b);
int    rra(t_list *list_a);
int    rrb(t_list *list_b);
int    rrr(t_list *list_a,t_list *list_b);
#endif
