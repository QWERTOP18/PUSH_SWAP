/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:11:02 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/08 20:59:05 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cyclic_list.h"

int	lstalloc(t_list *list, int size)
{
	list->head = 0;
	list->size = size;
	list->data = ft_calloc(sizeof(int), list->size);
	if (list->data == NULL)
		return (ALLOCATE_ERROR);
	return (SUCCESS);
}

int	nextid(const t_list *list)
{
	return ((list->head + 1) % list->size);
}

int	previd(const t_list *list)
{
	return ((list->head + list->size - 1) % list->size);
}

void	lstmove_forward(t_list *list)
{
	int	tmp_head;

	tmp_head = list->head + 1;
	while (tmp_head < list->size)
	{
		list->data[tmp_head] = list->data[tmp_head - 1];
		tmp_head++;
	}
	list->head = nextid(list);
	list->size--;
}

void	lstmove_backward(t_list *list)
{
	int	tmp_head;

	tmp_head = list->size - 1;
	while (tmp_head >= 0)
	{
		list->data[tmp_head] = list->data[tmp_head + 1];
		tmp_head--;
	}
	list->head = previd(list);
	list->size++;
}
