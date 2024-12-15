/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:56:35 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/15 12:17:03 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "cyclic_list.h"
# include "error.h"
# include <limits.h>

typedef struct s_cnt
{
	int	a;
	int	b;
	int	r;
	int	total;
}		t_cnt;

/***** ***** ***** MAIN ****** ***** ****/
void	ft_exit(int status, t_clst *list_a, t_clst *list_b);
t_clst	*format_input(int argc, char **argv);
void	calculate(t_clst *list_a, t_clst *list_b, t_cnt *ret_cnt);
void	optimize_cnt(t_cnt *cnt);
int		find_insert_idx(const t_clst *list_a, const t_clst *list_b, int idx_a);

/***** ***** ***** BUILD ****** ***** ****/
void	handle_pusha(t_clst *list_a, t_clst *list_b);
void	handle_pushb(t_clst *list_a, t_clst *list_b);
void	handle_rotation(t_clst *list_a, t_clst *list_b, t_cnt *cnt);

/***** ***** ***** BUILD UTILS ****** ***** ****/
void	calculate(t_clst *list_a, t_clst *list_b, t_cnt *ret_cnt);
int		check_sorted(t_clst *list, int head);
int		select_direction(int idx, int list_size);
void	alignby_rotate(t_clst *list);

#endif