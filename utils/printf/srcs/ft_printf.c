/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:09:34 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/02 09:34:40 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_funcs(t_fptr *funcs)
{
	funcs['c'] = process_char;
	funcs['s'] = process_str;
	funcs['p'] = process_addr;
	funcs['d'] = process_nbr;
	funcs['i'] = process_nbr;
	funcs['u'] = process_unsigned;
	funcs['x'] = process_hex_lower;
	funcs['X'] = process_hex_upper;
	funcs['%'] = process_percent;
}

int	process_ap(const char type, va_list ap, t_error *__errorno__)
{
	int				ret;
	static t_fptr	funcs[256];

	ret = 0;
	init_funcs(funcs);
	if (funcs[(unsigned char)type])
	{
		ret = funcs[(unsigned char)type](ap, __errorno__);
	}
	else
	{
		*__errorno__ = E_FORMAT;
		return (-1);
	}
	return (ret);
}

int	ft_printf(const char *fmt, ...)
{
	va_list			ap;
	int				len;
	static t_error	__errno__;

	if (!fmt)
		return (0);
	len = 0;
	va_start(ap, fmt);
	while (!__errno__ && *fmt)
	{
		if (*fmt != '%')
			len += print_char(*fmt++, &__errno__);
		else if (*fmt++ == '%')
			len += process_ap(*fmt++, ap, &__errno__);
	}
	va_end(ap);
	if (__errno__)
		return (-1);
	return (len);
}

// #ifdef TEST
// # define ft_printf printf
// #endif

// int	main(void)
// {
// 	ft_printf("%x", 9223372036854775807LL);
// 	printf("printf: %d \n", ft_printf("%s %x  %X  %d\nsample \n", "hello\t",
// 			-16, 16, 6789));
// 	return (0);
// }