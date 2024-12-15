/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a1_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:06:45 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/15 13:14:54 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "push_swap.h"

// printf("exit with %d\n", status);
void	ft_exit(int status, t_clst *list_a, t_clst *list_b)
{
	clst_clear(list_a);
	clst_clear(list_b);
	if (status == E_NONE)
		exit(0);
	write(2, "Error\n", 6);
	exit(status);
}

t_err	build(t_clst *list_a, t_clst *list_b)
{
	if (check_sorted(list_a, list_a->head))
		return (E_NONE);
	handle_pushb(list_a, list_b);
	handle_pusha(list_a, list_b);
	alignby_rotate(list_a);
	if (check_sorted(list_a, list_a->head))
		return (E_NONE);
	else
		return (E_SORT);
}

int	main(int argc, char **argv)
{
	t_clst	*list_a;
	t_clst	*list_b;

	if (argc == 1)
		return (0);
	list_a = format_input(argc, argv);
	if (!list_a)
		ft_exit(E_ALLOCATE, NULL, NULL);
	list_b = clst_new(list_a->capacity);
	if (!list_b)
		ft_exit(E_ALLOCATE, list_a, NULL);
	if (build(list_a, list_b))
		ft_exit(E_OPERATION, list_a, list_b);
	ft_exit(E_NONE, list_a, list_b);
}
