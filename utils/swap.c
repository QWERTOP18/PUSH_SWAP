/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:44:10 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/08 19:26:34 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cyclic_list.h"

int	swap(t_list *list)
{
	int	id1;
	int	id2;
	int	temp;

	if (list->size < 2)
	{
		return (1);
	}
	id1 = list->head;
	id2 = (list->head + 1) % list->size;
	temp = list->data[id1];
	list->data[id1] = list->data[id2];
	list->data[id2] = temp;
	return (0);
}
#ifdef TEST_SWAP
# include <stdio.h>

int	main(int argc, char const *argv[])
{
	t_list	list;

	list.head = 1;
	list.size = 3;
	list.data = malloc(sizeof(int) * list.size);
	list.data[0] = 1;
	list.data[1] = 2;
	list.data[2] = 3;
	for (int i = 0; i < list.size; i++)
	{
		printf("%d ", list.data[(list.head + i) % list.size]);
	}
	printf("\n");
	swap(&list);
	for (int i = 0; i < list.size; i++)
	{
		printf("%d ", list.data[(list.head + i) % list.size]);
	}
	free(list.data);
	return (0);
}

#endif