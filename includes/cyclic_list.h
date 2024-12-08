/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyclic_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:58:55 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/08 20:50:41 by ymizukam         ###   ########.fr       */
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
# define ALLOCATE_ERROR 1
# define INVALID_INPUT 2

// typedef struct s_node
// {
// 	int				val;
// 	int				init_val;
// 	struct s_node	*next;
// 	struct s_node	*prev;
// }					t_node;

typedef struct s_list
{
	int	*data;
	int	head;
	int	size;

}		t_list;

int		nextid(const t_list *list);
int		previd(const t_list *list);
void	lstmove_forward(t_list *list);
void	lstmove_backward(t_list *list);

#endif
