/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:18:58 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/02 08:21:55 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(int nbr)
{
	static char	buf[MXLEN + 1];
	int			sign;
	int			index;

	sign = (nbr >= 0) * PLUS + MINUS;
	index = MXLEN;
	if (nbr == 0)
		buf[--index] = '0';
	while (nbr != 0)
	{
		buf[--index] = (nbr % 10) * sign + '0';
		nbr /= 10;
	}
	if (sign == MINUS)
	{
		buf[--index] = '-';
	}
	return (print_str(buf + index));
}
