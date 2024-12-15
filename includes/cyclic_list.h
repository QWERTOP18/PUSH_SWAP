/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyclic_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:58:55 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/15 12:16:31 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYCLIC_LIST_H
# define CYCLIC_LIST_H

# include "../utils/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define SUCCESS 0
# define ALLOCATE_FAILURE 1
# define INVALID_INPUT 2

typedef struct s_clst
{
	int	*data;
	int	head;
	int	size;
	int	capacity;

}		t_clst;

/***** ***** ***** UTILS ****** ***** ****/
int		nextid(const t_clst *list);
int		previd(const t_clst *list);
int		clst_get(const t_clst *list, const int idx);
t_clst	*clst_new(int capa);
void	clst_clear(t_clst *list);
void	clst_insert(t_clst *list, int element);
void	clst_remove(t_clst *list);

/***** ***** ***** OPERATIONS ****** ***** ****/
int		sa(t_clst *list_a);
int		sb(t_clst *list_b);
int		ss(t_clst *list_a, t_clst *list_b);
int		pa(t_clst *list_a, t_clst *list_b);
int		pb(t_clst *list_a, t_clst *list_b);
int		ra(t_clst *list_a);
int		rb(t_clst *list_b);
int		rr(t_clst *list_a, t_clst *list_b);
int		rra(t_clst *list_a);
int		rrb(t_clst *list_b);
int		rrr(t_clst *list_a, t_clst *list_b);
#endif
