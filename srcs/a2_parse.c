/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a2_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:43:48 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/14 22:43:49 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "ft_math.h"
#include "push_swap.h"

t_err	check_duplicate(const t_clst *list)
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
				return (E_DUPLICATE_VALUE);
			id2++;
		}
		id1++;
	}
	return (E_NONE);
}

t_err	store_as_array(t_clst *list_a, char **args)
{
	int	next_num;

	while (*args)
	{
		next_num = bijective_atoi(*args);
		if (next_num == 0 && ft_strncmp(*args, "0", ft_strlen(*args)))
		{
			clst_clear(list_a);
			return (E_INVALID_INPUT);
		}
		list_a->data[list_a->size++] = next_num;
		args++;
	}
	return (E_NONE);
}

t_clst	*format_input(int argc, char **argv)
{
	char	**args;
	t_clst	*list_a;

	list_a = NULL;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (args == NULL)
			ft_exit(E_ALLOCATE);
		list_a = clst_new(ft_count_words(argv[1], ' '));
		if (list_a == NULL)
			ft_exit(E_ALLOCATE);
		if (store_as_array(list_a, args))
			ft_exit(E_INVALID_INPUT);
		split_free(args);
	}
	else if (argc > 2)
	{
		list_a = clst_new(argc - 1);
		if (store_as_array(list_a, &argv[1]))
			ft_exit(E_INVALID_INPUT);
	}
	else
	{
		ft_exit(E_NONE);
	}
	if (check_duplicate(list_a))
		ft_exit(E_DUPLICATE_VALUE);
	return (list_a);
}

// int main()
// {
//     t_clst *list_a;
//     list_a = format_input(2, (char *[]){"1 2 3",NULL});
//     // a1_main.c
//     if(!list_a)
//        ft_exit(E_ALLOCATE);
//     if(build(list_a, NULL))
//         ft_exit(E_OPERATION);
//     clst_clear(list_a);
//     return (E_NONE);
//     //ft_exit(E_NONE);
// }