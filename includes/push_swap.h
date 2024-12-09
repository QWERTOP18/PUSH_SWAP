/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:56:35 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/08 19:57:31 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
#include "cyclic_list.h"

typedef struct s_cnt
{
    int    a;
    int    b;
    int    r;
} t_cnt;

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