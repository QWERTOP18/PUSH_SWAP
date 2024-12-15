/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_heapq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:39:14 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/15 12:33:44 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cyclic_list.h"

t_clst	*clst_new(int capa)
{
	t_clst	*newlst;

	newlst = malloc(sizeof(t_clst));
	if (!newlst)
		return (NULL);
	newlst->size = 0;
	newlst->head = 0;
	newlst->capacity = capa;
	newlst->data = ft_calloc(capa, sizeof(int));
	if (!newlst->data)
	{
		free(newlst);
		return (NULL);
	}
	return (newlst);
}

void	clst_clear(t_clst *lst)
{
	if (lst == NULL)
		return ;
	free(lst->data);
	free(lst);
	lst = NULL;
}

// int	lstalloc(t_clst *list, int size, int capacity)
// {
// 	list->head = 0;
// 	list->size = size;
// 	list->capacity = capacity;
// 	list->data = ft_calloc(sizeof(int), capacity);
// 	if (list->data == NULL)
// 		return (ALLOCATE_FAILURE);
// 	return (SUCCESS);
// }

// void    lstfree(t_clst *list)
// {
//     free(list->data);
//     list->data = NULL;
//     list->head = 0;
//     list->size = 0;
//     list->capacity = 0;
// }
