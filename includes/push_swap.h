/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:56:35 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/12 15:04:32 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
# include "cyclic_list.h"
# include "error.h"
# include <limits.h>
typedef struct s_cnt
{
	int	a;
	int	b;
	int	r;
}		t_cnt;

/***** ***** ***** MAIN ****** ***** ****/
t_err	format(int argc, char **argv, int *size, char ***array);
t_err	extract(t_list *list_a, t_list *list_b, int size, char **array);
t_err	build(t_list *list_a, t_list *list_b);
void	calculate(t_list *list_a, t_list *list_b, t_cnt *ret_cnt);
int		optimize_cnt(t_cnt *cnt);
int		find_insert_idx(t_list *list_a, t_list *list_b, int idx_a);

/***** ***** ***** BUILD ****** ***** ****/

void	handle_pusha(t_list *list_a, t_list *list_b);
void	handle_pushb(t_list *list_a, t_list *list_b);
t_err	handle_rotation(t_list *list_a, t_list *list_b, t_cnt *cnt);

/***** ***** ***** BUILD UTILS ****** ***** ****/
int		check_sorted(t_list *list, int head);
int		select_direction(int idx, int list_size);

t_err	alignby_rotate(t_list *list);

#endif