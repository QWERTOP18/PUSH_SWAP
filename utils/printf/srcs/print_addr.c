/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_addr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:20:37 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/02 08:26:27 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_addr(void *ptr, const char *base)
{
	static char		buf[MXLEN + 1];
	int				index;
	unsigned long	nbr;

	index = MXLEN;
	if (ptr == NULL)
		return (print_str("(nil)"));
	nbr = (unsigned long)ptr;
	while (nbr != 0)
	{
		buf[--index] = base[nbr % 16];
		nbr /= 16;
	}
	buf[--index] = 'x';
	buf[--index] = '0';
	return (print_str(buf + index));
}
