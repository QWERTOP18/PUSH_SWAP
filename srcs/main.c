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
	t_list list_a; 
	t_list list_b;

	int lstsize = argc - 1;
	list_a.data = NULL;
	list_b.data = NULL;
	if\
	(\
	lstalloc(&list_a, lstsize, lstsize) || \
	lstalloc(&list_b, 0, lstsize) || \
	parse_input(&list_a, argc, argv) || \
	build(&list_a, &list_b)\
	)
		ft_printf("Error\n");
		

	lstfree(&list_a);
	lstfree(&list_b);
	return (0);
}