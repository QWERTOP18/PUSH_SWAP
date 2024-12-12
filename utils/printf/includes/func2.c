/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:38:41 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/02 09:33:50 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_nbr(va_list ap, t_error *__errorno__)
{
	int	ret;

	ret = print_nbr(va_arg(ap, int));
	if (ret == -1)
	{
		*__errorno__ = E_WRITE;
	}
	return (ret);
}

int	process_unsigned(va_list ap, t_error *__errorno__)
{
	int	ret;

	ret = print_unsigned(va_arg(ap, unsigned int));
	if (ret == -1)
	{
		*__errorno__ = E_WRITE;
	}
	return (ret);
}

int	process_hex_lower(va_list ap, t_error *__errorno__)
{
	int	ret;

	ret = print_hex(va_arg(ap, unsigned int), "0123456789abcdef");
	if (ret == -1)
	{
		*__errorno__ = E_WRITE;
	}
	return (ret);
}

int	process_hex_upper(va_list ap, t_error *__errorno__)
{
	int	ret;

	ret = print_hex(va_arg(ap, unsigned int), "0123456789ABCDEF");
	if (ret == -1)
	{
		*__errorno__ = E_WRITE;
	}
	return (ret);
}
