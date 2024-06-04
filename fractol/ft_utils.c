/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshimiz <aoshimiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:07:37 by aoshimiz          #+#    #+#             */
/*   Updated: 2024/06/03 20:12:49 by aoshimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	process_decimal(const char *str, double result)
{
	double	divisor;

	divisor = 10.0;
	while (*str >= '0' && *str <= '9')
	{
		result += (*str - '0') / divisor;
		divisor *= 10.0;
		str++;
	}
	return (result);
}

const char	*parse_sign(const char *str, double *sign)
{
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign = -1.0;
		else
			*sign = 1.0;
		str++;
	}
	return (str);
}

double	ft_atof(const char *str)
{
	double	result;
	double	sign;

	if (!str || *str == '\0')
		exit(1);
	result = 0.0;
	sign = 1.0;
	while (*str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		str = parse_sign(str, &sign);
	if (*str < '0' || *str > '9')
		exit(1);
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		result = process_decimal(str, result);
	}
	return (result * sign);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	result;

	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	result = (*(const unsigned char *)s1 - *(const unsigned char *)s2);
	return (result);
}
