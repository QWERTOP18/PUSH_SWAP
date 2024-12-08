/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyclic_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:58:55 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/08 20:01:11 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYCLIC_LIST_H
# define CYCLIC_LIST_H

# define ft_printf printf //あとで消す
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

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

#endif