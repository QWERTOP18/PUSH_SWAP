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

int    main(int argc, char **argv)
{
    t_list list_a; 
    t_list list_b;
    int input_size;
    char **input_array;
    setup(&list_a,&list_b,&input_array);
    if\
    (\
    format(argc,argv,&input_size, &input_array) || \
    extract(&list_a,&list_b,input_size, input_array) || \
    build(&list_a, &list_b) \
    )
        ft_printf("Error\n");
    cleanup(&list_a, &list_b, input_array);
    return (0);
}
