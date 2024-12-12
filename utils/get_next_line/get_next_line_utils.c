/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:29:32 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/04 22:38:39 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_err	allocate(t_str *str, t_opt opt, int fd)
{
	if (!str->base)
		str->base = malloc(BUFFER_SIZE + 1);
	if (!str->base)
		return (E_ALLOCATE);
	str->size = BUFFER_SIZE;
	str->index = 0;
	if (opt == O_READ)
	{
		str->size = read(fd, str->base, BUFFER_SIZE);
		if (str->size < 0)
			return (E_READ);
		str->base[str->size] = '\0';
		if (str->size == 0)
			return (END_FILE);
	}
	str->base[str->size] = '\0';
	return (E_NONE);
}

t_err	reallocate(t_str *str)
{
	char	*new_base;
	ssize_t	index;

	index = 0;
	new_base = malloc(str->size * 2 + 1);
	if (!new_base)
	{
		free(str->base);
		str->base = NULL;
		return (E_ALLOCATE);
	}
	while (index < str->index)
	{
		new_base[index] = str->base[index];
		index++;
	}
	str->size *= 2;
	new_base[str->size] = '\0';
	free(str->base);
	str->base = new_base;
	return (E_NONE);
}

void	release(t_str *str)
{
	free(str->base);
	str->base = NULL;
	str->size = 0;
	str->index = 0;
}
