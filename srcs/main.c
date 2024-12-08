/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:06:45 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/08 20:50:44 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cyclic_list.h"
#include <stdio.h>

int	check_next_input(const char *next_input)
{
	return (0);
}

int	check_duplicate(const t_list *list)
{
	int	id1;
	int	id2;

	id1 = 0;
	while (id1 < list->size)
	{
		id2 = id1 + 1;
		while (id2 < list->size)
		{
			if (list->data[id1] == list->data[id2])
				return (1);
			id2++;
		}
		id1++;
	}
	return (0);
}

int	parse_input(t_list *list, int argc, char **argv)
{
	int	input_head;
	int	next_number;

	input_head = 1;
	while (input_head < list->size)
	{
		if (check_next_input(argv[input_head]))
			return (INVALID_INPUT);
		list->data[list->head] = atoi(argv[input_head++]);
	}
	if (check_duplicate(list))
		return (INVALID_INPUT);
}
int	compress_list(t_list *list_origin, t_list *list_a)
{
}

// listutils file
// int	allocate(t_list *list, int size)
// {
// 	list->head = 0;
// 	list->size = size;
// 	list->head = ft_calloc(sizeof(int), list->size);
// 	if (list->head == NULL)
// 		return (ALLOCATE_ERROR);
// }

int	main(int argc, char **argv)
{
	t_list *list_origin;
	t_list *dict;   //最後に数字を復元させるための辞書
	t_list *list_a; //座標圧縮されたあと
	t_list *list_b;

	if (allocate(list_origin, argc - 1))
	{
		printf("error\n");
		return (1);
	}

	if (parse_input(list_origin, argc, argv))
	{
		printf("error\n");
		return (1);
	}
	compress_list(list_origin, list_a);
	int i;

	return (0);
}