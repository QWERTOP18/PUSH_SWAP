/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:22:58 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/02 09:07:41 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(const int c, t_error *__errorno__)
{
	int	ret;

	ret = write(1, &c, 1);
	if (ret == -1)
		*__errorno__ = E_WRITE;
	return (ret);
}
