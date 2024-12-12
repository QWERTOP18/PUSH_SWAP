/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:20:56 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/02 09:32:29 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned(unsigned int nbr)
{
	static char	buf[MXLEN + 1];
	int			index;

	index = MXLEN;
	if (nbr == 0)
		buf[--index] = '0';
	while (nbr != 0)
	{
		buf[--index] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (print_str(buf + index));
}
