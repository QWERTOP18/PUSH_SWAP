/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:34:12 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/14 22:44:51 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_strtol(const char *str)
{
	long long	result;
	long		sign;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		result = result * 10 + (*str - '0');
		if (result > LONG_MAX && sign == 1)
			return (LONG_MAX);
		else if (result > LONG_MAX && sign == -1)
			return (LONG_MIN);
		str++;
	}
	return ((long)sign * result);
}

int	ft_atoi(const char *str)
{
	if (!str)
		return (0);
	return ((int)ft_strtol(str));
}
