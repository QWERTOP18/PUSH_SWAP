/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:36:55 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/15 12:16:25 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cyclic_list.h"

int	rotate(t_clst *list)
{
	if (list->size < 1)
	{
		return (1);
	}
	list->head = nextid(list);
	return (0);
}

int	ra(t_clst *list_a)
{
	if (rotate(list_a))
	{
		return (1);
	}
	write(1, "ra\n", 3);
	return (0);
}

int	rb(t_clst *list_b)
{
	if (rotate(list_b))
	{
		return (1);
	}
	write(1, "rb\n", 3);
	return (0);
}

int	rr(t_clst *list_a, t_clst *list_b)
{
	if (rotate(list_a) || rotate(list_b))
	{
		return (1);
	}
	write(1, "rr\n", 3);
	return (0);
}

// #ifdef TEST_ROTATE
// int	main(int argc, char const *argv[])
// {
// 	t_clst	list;

// 	list.head = 0;
// 	list.size = 3;
// 	list.data = malloc(sizeof(int) * list.size);
// 	list.data[0] = 1;
// 	list.data[1] = 2;
// 	list.data[2] = 3;
// 	for (int i = 0; i < list.size; i++)
// 	{
// 		printf("%d ", list.data[(list.head + i) % list.size]);
// 	}
// 	printf("\n");
// 	ra(&list);
// 	for (int i = 0; i < list.size; i++)
// 	{
// 		printf("%d ", list.data[(list.head + i) % list.size]);
// 	}
// 	printf("\n");
// 	free(list.data);
// 	return (0);
// }
// #endif