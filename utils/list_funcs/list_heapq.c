#include "cyclic_list.h"
t_list *lst_alloc(int capa)
{
    t_list *newlst;

    newlst = malloc(sizeof(t_list));
    if (!newlst)
        return NULL;

    newlst->size = 0;
    newlst->head = 0;
    newlst->capacity = capa;

    newlst->data = ft_calloc(capa, sizeof(int));
    if (!newlst->data)
    {
        free(newlst);
        return NULL;
    }

    return newlst;
}
void lst_clear(t_list *lst)
{
    if (!lst)
        return;
    free(lst->data);
    free(lst);
    lst = NULL;
}

// int	lstalloc(t_list *list, int size, int capacity)
// {
// 	list->head = 0;
// 	list->size = size;
// 	list->capacity = capacity;
// 	list->data = ft_calloc(sizeof(int), capacity);
// 	if (list->data == NULL)
// 		return (ALLOCATE_FAILURE);
// 	return (SUCCESS);
// }

// void    lstfree(t_list *list)
// {
//     free(list->data);
//     list->data = NULL;
//     list->head = 0;
//     list->size = 0;
//     list->capacity = 0;
// }
