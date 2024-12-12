/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:21:28 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/02 09:32:58 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned int nbr, const char *base)
{
	static char	buf[MXLEN + 1];
	int			index;

	index = MXLEN;
	if (nbr == 0)
		buf[--index] = '0';
	while (nbr != 0)
	{
		buf[--index] = base[nbr % 16];
		nbr /= 16;
	}
	return (print_str(buf + index));
}
