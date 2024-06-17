/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshimiz <aoshimiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:00:00 by aoshimiz          #+#    #+#             */
/*   Updated: 2024/06/17 19:27:28 by aoshimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(char *str, int *array, int size)
{
	int	tmp;

	if (size <= 0)
		return ;
	tmp = array[0];
	array[0] = array[1];
	array[1] = tmp;
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

void	push_a(t_stacks *s)
{
	int	tmp;

	if (s->b_size <= 0)
		return ;
	tmp = s->b[0];
	ft_memmove(s->a + 1, s->a, sizeof(int) * s->a_size);
	s->a[0] = tmp;
	s->b_size--;
	ft_memmove(s->b, s->b + 1, sizeof(int) * s->b_size);
	s->a_size++;
	write(1, "pa\n", 3);
}

void	push_b(t_stacks *s)
{
	int	tmp;

	if (s->a_size <= 0)
		return ;
	tmp = s->a[0];
	ft_memmove(s->b + 1, s->b, sizeof(int) * s->b_size);
	s->b[0] = tmp;
	s->a_size--;
	ft_memmove(s->a, s->a + 1, sizeof(int) * s->a_size);
	s->b_size++;
	write(1, "pb\n", 3);
}

void	rotate_up(int *array, int size, char *list)
{
	int	tmp;

	if (size < 0)
		return ;
	tmp = array[0];
	ft_memmove(array, array + 1, sizeof(int) * (size - 1));
	array[size - 1] = tmp;
	write(1, "r", 1);
	write(1, list, ft_strlen(list));
	write(1, "\n", 1);
}

void	rotate_down(int *array, int size, char *list)
{
	int	tmp;

	if (size < 0)
		return ;
	tmp = array[size - 1];
	ft_memmove(array + 1, array, sizeof(int) * (size - 1));
	array[0] = tmp;
	write(1, "rr", 2);
	write(1, list, ft_strlen(list));
	write(1, "\n", 1);
}
