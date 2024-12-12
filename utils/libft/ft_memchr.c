/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:59:15 by ymizukam          #+#    #+#             */
/*   Updated: 2024/10/29 20:59:54 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;

	if (!s)
		return (NULL);
	str = (unsigned char *)s;
	ch = (unsigned char)c;
	while (n--)
	{
		if (*str == ch)
			return (str);
		str++;
	}
	return (NULL);
}
