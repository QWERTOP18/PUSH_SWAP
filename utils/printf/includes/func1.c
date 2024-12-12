/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:37:05 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/02 08:58:11 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_char(va_list ap, t_error *__errorno__)
{
	int	ret;

	ret = print_char(va_arg(ap, int), __errorno__);
	if (ret == -1)
	{
		*__errorno__ = E_WRITE;
	}
	return (ret);
}

int	process_str(va_list ap, t_error *__errorno__)
{
	int	ret;

	ret = print_str(va_arg(ap, char *));
	if (ret == -1)
	{
		*__errorno__ = E_WRITE;
	}
	return (ret);
}

int	process_addr(va_list ap, t_error *__errorno__)
{
	int	ret;

	ret = print_addr(va_arg(ap, void *), "0123456789abcdef");
	if (ret == -1)
	{
		*__errorno__ = E_WRITE;
	}
	return (ret);
}

int	process_percent(va_list ap, t_error *__errorno__)
{
	(void)ap;
	return (print_char('%', __errorno__));
}
