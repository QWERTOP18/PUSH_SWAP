/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:11:02 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/12 15:36:13 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cyclic_list.h"

void	lstinsert(t_list *list, int element)
{
	int	pos;

	pos = list->size;
	while (pos > list->head)
	{
		list->data[pos] = list->data[pos - 1];
		pos--;
	}
	list->data[list->head] = element;
	list->size++;
}

void	lstremove(t_list *list)
{
	int	pos;

	pos = list->head;
	while (pos + 1 < list->size)
	{
		list->data[pos] = list->data[pos + 1];
		pos++;
	}
	list->size--;
}

int	nextid(const t_list *list)
{
	return ((list->head + 1) % list->size);
}

int	previd(const t_list *list)
{
	return ((list->head + list->size - 1) % list->size);
}
