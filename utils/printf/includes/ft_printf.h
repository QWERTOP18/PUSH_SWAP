/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:19:45 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/02 09:33:13 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

# define PLUS 2
# define MINUS -1
# define MXLEN 60

typedef enum s_error
{
	E_NONE,
	E_WRITE,
	E_TYPE,
	E_ARG,
	E_FORMAT,
}			t_error;
typedef int	(*t_fptr)(va_list ap, t_error *__errorno__);

int			ft_printf(const char *fmt, ...);
// utils
int			ft_strlen(const char *str);

// funcs
int			process_char(va_list ap, t_error *__errorno__);
int			process_str(va_list ap, t_error *__errorno__);
int			process_addr(va_list ap, t_error *__errorno__);
int			process_nbr(va_list ap, t_error *__errorno__);
int			process_unsigned(va_list ap, t_error *__errorno__);
int			process_hex_lower(va_list ap, t_error *__errorno__);
int			process_hex_upper(va_list ap, t_error *__errorno__);
int			process_percent(va_list ap, t_error *__errorno__);

// print_type
int			print_char(const int c, t_error *__errorno__);
int			print_str(const char *str);
int			print_nbr(int nbr);
int			print_hex(unsigned int nbr, const char *base);
int			print_unsigned(unsigned int longnbr);
int			print_addr(void *ptr, const char *base);

#endif