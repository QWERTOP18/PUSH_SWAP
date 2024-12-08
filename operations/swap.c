/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:44:10 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/08 20:57:06 by ymizukam         ###   ########.fr       */
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
	id2 = nextid(list);
	temp = list->data[id1];
	list->data[id1] = list->data[id2];
	list->data[id2] = temp;
	return (0);
}

int	sa(t_list *list_a)
{
	if (swap(list_a))
	{
		return (1);
	}
	ft_printf("sa\n");
	return (0);
}

int	sb(t_list *list_b)
{
	if (swap(list_b))
	{
		return (1);
	}
	ft_printf("sb\n");
	return (0);
}

int	ss(t_list *list_a, t_list *list_b)
{
	if (sa(list_a) || sb(list_b))
	{
		return (1);
	}
	ft_printf("ss\n");
	return (0);
}

#ifdef TEST_SWAP

// cc *.c -I../includes -DTEST_SWAP

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
	sa(&list);
	for (int i = 0; i < list.size; i++)
	{
		printf("%d ", list.data[(list.head + i) % list.size]);
	}
	free(list.data);
	return (0);
}

#endif