/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:11:02 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/09 19:38:41 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cyclic_list.h"

void	lstinsert(t_list *list, int element)
{
	int	insert_pos;
	int	shift_pos;
	int	prev_pos;
	int	index;

	// 挿入位置のインデックスを調整（headからの相対的な位置）
	insert_pos = list->head;
	index = list->capacity - insert_pos;
	for (int i = list->size; i > index; i--)
	{
		shift_pos = (list->head + i) % list->capacity;
		prev_pos = (list->head + i - 1) % list->capacity;
		list->data[shift_pos] = list->data[prev_pos];
	}
	// 挿入
	list->data[insert_pos] = element;
	list->size++;
}

// リストの先頭の要素を削除
void	lstremove(t_list *list)
{
	int	remove_pos;

	if (list->size == 0)
	{
		printf("Error: The list is empty!\n");
		return ;
	}
	remove_pos = list->head;
	// 削除後、要素をシフトして前に移動
	for (int i = remove_pos; i != (list->head + list->size - 1)
		% list->capacity; i = (i + 1) % list->capacity)
	{
		list->data[i] = list->data[(i + 1) % list->capacity];
	}
	// 最後の要素をクリア
	list->size--;
	// headを更新（削除後、次の要素がheadになる）
	list->head = (list->head + 1) % list->capacity;
}

int	nextid(const t_list *list)
{
	return ((list->head + 1) % list->size);
}

int	previd(const t_list *list)
{
	return ((list->head + list->size - 1) % list->size);
}

// void	print_list(t_list *list)
// {
// 	int	index;

// 	printf("List: ");
// 	for (int i = 0; i < list->size; i++)
// 	{
// 		index = (list->head + i) % list->capacity;
// 		printf("%d ", list->data[index]);
// 	}
// 	printf("\n");
// }

// int	main(void)
// {
// 	t_list	list;

// 	// リストの初期化 (容量5、サイズ0)
// 	if (lstalloc(&list, 0, 5) == ALLOCATE_ERROR)
// 	{
// 		printf("Memory allocation failed\n");
// 		return (1);
// 	}
// 	// 要素を挿入
// 	printf("Inserting 10\n");
// 	lstinsert(&list, 10);
// 	print_list(&list);
// 	printf("lstinserting 20\n");
// 	lstinsert(&list, 20);
// 	print_list(&list);
// 	printf("lstinserting 30\n");
// 	lstinsert(&list, 30);
// 	print_list(&list);
// 	printf("lstinserting 40\n");
// 	lstinsert(&list, 40);
// 	print_list(&list);
// 	printf("lstinserting 50\n");
// 	lstinsert(&list, 50);
// 	print_list(&list);
// 	// 要素を削除
// 	printf("Removing an element\n");
// 	lstremove(&list);
// 	print_list(&list);
// 	printf("Removing an element\n");
// 	lstremove(&list);
// 	print_list(&list);
// 	printf("Removing an element\n");
// 	lstremove(&list);
// 	print_list(&list);
// 	printf("Removing an element\n");
// 	lstremove(&list);
// 	print_list(&list);
// 	printf("Removing an element\n");
// 	lstremove(&list);
// 	print_list(&list);
// 	// リストが空の状態で削除しようとする
// 	printf("Attempting to lstremove from empty list\n");
// 	lstremove(&list);
// 	print_list(&list);
// 	// メモリ解放
// 	free(list.data);
// 	return (0);
// }
