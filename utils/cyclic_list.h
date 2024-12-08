/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyclic_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:58:55 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/08 18:06:26 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CYCLIC_LIST_H
# define CYCLIC_LIST_H

# include <stddef.h>

typedef struct s_list
{
    int *data;
    int head;
    int size;
    
}                    t_list;

#endif