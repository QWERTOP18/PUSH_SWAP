/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:17:00 by ymizukam          #+#    #+#             */
/*   Updated: 2024/10/31 20:54:38 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **list, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (!list || !del)
		return ;
	current = *list;
	while (current)
	{
		next = current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*list = NULL;
}
