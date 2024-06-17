/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshimiz <aoshimiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:00:00 by aoshimiz          #+#    #+#             */
/*   Updated: 2024/06/17 19:49:46 by aoshimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_if_sorted_or_has_duplicate(t_stacks *s, int i)
{
	int	j;

	j = 0;
	if (i == 0)
	{
		while (i < s->a_size)
		{
			j = i + 1;
			while (j < s->a_size)
			{
				if (s->a[i] == s->a[j])
					exit_failure(s);
				j++;
			}
			i++;
		}
	}
	if (is_array_sorted(s))
		exit_success(s);
}

void	parse_numbers(t_stacks *s)
{
	char	**tmp;
	int		i;
	int		z;

	z = 0;
	tmp = ft_split(s->join_args, ' ');
	i = 0;
	while (tmp[i] != NULL && tmp[i][0] != '\0')
	{
		s->a[z++] = ft_atol(tmp[i++], s);
		free(tmp[i - 1]);
	}
	free(tmp);
}

void	create_index(t_stacks *s)
{
	int	i;
	int	j;
	int	k;
	int	*new_a;

	new_a = malloc(s->a_size * sizeof(*new_a));
	if (new_a == NULL)
		exit_failure(s);
	i = -1;
	while (++i < s->a_size)
	{
		k = 0;
		j = -1;
		while (++j < s->a_size)
			if (s->a[i] > s->a[j])
				k++;
		new_a[i] = k;
	}
	i = s->a_size;
	while (i--)
		s->a[i] = new_a[i];
	free(new_a);
}

long	parse_long(const char *n, int *index, t_stacks *s)
{
	long	res;
	int		i;

	res = 0;
	i = *index;
	while (n[i])
	{
		if (n[i] < '0' || n[i] > '9')
			exit_failure(s);
		if (res > LONG_MAX / 10 || (res == LONG_MAX / 10 && n[i]
				- '0' > LONG_MAX % 10))
			exit_failure(s);
		res = res * 10 + (n[i] - '0');
		i++;
	}
	*index = i;
	return (res);
}

int	ft_atol(const char *n, t_stacks *s)
{
	long	sign;
	long	result;
	int		i;

	i = 0;
	sign = 1;
	while (n[i] == ' ' || (n[i] >= '\t' && n[i] <= '\r'))
		i++;
	if (n[i] == '+' || n[i] == '-')
	{
		if (n[i] == '-')
			sign = -1;
		i++;
	}
	result = parse_long(n, &i, s) * sign;
	if ((sign == 1 && result > INT_MAX) || (sign == -1 && result < INT_MIN))
		exit_failure(s);
	return ((int)result);
}
