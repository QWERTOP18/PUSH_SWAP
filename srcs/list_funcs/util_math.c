
#include <limits.h>
int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int bijective_atoi(const char *str)
{
	long long	result;
	int		sign;

	sign = 1;
	result = 0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		result = result * 10 + (*str - '0');
		if (result > INT_MAX)
			return (0);
		str++;
	}
	if(*str)
	    return (0);
	return (sign * result);
}