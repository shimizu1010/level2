/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshimiz <aoshimiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:00:00 by aoshimiz          #+#    #+#             */
/*   Updated: 2024/06/06 20:27:25 by aoshimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	sort_three_elements(t_stacks *s)
{
	if (s->a[2] != 2)
	{
		if (s->a[0] == 2)
			rotate_up(s->a, s->a_size, "a");
		else
			rotate_down(s->a, s->a_size, "a");
	}
	if (s->a[0] > s->a[1])
		swap("sa", s->a, s->a_size);
}

void	sort_four_to_five_elements(t_stacks *s)
{
	while (s->b_size <= 1)
	{
		if (s->a[0] == 0 || s->a[0] == 1)
			push_b(s);
		else
			rotate_up(s->a, s->a_size, "a");
	}
	if (s->b[0] == 0)
		swap("sb", s->b, s->b_size);
	if (s->a[2] != 4)
	{
		if (s->a[0] == 4)
			rotate_up(s->a, s->a_size, "a");
		else
			rotate_down(s->a, s->a_size, "a");
	}
	if (s->a[0] > s->a[1])
		swap("sa", s->a, s->a_size);
	push_a(s);
	push_a(s);
}

int	is_array_sorted(t_stacks *s)
{
	int	i;

	i = 0;
	while (i < s->a_size - 1)
	{
		if (s->a[i] > s->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	radix_sort_stack_b(t_stacks *s, int b_size, int bit_size, int j)
{
	while (b_size-- && j <= bit_size && !is_array_sorted(s))
	{
		if (((s->b[0] >> j) & 1) == 0)
			rotate_up(s->b, s->b_size, "b");
		else
			push_a(s);
	}
	if (is_array_sorted(s))
		while (s->b_size != 0)
			push_a(s);
}

void	radix_sort(t_stacks *s)
{
	int	j;
	int	bit_size;
	int	size;

	bit_size = 0;
	size = s->a_size;
	while (size > 1 && ++bit_size)
		size /= 2;
	j = -1;
	while (++j <= bit_size)
	{
		size = s->a_size;
		while (size-- && !is_array_sorted(s))
		{
			if (((s->a[0] >> j) & 1) == 0)
				push_b(s);
			else
				rotate_up(s->a, s->a_size, "a");
		}
		radix_sort_stack_b(s, s->b_size, bit_size, j + 1);
	}
	while (s->b_size != 0)
		push_a(s);
}
