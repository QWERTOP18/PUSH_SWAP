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
	if (push(list_b, list_a))
	{
		return (1);
	}
	ft_printf("pa\n");
	return (0);
}

int	pb(t_list *list_a, t_list *list_b)
{
	if (push(list_a, list_b))
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
void test_push_operations()
{
    t_list list_a;
    t_list list_b;

    // リストを初期化
    lstalloc(&list_a, 3, 5); // 容量5, 初期サイズ3
    lstalloc(&list_b, 0, 5); // 容量5, 初期サイズ0

    // 初期データを設定
    list_a.data[0] = 1;
    list_a.data[1] = 2;
    list_a.data[2] = 3;

    // 初期状態の出力
    printf("Initial List A: ");
    for (int i = 0; i < list_a.size; i++)
        printf("%d ", list_a.data[(list_a.head + i) % list_a.capacity]);
    printf("\n");

    printf("Initial List B: ");
    for (int i = 0; i < list_b.size; i++)
        printf("%d ", list_b.data[(list_b.head + i) % list_b.capacity]);
    printf("\n");

    // テスト: pb (List A → List B)
    printf("\nPerforming pb...\n");
    pb(&list_a, &list_b);
	pb(&list_a, &list_b);	
	pb(&list_a, &list_b);	
    // 状態を確認
    printf("List A after pb: ");
    for (int i = 0; i < list_a.size; i++)
        printf("%d ", list_a.data[(list_a.head + i) % list_a.capacity]);
    printf("\n");

    printf("List B after pb: ");
    for (int i = 0; i < list_b.size; i++)
        printf("%d ", list_b.data[(list_b.head + i) % list_b.capacity]);
    printf("\n");

    // テスト: pa (List B → List A)
    printf("\nPerforming pa...\n");
    pa(&list_a, &list_b);

    // 状態を確認
    printf("List A after pa: ");
    for (int i = 0; i < list_a.size; i++)
        printf("%d ", list_a.data[(list_a.head + i) % list_a.capacity]);
    printf("\n");

    printf("List B after pa: ");
    for (int i = 0; i < list_b.size; i++)
        printf("%d ", list_b.data[(list_b.head + i) % list_b.capacity]);
    printf("\n");

    // メモリ解放
    free(list_a.data);
    free(list_b.data);
}

int main(void)
{
    test_push_operations();
    return 0;
}

#endif