/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshimiz <aoshimiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:07:37 by aoshimiz          #+#    #+#             */
/*   Updated: 2024/05/16 16:47:18 by aoshimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_pow(double base, int exp)
{
	double	result;

	result = 1.0;
	while (exp > 0)
	{
		result *= base;
		exp--;
	}
	while (exp < 0)
	{
		result /= base;
		exp++;
	}
	return (result);
}

static double	parse_exponent(const char **str)
{
	int	exponent_sign;
	int	exponent;

	exponent_sign = 1;
	exponent = 0;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			exponent_sign = -1;
		(*str)++;
	}
	while (ft_isdigit(**str))
	{
		exponent = exponent * 10 + (**str - '0');
		(*str)++;
	}
	return (ft_pow(10, exponent_sign * exponent));
}

static double	parse_fraction(const char **str)
{
	double	fraction;
	double	result;

	fraction = 1.0;
	result = 0.0;
	while (ft_isdigit(**str))
	{
		fraction /= 10.0;
		result += (**str - '0') * fraction;
		(*str)++;
	}
	return (result);
}

static double	parse_integer(const char **str)
{
	double	result;

	result = 0.0;
	while (ft_isdigit(**str))
	{
		result = result * 10.0 + (**str - '0');
		(*str)++;
	}
	return (result);
}

double	ft_atof(const char *str)
{
	double	result;
	double	sign;

	result = 0.0;
	sign = 1.0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1.0;
		str++;
	}
	result = parse_integer(&str);
	if (*str == '.')
	{
		str++;
		result += parse_fraction(&str);
	}
	if (*str == 'e' || *str == 'E')
	{
		str++;
		result *= parse_exponent(&str);
	}
	return (sign * result);
}
