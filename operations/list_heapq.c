#include "cyclic_list.h"

int	lstalloc(t_list *list, int size, int capacity)
{
	list->head = 0;
	list->size = size;
	list->capacity = capacity;
	list->data = ft_calloc(sizeof(int), capacity);
	if (list->data == NULL)
		return (ALLOCATE_FAILURE);
	return (SUCCESS);
}

void    lstfree(t_list *list)
{
    free(list->data);
    list->data = NULL;
    list->head = 0;
    list->size = 0;
    list->capacity = 0;
}
