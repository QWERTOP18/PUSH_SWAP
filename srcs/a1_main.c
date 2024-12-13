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

#include "push_swap.h"
#include "error.h"

void setup(t_list *list_a,t_list *list_b,char ***input_array)
{
    list_a->data = NULL;
    list_b->data = NULL;
    *input_array = NULL;
}

void cleanup(t_list *list_a,t_list *list_b,char **input_array)
{
    lstfree(list_a);
    lstfree(list_b);
    if (input_array)
        free_split(input_array);
}



/*
stringの入力をintの配列に直す

*/

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
        next_num = ft_atoi(*args);
        if(next_num==0 && *args!='0')
        {
            lst_free(list_a);
            return NULL;
        }
        list_a->data[list_a->size++] = next_num; 
    }
    return (list_a);
}


int main(int argc,char **argv) {
    t_list *list_a;
    t_list *list_b;
    char **args;
    if (argc==2)
    {
        args = ft_split(argv[1],' ');
        list_a = store_as_array(args,ft_count_words(argv[1]));
        split_free(args);
    }
    else if(argc>2)
    {
        list_a = store_as_array(&argv[1],argc-1);
    }
        
    list_b = lst_alloc(list_a->capacity);

    return 0;
}


// #ifndef DEBUG
// int    main(int argc, char **argv)
// {
//     t_list list_a; 
//     t_list list_b;
//     int input_size;
//     char **input_array;
//     setup(&list_a,&list_b,&input_array);
//     if\
//     (\
//     format(argc,argv,&input_size, &input_array) || \
//     extract(&list_a,&list_b,input_size, input_array) || \
//     build(&list_a, &list_b) \
//     )
//         ft_printf("Error\n");
//     cleanup(&list_a, &list_b, input_array);
//     return (0);
// }
// #endif
