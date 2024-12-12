/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:23:21 by ymizukam          #+#    #+#             */
/*   Updated: 2024/10/31 13:46:51 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	if (!*little)
		return ((char *)big);
	little_len = ft_strlen(little);
	i = 0;
	while (*(big + i) && i + little_len <= len)
	{
		if (ft_strncmp(big + i, little, little_len) == 0)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

#ifdef DEBUG

int	main(void)
{
	const char	*largestring = "Foo Bar Baz";
	const char	*smallstring = "Bar";
	char		*ptr1;

	ptr1 = ft_strnstr(largestring, smallstring, 10);
	ft_putendl_fd(ptr1, 1);
	return (0);
}
// ccw -L. -D DEBUG ft_strnstr.c -lft
#endif