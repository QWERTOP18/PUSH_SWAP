/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:11:02 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/12 15:27:55 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cyclic_list.h"

#ifdef DEBUG
void	printlst(t_list *list)
{
	int	i;

	ft_printf("--->list<---\n");
	i = 0;
	while (i < list->size)
	{
		ft_printf("%d ", list->data[(list->head + i) % list->size]);
		i++;
	}
	ft_printf("\n");
}
#endif

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
