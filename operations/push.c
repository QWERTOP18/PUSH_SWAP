/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:56:15 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/09 19:40:40 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cyclic_list.h"

int	push(t_list *list_from, t_list *list_to)
{
	int	push_val;

	if (list_from->size < 1)
	{
		return (1);
	}
	push_val = list_from->data[list_from->head];
	lstremove(list_from);
	lstinsert(list_to, push_val);
	return (0);
}

int	pa(t_list *list_a, t_list *list_b)
{
	if (push(list_a, list_b))
	{
		return (1);
	}
	ft_printf("pa\n");
	return (0);
}

int	pb(t_list *list_a, t_list *list_b)
{
	if (push(list_b, list_a))
	{
		return (1);
	}
	ft_printf("pb\n");
	return (0);
}

#ifdef TEST_PUSH

// gcc -g *.c -I../includes -DTEST_PUSH -o a.out
//  gdb ./a.out
//(gdb) run

int	main(int argc, char const *argv[])
{
	t_list	list_a;
	t_list	list_b;

	lstalloc(&list_a, 3, 3);
	lstalloc(&list_b, 0, 3);
	list_a.data[0] = 1;
	list_a.data[1] = 2;
	list_a.data[2] = 3;
	list_b.size = 1;
	for (int i = 0; i < list_a.size; i++)
	{
		printf("%d ", list_a.data[(list_a.head + i) % list_a.size]);
	}
	printf("\n");
	pb(&list_a, &list_b);
	for (int i = 0; i < list_a.size; i++)
	{
		printf("%d ", list_a.data[(list_a.head + i) % list_a.size]);
	}
	printf("\n");
	pb(&list_a, &list_b);
	for (int i = 0; i < list_a.size; i++)
	{
		printf("%d ", list_a.data[(list_a.head + i) % list_a.size]);
	}
	printf("\n");
	for (int i = 0; i < list_b.size; i++)
	{
		printf("%d ", list_b.data[(list_b.head + i) % list_b.size]);
	}
	printf("done\n");
	free(list_a.data);
	free(list_b.data);
	return (0);
}
#endif