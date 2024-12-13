#include "push_swap.h"
#include "error.h"
# include "ft_math.h"
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
				return (E_DUPLICATE_VALUE);
			id2++;
		}
		id1++;
	}
	return (E_NONE);
}

t_err store_as_array(t_list *list_a,char **args)
{
    int next_num;

    while(*args)
    {
        next_num = bijective_atoi(*args);
        if(next_num==0 && *args!='0')
        {
            lst_free(list_a);
            return E_INVALID_INPUT;
        }
        list_a->data[list_a->size++] = next_num; 
    }
    return E_NONE;
}

t_list *format_input(int argc, char **argv)
{
    char **args;
    t_list *list_a;
    if (argc==2)
    {
        args = ft_split(argv[1],' ');
        if (args==NULL)
            ft_exit(E_ALLOCATE);
        list_a = lst_alloc(ft_count_words(argv[1],' '));
        if (list_a==NULL)
            ft_exit(E_ALLOCATE);
        if(store_as_array(list_a,args))
            ft_exit(E_INVALID_INPUT);
        split_free(args);
    }
    else if(argc>2)
    {
        list_a = lst_alloc(argc-1);
        list_a = store_as_array(list_a,&argv[1]);
    }
	if (check_duplicate(list_a))
		ft_exit(E_DUPLICATE_VALUE);
    return list_a;
}



// t_err format(int argc, char **argv,int *size, char ***array)
// {
// 	int ptr;
// 	if (argc <2)
// 		return (E_INVALID_INPUT);
// 	else if (argc == 2)
// 	{
// 		*size = ft_count_words(argv[1]);
// 		*array = ft_split(argv[1],' ');
// 		if (!*array)
// 		    return (E_ALLOCATE);
// 		return (E_NONE);
// 	}
// 	*size = argc - 1;
// 	*array = malloc(sizeof(char *) * (*size + 1));
// 	if (!*array)
// 		return (E_ALLOCATE);
// 	ptr = 1;
// 	while (ptr < argc)
// 	{
// 		(*array)[ptr] = ft_strdup(argv[ptr]);
// 		if (!(*array)[ptr])
// 			return (E_ALLOCATE);
// 		ptr++;
// 	}
// 	return (E_NONE);
// }