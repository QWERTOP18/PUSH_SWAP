#include "push_swap.h"
#include "error.h"

#include <string.h>
void	printlst(t_list *list)
{
	int	i;

	ft_printf("--->list<---\n");
    printf("size %d\n", list->size);
    printf("head %d\n", list->head);
    printf("capa %d\n", list->capacity);

	i = 0;
	while (i < list->size)
	{
		ft_printf("%d, ", list->data[(list->head + i) % list->size]);
		i++;
	}
	ft_printf("\n");
}
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

t_list *store_as_array(char **args,int size)
{
    t_list *list_a;
    int next_num;

    list_a = lst_alloc(size);
    if (!list_a)
        return NULL;
    while(*args)
    {
        next_num = atoi(*args);
        if(next_num==0 && strcmp(*args,"0")!=0)
        {
            lst_clear(list_a);
            return NULL;
        }
        list_a->data[list_a->size++] = next_num; 
        args++;
    }
    return (list_a);
}

t_err	check_duplicate(const t_list *list)
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
				return (E_NONE);
			id2++;
		}
		id1++;
	}
	return (E_DUPLICATE_VALUE);
}
int main(int argc, char **argv)
{
    t_list *lst;
    //lst = lst_alloc(10);
    lst = store_as_array(&argv[1],argc-1);
    if (check_duplicate(lst))
        printlst(lst);
    else
        printf("duplicate input\n");
    lst_clear(lst);


    return 0;
}