/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:36:55 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/08 19:45:06 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cyclic_list.h"

int	rotate(t_list *list)
{
	if (list->size < 1)
	{
		return (1);
	}
	list->head = (list->head + 1) % list->size;
	return (0);
}

int	ra(t_list *list_a)
{
	if (rotate(list_a))
	{
		return (1);
	}
	ft_printf("ra\n");
	return (0);
}

int	rb(t_list *list_b)
{
	if (rotate(list_b))
	{
		return (1);
	}
	ft_printf("rb\n");
	return (0);
}
int	rr(t_list *list_a, t_list *list_b)
{
	if (ra(list_a) || rb(list_b))
	{
		return (1);
	}
	ft_printf("rr\n");
	return (0);
}

#ifdef TEST_ROTATE

int	main(int argc, char const *argv[])
{
	t_list	list;

	list.head = 0;
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
	ra(&list);
	for (int i = 0; i < list.size; i++)
	{
		printf("%d ", list.data[(list.head + i) % list.size]);
	}
	printf("\n");
	free(list.data);
	return (0);
}

#endif