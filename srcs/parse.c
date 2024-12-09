#include "cyclic_list.h"
#include "error.h"

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

t_err    extract(t_list *list_a,t_list *list_b, int size, char **array)
{
	if (lstalloc(list_a, size,size) || lstalloc(list_b, 0,size))
	    return (E_ALLOCATE);
	int ptr;
	ptr = 0;
	while (ptr < size)
	{
		//atoiでオーバーフローしたら０を返すようにする
		if (ft_atoi(array[ptr]) == 0 && ft_strcmp(array[ptr], "0")!= 0)
            return (E_INVALID_INPUT);
        list_a->data[ptr] = ft_atoi(array[ptr]);
        ptr++;
	}
	return (check_duplicate);
}

t_err format(int argc, char **argv,int *size, char ***array)
{
	int ptr;
	if (argc <2)
		return (E_INVALID_INPUT);
	else if (argc == 2)
	{
		*size = ft_count_words(argv[1]);
		*array = ft_split(argv[1],' ');
		if (!*array)
		    return (E_ALLOCATE);
		return (E_NONE);
	}
	*size = argc - 1;
	*array = malloc(sizeof(char *) * (*size + 1));
	if (!*array)
		return (E_ALLOCATE);
	ptr = 1;
	while (ptr < argc)
	{
		(*array)[ptr] = ft_strdup(argv[ptr]);
		if (!(*array)[ptr])
			return (E_ALLOCATE);
		ptr++;
	}
	return (E_NONE);
}