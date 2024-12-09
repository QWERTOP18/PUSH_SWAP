#include "cyclic_list.h"
int	check_next_input(const char *next_input)
{
	return (0);
}

int	check_duplicate(const t_list *list)
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
				return (1);
			id2++;
		}
		id1++;
	}
	return (0);
}

int	parse_input(t_list *list, int argc, char **argv)
{
	int	input_head;
	int	next_number;

	input_head = 1;
	while (input_head < list->size)
	{
		if (check_next_input(argv[input_head]))
			return (INVALID_INPUT);
		list->data[list->head] = atoi(argv[input_head++]);
	}
	if (check_duplicate(list))
		return (INVALID_INPUT);
}