/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshimiz <aoshimiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:00:00 by aoshimiz          #+#    #+#             */
/*   Updated: 2024/06/06 20:28:31 by aoshimiz         ###   ########.fr       */
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
	ft_putendl_fd(str, 1);
}

// void	push(char *str, t_stacks *s)
// {
// 	int	tmp;

// 	if (ft_strncmp(str, "pa", 3) == 0)
// 	{
// 		if (s->b_size <= 0)
// 			return ;
// 		tmp = s->b[0];
// 		ft_memmove(s->a + 1, s->a, sizeof(int) * s->a_size);
// 		s->a[0] = tmp;
// 		s->b_size--;
// 		ft_memmove(s->b, s->b + 1, sizeof(int) * s->b_size);
// 		s->a_size++;
// 	}
// 	else if (ft_strncmp(str, "pb", 3) == 0)
// 	{
// 		if (s->a_size <= 0)
// 			return ;
// 		tmp = s->a[0];
// 		ft_memmove(s->b + 1, s->b, sizeof(int) * s->b_size);
// 		s->b[0] = tmp;
// 		s->a_size--;
// 		ft_memmove(s->a, s->a + 1, sizeof(int) * s->a_size);
// 		s->b_size++;
// 	}
// 	ft_putendl_fd(str, 1);
// }

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
	ft_putendl_fd("pa", 1);
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
	ft_putendl_fd("pb", 1);
}

// void	rotate(int *array, int size, char *direction, char *list)
// {
// 	int	tmp;

// 	if (size < 0)
// 		return ;
// 	if (ft_strncmp(direction, "up", 5) == 0)
// 	{
// 		tmp = array[0];
// 		ft_memmove(array, array + 1, sizeof(int) * (size - 1));
// 		array[size - 1] = tmp;
// 		write(1, "r", 1);
// 	}
// 	else if (ft_strncmp(direction, "down", 5) == 0)
// 	{
// 		tmp = array[size - 1];
// 		ft_memmove(array + 1, array, sizeof(int) * (size - 1));
// 		array[0] = tmp;
// 		write(1, "rr", 2);
// 	}
// 	ft_putendl_fd(list, 1);
// }

void	rotate_up(int *array, int size, char *list)
{
	int	tmp;

	if (size < 0)
		return ;
		tmp = array[0];
		ft_memmove(array, array + 1, sizeof(int) * (size - 1));
		array[size - 1] = tmp;
		write(1, "r", 1);
	ft_putendl_fd(list, 1);
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
	ft_putendl_fd(list, 1);
}