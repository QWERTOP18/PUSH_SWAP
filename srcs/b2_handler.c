/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b2_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:01:52 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/12 15:28:25 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_err	handle_rotation(t_list *list_a, t_list *list_b, t_cnt *cnt)
{
	t_err	err;

	printf("handle_rotation a%d\tb%d\tr%d\n", cnt->a, cnt->b, cnt->r);
	if (cnt->r > 0)
		while (cnt->r-- > 0)
			err = rr(list_a, list_b);
	else
		while (cnt->r++ < 0)
			err = rrr(list_a, list_b);
	if (cnt->a > 0)
		while (cnt->a-- > 0)
			err = ra(list_a);
	else
		while (cnt->a++ < 0)
			err = rra(list_a);
	if (cnt->b > 0)
		while (cnt->b-- > 0)
			err = rb(list_b);
	else
		while (cnt->b++ < 0)
			err = rrb(list_b);
	cnt->a = 0;
	cnt->b = 0;
	cnt->r = 0;
	return (err);
}

void	handle_pushb(t_list *list_a, t_list *list_b)
{
	// 3個残してpb
	//余裕あればLISの計算
	while (list_a->size > 3)
	{
		pb(list_a, list_b);
	}
	// swap
	// find__insert_idxと同じだから関数かできそう
	if (check_sorted(list_a, list_a->head) || check_sorted(list_a,
			previd(list_a)) || check_sorted(list_a, nextid(list_a)))
		return ;
	sa(list_a);
}

void	handle_pusha(t_list *list_a, t_list *list_b)
{
	t_cnt	count;

	while (list_b->size)
	{
		calculate(list_a, list_b, &count);
		// count = calculate(list_a, list_b);
		handle_rotation(list_a, list_b, &count);
		pa(list_a, list_b);
	}
}
#ifdef TEST_HANDLER
# define DEBUG

int	main(int argc, char const *argv[])
{
	t_list	list_a;
	t_list	list_b;
	t_cnt	cnt;
	int		size;

	size = 5;
	cnt.a = 0;
	cnt.b = 0;
	cnt.r = 2;
	size = 10;
	lstalloc(&list_a, size, size);
	lstalloc(&list_b, 0, size);
	for (size_t i = 0; i < size; i++)
	{
		list_a.data[i] = i + 1;
	}
	for (size_t i = 0; i < size / 2; i++)
	{
		pb(&list_a, &list_b);
	}
	printlst(&list_a);
	printlst(&list_b);
	handle_rotation(&list_a, &list_b, &cnt);
	printlst(&list_a);
	printlst(&list_b);
	cnt.a = 4;
	cnt.b = 0;
	cnt.r = 0;
	handle_rotation(&list_a, &list_b, &cnt);
	printlst(&list_a);
	printlst(&list_b);
	lstfree(&list_a);
	lstfree(&list_b);
	return (0);
}
#endif

#ifdef TEST_PUSHB
# define DEBUG
// cc ../utils/list_funcs/*.c  b*.c -DTEST_PUSHB -I../includes
int	main(int argc, char const *argv[])
{
	t_list	list_a;
	t_list	list_b;
	int		size;

	size = 3;
	lstalloc(&list_a, size, size);
	lstalloc(&list_b, 0, size);
	for (size_t i = 0; i < size; i++)
	{
		list_a.data[i] = (i + 7) % 4;
	}
	sa(&list_a);
	printlst(&list_a);
	printlst(&list_b);
	handle_pushb(&list_a, &list_b);
	printlst(&list_a);
	printlst(&list_b);
	lstfree(&list_a);
	lstfree(&list_b);
	return (0);
}
#endif

#ifdef TEST_PUSHA
# define DEBUG
// cc ../utils/list_funcs/*.c  b*.c -DTEST_PUSHA -I../includes
int	main(int argc, char const *argv[])
{
	t_list	list_a;
	t_list	list_b;
	int		size;

	size = 6;
	lstalloc(&list_a, size, size);
	lstalloc(&list_b, 0, size);
	for (size_t i = 0; i < size; i++)
	{
		list_a.data[i] = i + 1; //(size - i + 1);
	}
	printlst(&list_a);
	printlst(&list_b);
	handle_pushb(&list_a, &list_b);
	printlst(&list_a);
	printlst(&list_b);
	handle_pusha(&list_a, &list_b);
	printlst(&list_a);
	printlst(&list_b);
	lstfree(&list_a);
	lstfree(&list_b);
	return (0);
}
#endif