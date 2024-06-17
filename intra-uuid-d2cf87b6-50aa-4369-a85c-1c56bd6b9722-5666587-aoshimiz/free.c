/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshimiz <aoshimiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:00:00 by aoshimiz          #+#    #+#             */
/*   Updated: 2024/06/17 19:15:02 by aoshimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_resources(t_stacks *s)
{
	if (!s)
		return ;
	free(s->a);
	free(s->b);
	free(s->join_args);
	free(s);
}

void	exit_success(t_stacks *s)
{
	free_resources(s);
	exit(0);
}

void	exit_failure(t_stacks *s)
{
	write(2, "Error\n", 6);
	free_resources(s);
	exit(1);
}
